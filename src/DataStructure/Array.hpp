
#include <iostream>
#include "Collection.hpp"

#ifndef ARRAY_HPP
#define ARRAY_HPP

namespace mlib {
	template<typename T>
	class array : public mlib::Collection<T> {
	private:
		T* list;
		index_t size = 0;
		index_t length = 0;
		void resize(index_t add_size);
	public:
		
		array(index_t entr_size);
		array(const array<T> &array2);
		~array();
		void append_back(T value);
		void append_front(T value);
		void append_back(array& array2);
		void remove_back();
		void remove_front();
		void remove(index_t index);
		void insert(index_t index,T value);
		void swap(index_t index,index_t index2);
		void reverse();
		void print();
		void shiftRight();
		void shiftLeft();
		void strip(T value);
		void freedup();
		void purge();
		void push_front(T value);
		void push_back(T value);
		index_t getLength();
		index_t getSize();
		index_t search(T value);
		T get(index_t index);
	 	T pop_front();
	 	T pop_back();
		inline T begin();
		inline T end();
		
		
		
		T operator[](index_t index);
	};
}

#include "Array.tpp"
#endif // ARRAY_HPP

