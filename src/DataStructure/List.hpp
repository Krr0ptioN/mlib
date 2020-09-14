#include <iostream>
#include "Collection.hpp"
#include "Node.hpp"
#pragma once

namespace mlib {
	// Double Linked List Node(DLLNode)
	template <typename T>
	class DLLNode : public mlib::Node<T> {
	public:
		T value;
		DLLNode<T>* next;
		DLLNode<T>* prev;
		DLLNode(T value) : value(value), next(nullptr), prev(nullptr)
		{}
	};

	template <typename T>
	class List : public Collection<T> {
	private:
		index_t length = 0;
		DLLNode<T>* head;
		DLLNode<T>* tail;

		T get(index_t index);
		DLLNode<T>* get_node(index_t index);
	public:
		List();
		~List();
		void append_front(T value);
		void append_back(T value);
		void insert(index_t index, T value);
		void remove_front();
		void remove_back();
		void reverse();
		void swap(index_t index_1,index_t index_2);
		void strip(T value);
		void remove(index_t index);
		void purge();
		void freedup();
		void print();
		void push_back(T value);
		void push_front(T value);
		T pop_front();
		T pop_back();
		bool empty();
		inline T begin();
		inline T end();
		index_t search(T value);
		T operator[](index_t index);
	};
}

#include "List.tpp"

