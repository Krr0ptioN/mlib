#include <iostream>
#include "Collection.hpp"


#ifndef LIST_HPP
#define LIST_HPP

namespace mlib {
	template <typename T>
	
	class Node {
	public:
		T value;
		Node<T>* next;
		Node<T>* prev;
		Node(T value) : value(value) {}
	};

	template <typename T>
	class List : public Collection<T> {
	private:
		index_t length = 0;
		Node<T>* head;
		Node<T>* tail;

		T get(index_t index);
		Node<T>* getNode(index_t index);
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
		inline T begin();
		inline T end();
		index_t search(T value);
		T operator[](index_t index);
	};
}
#include "List.tpp"

#endif // LIST_HPP
