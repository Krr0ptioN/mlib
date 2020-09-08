
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
	public:
		
		array(index_t entr_size);
		array(const array<T> &array2);

		~array();
		
		index_t length = 0;
		inline index_t getSize();
		inline T get(index_t index);
		void resize(index_t add_size);
		void append(T value);
		void append(array& array2);
		index_t search(T value);
		void remove(index_t index);
		void insert(index_t index,T value);
		inline void swap(index_t index,index_t index2);
		void reverse();
		void print();
		void shiftRight();
		void shiftLeft();
		void strip(T value);
		void freedup();
		inline T begin();
		inline T end();
		inline T pop_front();
		inline T pop_back();
		inline void push_front(T value);
		inline void push_back(T value);
		
		T operator[](index_t index);
	};
}

#include "Array.tpp"
#endif // ARRAY_HPP

