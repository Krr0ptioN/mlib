
#include "List.hpp"
#include "Node.hpp"

#pragma once
using namespace mlib;

template<typename T>
List<T>::List(){}

template<typename T>
List<T>::~List(){
	purge();
    length = 0;
	head = tail = nullptr;
}

template<typename T>
T List<T>::get(index_t index){
	if (not(index > length)){
		if(index == 0)
			return head->value;
		else if(index == length - 1)
			return tail->value;
		else {
			DLLNode<T>* node = head;
			if(index < 0)
				index = length + (index - 1);
			for (int i = 0; i <= index; ++i)
				node = node->next;
			return node->value;
		}
	}
	return -1;
}


template<typename T>
DLLNode<T>* List<T>::get_node(index_t index){
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
void List<T>::append_front(T value)
{
	DLLNode<T>* node = new DLLNode<T>(value);
	node->next = head;
	if(head != nullptr)
		head->prev = node;
	node->prev = nullptr;
	head = node;
	if (length == 0)
		tail = head;
	++length;
}

template <typename T>
void List<T>::append_back(T value){
	if (length == 0){
		append_front(value);
		return;
	} else {
		DLLNode<T>* node = new DLLNode<T>(value);
		node->prev = tail;
		node->next = nullptr;
		tail->next = node;
		tail = node;
		length++;
	}
}

template <typename T>
void List<T>::insert(index_t index, T value){
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
			DLLNode<T>* node = new DLLNode<T>(value);
			node->next = nextNode;
			node->prev = prevNode;
			prevNode->next = node;
			nextNode->prev = node;
			length++;
		}
	}
}

template <typename T>
index_t List<T>::search(T value){
	if (length != 0){
		int index = 0;
		DLLNode<T>* node = head;
		while (node->value != value){
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
void List<T>::remove_front(){
	if (length != 0){
		DLLNode<T>* node = head;
		head = head->next;
		head->prev = nullptr;
		delete node;
		length--;
	}
}

template <typename T>
void List<T>::remove_back() {
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
void List<T>::remove(index_t index){
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
void List<T>::push_back(T value){
	append_back(value);
}

template<typename T>
void List<T>::push_front(T value){
	append_front(value);
}

template<typename T>
T List<T>::pop_front(){
	T tmp = begin();
	remove_front();
	return tmp;
}

template<typename T>
T List<T>::pop_back(){
	T tmp = end();
	remove_back();
	return tmp;
}

template<typename T>
inline T List<T>::begin(){
	return head->value;
}

template<typename T>
inline T List<T>::end(){
	return tail->value;
}

template<typename T>
void List<T>::purge(){
	if(length != 0)
		for(index_t i = 0;i < length;i++)
			remove_front();
}

template<typename T>
void List<T>::print(){
	std::cout << "[ ";
	if(length != 0){
		DLLNode<T>* node = head;
		for(index_t i = 0;i < length - 1;i++){
			std::cout << node->value <<  ",";
			node = node->next;
		}
		std::cout << node->value;
	}
	std::cout << " ] ";
}

template<typename T>
T List<T>::operator[](index_t index){
	return get(index);
}

template<typename T>
void List<T>::strip(T value){
	for(index_t i = 0; i < length;i++){
		if(get(i) == value){
			for(index_t j = i;j < length;j++){
				if(get(j) == value)
					remove(j);
			}
		}
	}
}

template<typename T>
void List<T>::freedup(){
	for(int i = 0;i < length;i++)
		strip(get(i));
}

template<typename T>
void List<T>::swap(index_t index_1,index_t index_2){
	DLLNode<T>* node1 = get_node(index_1);
	DLLNode<T>* node2 = get_node(index_2);
	T tmp = node1->value;
	node1->value = node2->value;
	node2->value = tmp;
}

template<typename T>
void List<T>::reverse(){
	index_t mid = (this->length - 1) / 2;
	for(index_t i = 0;i <= mid;i++)
		swap(i,(length - i - 1));
}