
#include <iostream>
#include "CollectionBase.hpp"

#ifndef ARRAY_HPP
#define ARRAY_HPP

namespace mdata {
	template<typename T>
	class array : public mdata::CollectionBase<T> {
	private:
		T* list;
		size_t size = 0;
	public:
		
		array(size_t entr_size);
		array(array &array2);
		~array();
		
		size_t length = 0;
		
		inline T get(size_t index);
		inline void set(size_t index,T value);
		void resize(size_t add_size);
		void append(T value);
		void append(array& array2);
		size_t search(T value);
		void remove(size_t index);
		void insert(size_t index,T value);
		inline void swap(size_t index,size_t index2);
		void reverse();
		void print();
		void shiftRight();
		void shiftLeft();
		T operator[](size_t index);
	};
}

template<typename T>
mdata::array<T>::array(size_t entr_size) {
	size = entr_size;
	list = new T[size];
}

template<typename T>
mdata::array<T>::array(array &array2){
	size = array2.getSize();
	list = new T[size];
	for(size_t i = 0; i < array2.length;i++)
		list[length++] = array2[i];
}

template<typename T>
mdata::array<T>::~array(){
	delete[] list;
}

template<typename T>
inline T mdata::array<T>::get(size_t index){
	if(not(index >= size)){
		return list[index];
	} else {
		throw std::runtime_error("Index elements out of range");
	}
}

template<typename T>
inline void mdata::array<T>::set(size_t index,T value){
	list[index] = value;

}

template<typename T>
T mdata::array<T>::operator[](size_t index){
	return get(index);
}

template<typename T>
void mdata::array<T>::append(T value){
	if (length >= size) {
		resize(1);
		list[length++] = value;
	} else {
		list[length++] = value;
	}
}

template<typename T>
void mdata::array<T>::append(array& array2){
	size_t size2 = array2.getSize();
	int append_size = size - size2;
	append_size = abs(append_size);
	if(append_size != 0)
		resize(append_size);
	for(size_t i = length;i < length+size2;i++){
		list[length++] = array2[i];
	}
}

template<typename T>
void mdata::array<T>::resize(size_t add_size){
	if(add_size == 0)
		return;
	T *tmpList = new T[size + add_size];

	for(size_t i = 0;i <= length;i++)
		tmpList[i] = list[i];

	delete[] list;
	list = tmpList;
}

template<typename T>
void mdata::array<T>::insert(size_t index,T value){
	if(not(index >= size)){
		resize(1);
		for(size_t i = length;i > index;i--)
			list[i] = list[i - 1];
		list[index] = value;
		length++;
	} else {
		if(index < 0)
			throw std::runtime_error("Index elements out of range.");
		for(size_t i = length;i > index;i--)
			list[i] = list[i + 1];
		list[index] = value;
		length++;
	}
}

template<typename T>
size_t mdata::array<T>::search(T value){
	size_t mid = length/2;
	for(size_t i = 0;i < mid;i++){
		if(list[i] == value)
			return i;
		else if(list[length - i] == value)
			return length - i;
	}

	return -1;
}


template<typename T>
void mdata::array<T>::remove(size_t index){
        for(size_t i = index; i < length;i++){
		list[i] = list[i + 1];
	}
	length--;
}

template<typename T>
inline void mdata::array<T>::swap(size_t index,size_t index2){
	T tmp = list[index];
	list[index] = list[index2];
	list[index2] = tmp;
}

template<typename T>
void mdata::array<T>::reverse(){
	size_t mid = (length - 1)/2;
	for(size_t i = 0;i <= mid;i++)
		swap(i,(length - (i+1)));
}


template<typename T>
void mdata::array<T>::print(){
	std::cout << "[ ";
	for(size_t i = 0;i < length;i++)
		std::cout << list[i] << ((i == (length - 1)) ? " ]" : ",");
	std::cout << std::endl;
}

template<typename T>
void mdata::array<T>::shiftRight(){
	T tmp = list[length - 1];
	for(unsigned int i = length;i > 0;i--)
		list[i] = list[i - 1];
	list[0] = tmp;
}

template<typename T>
void mdata::array<T>::shiftLeft(){
	T tmp = list[0];
	for(unsigned int i = 0;i < length - 1;i++)
		list[i] = list[i+1];
	list[length-1] = tmp;
}

#endif // ARRAY_HPP

