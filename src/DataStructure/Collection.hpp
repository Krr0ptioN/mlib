#include <iostream>

#pragma once

typedef long int index_t;

namespace mlib {

	template<typename T>
	class Collection {
	public:
		virtual void remove_back() = 0;
		virtual void remove_front() = 0;
		virtual void remove(index_t index) = 0;
		virtual void insert(index_t index,T value) = 0;
		virtual void reverse() = 0;
		virtual void swap(index_t index_1,index_t index_2) = 0;
		virtual void strip(T value) = 0;
		virtual void purge() = 0;
		virtual index_t search(T value) = 0;
		virtual bool empty() = 0;
		virtual T operator[](index_t index) = 0;
	};

}
