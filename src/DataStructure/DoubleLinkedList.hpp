#include <iostream>
#include "Collection.hpp"
#include "Node.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

#pragma once

namespace mlib {
	// Double Linked List
	template <typename T>
	class DLLNode : public mlib::Node<T> {
	public:
		T value;
		DLLNode<T>* next;
		DLLNode<T>* prev;
		DLLNode(T value) : value(value), next(nullptr), prev(nullptr)
		{}
		DLLNode(T value,DLLNode<T>* next,DLLNode<T>* prev)
			: value(value), next(next), prev(prev) {}
	};

	template <typename T>
	class DList :  public mlib::Collection<T>,
				    public mlib::Stack<T>,
					public mlib::Queue<T> {
	private:
		index_t length = 0;
		DLLNode<T>* head = nullptr;
		DLLNode<T>* tail = nullptr;

		T get(index_t index);
		DLLNode<T>* get_node(index_t index);
        void append_front(T value);
		void append_back(T value);
	public:
		DList();
		~DList();
		index_t get_length();
		void insert(index_t index, T value);
		void remove_front();
		void remove_back();
		void reverse();
		void swap(index_t index_1,index_t index_2);
		void strip(T value);
		void remove(index_t index);
		void purge();
		void freedup();
		bool empty();
		// Stack and Queue methods
		void push_back(T value);
		void push_front(T value);
		T pop_front();
		T pop_back();
		index_t search(T value);
		T operator[](index_t index);
	};
}

// Implementation of methods.
using namespace mlib;

template<typename T>
DList<T>::DList(){}

template<typename T>
DList<T>::~DList(){
	purge();
	length = 0;
	head = tail = nullptr;
}

template<typename T>
bool DList<T>::empty(){
    return (this->length == 0) ? true : false;
}


template<typename T>
index_t DList<T>::get_length(){
    return this->length;
}

template<typename T>
T DList<T>::get(index_t index){
	if (not(index > length)){
		if(index == 0)
			return head->value;
		else if(index == length - 1)
			return tail->value;
		else {
			DLLNode<T>* node = head;
			if(index < 0)
				index = length + (index - 1);
			for (int i = 0; i < index; ++i)
				node = node->next;
			return node->value;
		}
	}
	throw std::runtime_error("Out of range index.");
}


template<typename T>
DLLNode<T>* DList<T>::get_node(index_t index){
	if (not(index < 0 or index > length)){
		if(index == 0)
			return head;
		else if(index == length - 1)
			return tail;
		else {
			DLLNode<T>* node = head;
			if(index < 0)
				index = length + (index - 1);
			for (int i = 0; i < index; ++i)
				node = node->next;
			return node;
		}
	}
	return NULL;
}

template <typename T>
void DList<T>::append_front(T __value){
	DLLNode<T>* node = new DLLNode<T>(__value,head,nullptr);
	if(head != nullptr)
		head->prev = node;
	head = node;
	if (tail != nullptr)
		tail = head;
	++length;
}

template <typename T>
void DList<T>::append_back(T __value){
	if (length == 0){
		append_front(__value);
		return;
	} else {
		DLLNode<T>* node = new DLLNode<T>(__value,nullptr,tail);
		if(tail != nullptr)
			tail->next = node;
		tail = node;
		length++;
	}
}

template <typename T>
void DList<T>::insert(index_t index, T value){
	if (not(index > length)){
		if (index == 0)
			append_front(value);
		else if (index == length)
			append_back(value);
		else {
			if(index < 0)
				index = length + (index - 1);
			DLLNode<T>* prevNode = get_node(index - 1);
			DLLNode<T>* nextNode = prevNode->next;
			DLLNode<T>* node = new DLLNode<T>(value,nextNode,prevNode);
			prevNode->next = node;
			nextNode->prev = node;
			length++;
		}
	}
}

template <typename T>
index_t DList<T>::search(T __value){
	if (length != 0){
		int index = 0;
		DLLNode<T>* node = head;
		while (node->value != __value){
			++index;
			node = node->next;
			if (node == nullptr)
				return -1;
		}
		return index;
	}
	return -1;
}

template <typename T>
void DList<T>::remove_front(){
	if (length != 0){
		DLLNode<T>* node = head;
		head = head->next;
		head->prev = nullptr;
		delete node;
		length--;
	}
}

template <typename T>
void DList<T>::remove_back() {
	if (length != 0){
		if (length == 1)
			remove_front();		
		else {	
			DLLNode<T>* prevNode = tail->prev;
			DLLNode<T>* node = tail;
			tail = prevNode;
			tail->next = nullptr;
			delete node;
			--length;
		}
	}
}

template<typename T>
void DList<T>::remove(index_t index){
	if (not(index < 0 or index >= length or length == 0)){
		if (index == 0)
			remove_front();
		else if (index == length - 1)
			remove_back();
		else {
			DLLNode<T>* prevNode = get_node(index - 1);
			DLLNode<T>* node = prevNode->next;
			DLLNode<T>* nextNode = node->next;	
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			delete node;
			--length;
		}
	}
}

template<typename T>
void DList<T>::push_back(T value){
	append_back(value);
}

template<typename T>
void DList<T>::push_front(T value){
	append_front(value);
}

template<typename T>
T DList<T>::pop_front(){
	T tmp = get(0);
	remove_front();
	return tmp;
}

template<typename T>
T DList<T>::pop_back(){
	T tmp = get(-1);
	remove_back();
	return tmp;
}

template<typename T>
void DList<T>::purge(){
	if(length != 0)
		for(index_t i = 0;i < length;i++)
			remove_back();
}

template<typename T>
T DList<T>::operator[](index_t __index){
	return get(__index);
}

template<typename T>
void DList<T>::strip(T __value){
	for(index_t i = 0; i < length;i++){
		if(get(i) == __value){
			for(index_t j = i;j < length;j++){
				if(get(j) == __value)
					remove(j);
			}
		}
	}
}

template<typename T>
void DList<T>::freedup(){
	for(int i = 0;i < length;i++)
		strip(get(i));
}

template<typename T>
void DList<T>::swap(index_t index_1,index_t index_2){
	DLLNode<T>* node1 = get_node(index_1);
	DLLNode<T>* node2 = get_node(index_2);
	T tmp = node1->value;
	node1->value = node2->value;
	node2->value = tmp;
}

template<typename T>
void DList<T>::reverse(){
	index_t mid = (this->length - 1) / 2;
	for(index_t i = 0;i <= mid;i++)
		swap(i,(length - i - 1));
}

