#include <iostream>
#ifndef COLLECTION_HPP
#define COLLECTION_HPP
typedef long int index_t;

namespace mlib {
	template<typename T>

	class Collection {
	public:
		index_t length = 0;
		index_t size = 0;
		inline index_t getSize();
		virtual T get() = 0;
		virtual void resize() = 0;
		virtual void append() = 0;
		virtual void remove() = 0;
		virtual void insert() = 0;
		virtual index_t search() = 0;
		virtual void swap() = 0;
		virtual void reverse() = 0;
		virtual void print()  = 0;
		virtual void strip() = 0;
		virtual T begin() = 0;
		virtual T end() = 0;
		virtual T pop_front() = 0;
		virtual T pop_back() = 0;
		virtual void push_front() = 0;
		virtual void push_back() = 0;

		virtual T operator[](index_t index) = 0;
	};

}

#endif
