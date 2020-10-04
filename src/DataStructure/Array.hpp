
#include <iostream>
#include "Collection.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

#pragma once

namespace mlib {
	template<typename T>
	class Array : public mlib::Collection<T>,
				  public mlib::Queue<T>,
		     	  public mlib::Stack<T> {
	private:
		T* list = nullptr;
		index_t size = 0;
		index_t length = 0;
		void resize(index_t add_size);
		void shift_right(index_t index);
		void shift_left(index_t index);
		T get(index_t index);
		void purge();
	public:
		Array(index_t size_t);
		Array(Array<T> &other);
		Array(Array<T> &&other) noexcept;
		~Array();
		void remove_back();
		void remove_front();
		void append_back(T value);
		void append_front(T value);
		void remove(index_t index);
		void insert(index_t index,T value);
		void swap(index_t index,index_t index2);
		void reverse();
		void rotate_right();
		void rotate_left();
		void strip(T value);
		void freedup();

		inline void push_front(T value);
		inline void push_back(T value);
		void push_back(Array<T>& array2);
		T pop_front();
	 	T pop_back();
		bool empty();
		index_t get_length();
		index_t get_size();
		index_t search(T value);

	 	
		T operator[](index_t index);
		Array<T>& operator=(Array<T>& other);
		Array<T>& operator=(Array<T>&& other) noexcept;
	};
}

// Implementation of methods.
using namespace mlib;

template<typename T>
Array<T>::Array(index_t __size_t) : size(__size_t){
	this->list = new T[this->size];
}

template<typename T>
Array<T>::Array(Array<T> &__other){
	size = __other.get_size();
	list = new T[size];
	for(index_t i = 0; i < __other.length;i++)
		list[length++] = __other[i];
}

// move symmatic
template<typename T>
Array<T>::Array(Array<T> &&__other) noexcept {
	this->list = __other.list;
	this->length = __other.get_length();
	__other.list = nullptr;
	__other.length = 0;
}


template<typename T>
Array<T>::~Array(){
	purge();
	this->size = this->length = 0;
}

template<typename T>
bool Array<T>::empty(){
    return (this->length == 0) ? true : false;
}


template<typename T>
index_t Array<T>::get_size(){
	return this->size;
}

template<typename T>
index_t Array<T>::get_length(){
	return this->length;
}

// if index < 0 return element from end,
// else return list[index].
template<typename T>
inline T Array<T>::get(index_t __index){
	if(not(__index >= length)){
		if(__index < 0) 
			return list[length + (__index - 1)];
		else
			return list[__index];
	} else {
		throw std::out_of_range("Index elements out of range");
	}
}

template<typename T>
T Array<T>::operator[](index_t __index){
	return get(__index);
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>& __other)  {
	delete[] this->list;
	this->list = new T[__other.get_size()];
	this->length = __other.get_length();
	for(index_t i = 0; i < __other.get_length();i++)
		this->list = __other.list[i];
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& __other) noexcept {
	if(this != __other){
		delete[] this->list;
		this->list = __other.list;
		this->length = __other.length();
		__other.length = 0;
		__other.list = nullptr;
	}
	return *this;
}

template<typename T>
void Array<T>::append_back(T __value){
	if (this->length >= this->size)
		resize(0);
	list[length++] = __value;
}

template<typename T>
void Array<T>::push_back(Array<T>& __other){
	index_t size2 = __other.get_size();
	int append_size = size - size2;
	append_size = abs(append_size);
	if(append_size != 0)
		resize(append_size);
	for(index_t i = length;i < length+size2;i++){
		list[length++] = __other[i];
	}
}

template<typename T>
void Array<T>::append_front(T __value){
	if (length >= size)
		resize(0);
	shift_right(1);
	list[0] = __value;
	++length;

}


template<typename T>
void Array<T>::resize(index_t __new_size){
	if(__new_size == 0)
		this->size = this->size * 2;
	else if(__new_size > 0)
		this->size = this->size * __new_size;
	T *tmpList = new T[this->size];
	for(index_t i = 0;i <= length;i++)
		tmpList[i] = list[i];
	delete[] list;
	list = tmpList;
} 

template<typename T>
void Array<T>::insert(index_t index,T value){
	index_t neg_index = length + index;
	if((neg_index >= size) or (index >= size))
		resize(0);
	if(index < 0) {
		for(index_t i = length;i > neg_index;i--)
			list[i] = list[i- 1];
		list[neg_index] = value;
	} else {
		for(index_t i = length;i > index;i--)
			list[i] = list[i - 1];
		list[index] = value;
	}
	length++;
}

template<typename T>
index_t Array<T>::search(T value){
	index_t mid = (length - 1)/2;
	if(list[mid] == value)
		return mid;
	for(index_t i = 0;i < mid;i++){
		if(list[i] == value)
			return i;
		else if(list[length - (i+1)] == value)
			return length - (i+1);
	}

	return -1;
}

template<typename T>
void Array<T>::remove(index_t __index){
    for(;__index < length;__index++)
		list[__index] = list[__index + 1];
	length--;
}

template<typename T>
void Array<T>::remove_back(){
    remove(0);
}

template<typename T>
void Array<T>::remove_front(){
    remove(length - 1);
}

template<typename T>
inline void Array<T>::swap(index_t __index,index_t __index2){
	T tmp = list[__index];
	list[__index] = list[__index2];
	list[__index2] = tmp;
}

template<typename T>
void Array<T>::reverse(){
	index_t mid = (length - 1)/2;
	for(index_t i = 0;i <= mid;i++)
		swap(i,(length - i - 1));
}

template<typename T> 
void Array<T>::shift_right(index_t __index){
	if(not(__index <= 0)){
		if(this->length + __index >= size)
			resize(2);
		for(unsigned long i = length + __index; i > 0;i--)
			list[i] = list[i - 1];
	}
}

template<typename T>
void Array<T>::shift_left(index_t __index){
 	for(;__index < length;__index++)
		list[__index] = list[__index + 1];
}

template<typename T>
void Array<T>::rotate_right(){
	T tmp = get(-1);
	for(unsigned int i = length;i > 0;i--)
		list[i] = list[i - 1];
	list[0] = tmp;
}

template<typename T>
void Array<T>::rotate_left(){
	T tmp = list[0];
	for(unsigned int i = 0;i < length - 1;i++)
		list[i] = list[i+1];
	list[length-1] = tmp;
}

template<typename T>
inline void Array<T>::strip(T value){
	for(index_t i = 0; i < length;i++){
		if(list[i] == value){
			for(index_t j = i;j < length;j++){
				if(list[j] == value)
					remove(j);
			}
		}
	}
}

template<typename T>
inline void Array<T>::freedup(){
	T end_value = this->get(-1);
	for(index_t i = 0;i < length;i++)
		strip(list[i]);
}


template<typename T>
inline T Array<T>::pop_front(){
	T tmp = this->get(0);
	remove_back();
	return tmp;
}


template<typename T>
inline T Array<T>::pop_back(){
	T tmp = this->get(-1);
	remove_front();
	return tmp;
}

template<typename T>
inline void Array<T>::push_front(T value){
	append_front(value);
}

template<typename T>
inline void Array<T>::push_back(T value){
	append_back(value);
}

template<typename T>
void Array<T>::purge(){
	delete[] this->list;
}


