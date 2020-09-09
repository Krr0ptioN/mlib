#include "Collection.hpp"

#ifndef DOUBLE_LIST_HPP
#define DOUBLE_LIST_HPP

namespace mlib{ 

    template<typename T>
    class DoubleNode {
        public:
        T value;
        Node<T>* prev;
        Node<T>* next;
    }

    template<typename T>
    class DoubleList : public Collection<T> {
    private:
    public:
    	void append_front(T value);
		void append(T value);
		void insert(index_t index, T value);
		index_t search(T value);
		void remove_front();
		void remove_back();
		void push_back(T value);
		void push_front(T value);
		T pop_front();
		T pop_back();
		inline T begin();
		inline T end();
		void reverse();
		void strip(T value);
		void remove(index_t index);
		void purge();
		void freedup();
		void print();
		void freeloop();
		T operator[](index_t index);
    };

}