#include <iostream>
#include <exception>
#include "Collection.hpp"

#ifndef LIST_H
#define LIST_H

#if defined(_LIST_H_INCLUDED)
	#error "List.hpp can not be included directly."
#endif

namespace mlib {
	template<typename T>

	class Node {
	public:
		T value;
		Node<T> *next;
		Node(T value) : value(value) {}
	};
	
	template<typename T>
	class List {
	private:

		Node<T> *head;
		Node<T> *tail;
		index_t length = 0;
		void remove_back();
		void remove_front();
		void append(T value);
		void append_front(T value);
	public:
		List(){
			head = nullptr;
			tail->next = nullptr;
		}

		Node<T>* get(index_t index);
		void set(index_t index,T value);

		void remove(index_t index);
		void insert(index_t index, T value);
		index_t search(T value);
		inline void swap(index_t index,index_t index2);
		void print();
		void push_back(T value);
		void push_front(T value);
		T pop_front();
		T pop_back();
		T operator[](index_t index);
	};
}


template<typename T>
mlib::Node<T>* mlib::List<T>::get(index_t index) {
	if(not(index > length) and not(index < 0)){
		Node<T> *current = head;
		for(index_t i = 0; i < index;++i)
			current = current->next;
		return current;
	} else {
		throw std::runtime_error("Index elements out of range");
	}
}


template<typename T>
T mlib::List<T>::operator[](index_t index){
	Node<T> *current = get(index);
	return current->value;
}


template<typename T>
void mlib::List<T>::set(index_t index,T value){
	if(not(index >= length) and not(index < 0)){
		Node<T>* current;
		for(index_t i = 0; i < index; i++)
			current = current->next;
		current->value = value;
	} else {
		throw std::runtime_error("Index elements out of range");
	}
}


template<typename T>
void mlib::List<T>::append(T value){	
	if(length == 0){
		append_front(value);
		return;
	}
	Node<T> *new_node = new Node<T>(value);
	new_node->next = tail;
	tail = new_node;

	++length;
}


template<typename T>
void mlib::List<T>::append_front(T value){
	Node<T> *new_node = new Node<T>(value);
	new_node->next = head;
	head = new_node;
	++length;
}


template<typename T>
void mlib::List<T>::insert(index_t index,T value){
	if(not(index >= length) and not(index < 0)){
		if(index == 0)
			append_front(value);
		else if(index == length)
			append(value);
		else {
			Node<T> previous_node = head;
			for(index_t i = 0;i < index - 1;++i){
				previous_node = previous_node->next;
			}
			
			Node<T> new_node = new Node<T>(value);
			Node<T> next_node = previous_node->next;

			previous_node->next = new_node;
			new_node->next = next_node;
			++length;
		}
	}
}


template<typename T>
index_t mlib::List<T>::search(T value){
	Node <T>* current = head;
	index_t index = 0;
	while(current == nullptr){
		if(current->value == value)
			return index;
		else 
			current = current->next;
	}
}

template<typename T>
void mlib::List<T>::remove_back(){
	if(not(length == 0)){
		if(length == 1)
			remove_front();
		Node<T> *previous_node = head;
		Node<T> *element_remove = head->next;
		while(element_remove->next != nullptr){
			previous_node = previous_node->next;
			element_remove = element_remove->next;
		}
		previous_node = nullptr;
		tail = previous_node;
		delete element_remove;
		--length;
	}
}

template<typename T>
void mlib::List<T>::remove_front(){
	if(not(length == 0)){
		Node<T> *element_remove = head->next;
		head = element_remove->next;
		delete element_remove;
		--length;
	}
}

template<typename T>
void mlib::List<T>::remove(index_t index){
	if(not(index >= length) and not(index < 0)){
		Node<T> *previous_node = get(index - 1);
		Node<T> *element_remove = previous_node->next;
		Node<T> *next_node = element_remove->next;
		delete element_remove;
		previous_node->next = next_node;
		--length;
	}
}


template<typename T>
void mlib::List<T>::push_front(T value){
	append_front(value);
}

template<typename T>
void mlib::List<T>::push_back(T value){
	append(value);
}

template<typename T>
T mlib::List<T>::pop_back(){
	T value = get(length - 1);
	remove_back();
	return value;
}

template<typename T>
T mlib::List<T>::pop_front(){
	T value = head->value;
	remove_back();
	return value;
}

template<typename T>
void mlib::List<T>::print(){
	Node<T>* current = head;
	std::cout << "[ ";
	while(current != NULL){
		std::cout << current->value << ", ";
		current = current->next;
	}
	std::cout << " ]";
}

#endif // LIST_H
