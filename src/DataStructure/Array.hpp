
#include <iostream>
#include "Collection.hpp"

#pragma once

namespace mlib {
	template<typename T>
	class Array : public mlib::Collection<T> {
	private:
		T* list = nullptr;
		index_t size = 0;
		index_t length = 0;
		void resize(index_t add_size);
	public:
		Array(index_t _size_t);
		Array(Array<T> &other);
		Array(Array<T> &&other) noexcept;
		~Array();
		void append_back(T value);
		void append_front(T value);
		void append_back(Array<T>& array2);
		void remove_back();
		void remove_front();
		void remove(index_t index);
		void insert(index_t index,T value);
		void swap(index_t index,index_t index2);
		void reverse();
		void print();
		void shift_right();
		void shift_left();
		void strip(T value);
		void freedup();
		void purge();
		void push_front(T value);
		void push_back(T value);
		bool empty();
		index_t get_length();
		index_t get_size();
		index_t search(T value);
		T get(index_t index);
	 	T pop_front();
	 	T pop_back();
		inline T begin();
		inline T end();	
		T operator[](index_t index);
		Array<T>& operator=(Array<T>& other);
		Array<T>& operator=(Array<T>&& other) noexcept;
	};
}

#include "Array.tpp"

