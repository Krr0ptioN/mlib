

#include "Array.hpp"
#pragma once
using namespace mlib;

template<typename T>
Array<T>::Array(index_t _size_t){
	this->size = _size_t;
	this->list = new T[_size_t];
}

template<typename T>
Array<T>::Array(Array<T> &other){
	size = other.get_size();
	list = new T[size];
	for(index_t i = 0; i < other.length;i++)
		list[length++] = other[i];
}


template<typename T>
Array<T>::Array(Array<T> &&other) noexcept {
	this->list = other.list;
	this->length = other.get_length();
	other.list = nullptr;
	other.length = 0;
}


template<typename T>
Array<T>::~Array(){
	purge();
	this->size = this->length = 0;
}

template<typename T>
index_t Array<T>::get_size(){
	return this->size;
}

template<typename T>
index_t Array<T>::get_length(){
	return this->length;
}

template<typename T>
inline T Array<T>::get(index_t index){
	if(not(index >= length)){
		if(index < 0) 
			return list[length + (index - 1)];
		else
			return list[index];
	} else {
		throw std::out_of_range("Index elements out of range");
	}
}

template<typename T>
T Array<T>::operator[](index_t index){
	return get(index);
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>& other)  {
	delete[] this->list;
	this->list = new T[other.get_size()];
	this->length = other.get_length();
	for(index_t i = 0; i < other.get_length();i++)
		this->list = other.list[i];
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
	if(this != other){
		delete[] this->list;
		this->list = other.list;
		this->length = other.length();
		other.length = 0;
		other.list = nullptr;
	}
	return *this;
}

template<typename T>
void Array<T>::append_back(T value){
	if (length >= size)
		resize(1);
	list[length++] = value;
}

template<typename T>
void Array<T>::append_back(Array<T>& other){
	index_t size2 = other.get_size();
	int append_size = size - size2;
	append_size = abs(append_size);
	if(append_size != 0)
		resize(append_size);
	for(index_t i = length;i < length+size2;i++){
		list[length++] = other[i];
	}
}

template<typename T>
void Array<T>::append_front(T value){
	if (length >= size)
		resize(1);
	for(unsigned int i = 0;i < length - 1;i++)
		list[i] = list[i+1];
	list[0] = value;
	++length;

}


template<typename T>
void Array<T>::resize(index_t add_size){
	if(add_size > 0){
		this->size += add_size;
		T *tmpList = new T[this->size];
		for(index_t i = 0;i <= length;i++)
			tmpList[i] = list[i];
		delete[] list;
		list = tmpList;
	}
} 

template<typename T>
void Array<T>::insert(index_t index,T value){
	index_t neg_index = length + index;
	if(neg_index >= size or index >= size)
		resize(length);
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
void Array<T>::remove(index_t index){
    for(;index < length;index++)
		list[index] = list[index + 1];
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
inline void Array<T>::swap(index_t index,index_t index2){
	T tmp = list[index];
	list[index] = list[index2];
	list[index2] = tmp;
}

template<typename T>
void Array<T>::reverse(){
	index_t mid = (length - 1)/2;
	for(index_t i = 0;i <= mid;i++)
		swap(i,(length - i - 1));
}


template<typename T>
void Array<T>::print(){
	std::cout << "[ ";
	for(index_t i = 0;i < length;i++)
		std::cout << list[i]
			  << ((i == (length - 1)) ? " ] " : ",");
}

template<typename T>
void Array<T>::shift_right(){
	T tmp = get(-1);
	for(unsigned int i = length;i > 0;i--)
		list[i] = list[i - 1];
	list[0] = tmp;
}

template<typename T>
void Array<T>::shift_left(){
	T tmp = list[0];
	for(unsigned int i = 0;i < length - 1;i++)
		list[i] = list[i+1];
	list[length-1] = tmp;
}

template<typename T>
T Array<T>::begin(){
	return get(0);
}

template<typename T>
inline T Array<T>::end(){
	return get(-1);
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
	T end_value = end();
	for(index_t i = 0;i < length;i++)
		strip(list[i]);
}


template<typename T>
inline T Array<T>::pop_front(){
	T tmp = begin();
	remove_back();
	return tmp;
}


template<typename T>
inline T Array<T>::pop_back(){
	T tmp = end();
	remove_front();
	return tmp;
}

template<typename T>
inline void Array<T>::push_front(T value){
	insert(0,value);
}

template<typename T>
inline void Array<T>::push_back(T value){
	append_back(value);
}

template<typename T>
void Array<T>::purge(){
	delete[] this->list;
}

template<typename T>
bool Array<T>::empty(){
	return ( length == 0 ) ? true : false;
}