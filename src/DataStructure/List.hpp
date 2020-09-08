#include <iostream>
#include "Collection.hpp"

#if !defined(__LIST_HPP_INCLUDED)
#error "List.hpp can not be included directely"
#endif

#ifndef LIST_HPP
#define LIST_HPP

namespace mlib {
	template <typename T>
	class Node {
	public:
		T value;
		Node<T>* next;
		Node(T value) : value(value) {}
	};

	template <typename T>
	class List {
	private:
		index_t length = 0;
		Node<T>* get(index_t index);
		Node<T>* head;
		Node<T>* tail;
	public:
		List();
		~List();
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
		T begin();
		T end();
		void remove(index_t index);
		void purge();
		void print();
		T operator[](index_t index);
	};
}
#include "List.tpp"

#endif // LIST_HPP
