#include <iostream>
#ifndef COLLECTION_HPP
#define COLLECTION_HPP
typedef long int index_t;

namespace mlib {
	template<typename T>
	class Collection {
	public:
		virtual void append_front(T value) = 0;
		virtual void append_back(T value) = 0;
		virtual void remove_back() = 0;
		virtual void remove_front() = 0;
		virtual void remove(index_t index) = 0;
		virtual void insert(index_t index,T value) = 0;
		virtual void reverse() = 0;
		virtual void swap(index_t index_1,index_t index_2) = 0;
		virtual void print()  = 0;
		virtual void strip(T value) = 0;
		virtual void push_front(T value) = 0;
		virtual void push_back(T value) = 0;
		virtual void purge() = 0;
		virtual index_t search(T value) = 0;
		virtual T begin() = 0;
		virtual T end() = 0;
		virtual T pop_front() = 0;
		virtual T pop_back() = 0;
		virtual T operator[](index_t index) = 0;
	};

}

#endif
