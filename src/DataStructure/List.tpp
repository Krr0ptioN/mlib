template<typename T>
mlib::List<T>::List(){}

template<typename T>
mlib::List<T>::~List(){
	purge();
}

template<typename T>
T mlib::List<T>::get(index_t index){
	if (not(index < 0 or index > length)){
		Node<T>* node = head;
		for (int i = 0; i < index; ++i)
			node = node->next;
		return node->value;
	}
	return NULL;
}


template <typename T>
void mlib::List<T>::append_front(T value)
{
	Node<T>* node = new Node<T>(value);
	node->next = head;
	head = node;
	if (length == 0)
		tail = head;
	length++;
}

template <typename T>
void mlib::List<T>::append(T value){
	if (length == 0){
		append_front(value);
		return;
	} else {
		Node<T>* node = new Node<T>(value);
		tail->next = node;
		tail = node;
		length++;
	}
}

template <typename T>
void mlib::List<T>::insert(index_t index, T value){
	if (not(index < 0 or index > length)){
		if (index == 0){
			append_front(value);
		} else if (index == length){
			append(value);
		} else {
			Node<T>* prevNode = head;
			for (int i = 0; i < index - 1; ++i)
				prevNode = prevNode->next;
			Node<T>* nextNode = prevNode->next;
			Node<T>* node = new Node<T>(value);
			node->next = nextNode;
			prevNode->next = node;
			length++;
		}
	}
}

template <typename T>
index_t mlib::List<T>::search(T value){
	if (length != 0){
		int index = 0;
		Node<T>* node = head;
		while (node->value != value){
			++index;
			node = node->next;
			if (node == nullptr){
				return -1;
			}
		}
		return index;
	}
	return -1;
}

template <typename T>
void mlib::List<T>::remove_front(){
	if (length != 0){
		Node<T>* node = head;
		head = head->next;
		delete node;
		length--;
	}
}

template <typename T>
void mlib::List<T>::remove_back() {
	if (not(length == 0)){
		if (length == 1) {
			remove_front();		
		} else {	
			Node<T>* prevNode = head;
			Node<T>* node = head->next;

			while (node->next != nullptr) {
				prevNode = prevNode->next;
				node = node->next;
			}
			prevNode->next = nullptr;
			tail = prevNode;
			delete node;
			--length;
		}
	}
}

template<typename T>
void mlib::List<T>::remove(index_t index){
	if (not(index < 0 or index >= length or length == 0)){
		if (index == 0) {
			remove_front();
		} else if (index == length - 1){
			remove_back();
		} else {
			Node<T>* prevNode = head;
	
			for(int i = 0; i < index - 1; ++i)
				prevNode = prevNode->next;
			Node<T>* node = prevNode->next;
			Node<T>* nextNode = node->next;	
			prevNode->next = nextNode;
			delete node;
			length--;
		}
	}
}

template<typename T>
void mlib::List<T>::push_back(T value){
	append(value);
}

template<typename T>
void mlib::List<T>::push_front(T value){
	append_front(value);
}

template<typename T>
T mlib::List<T>::pop_front(){
	T tmp = begin();
	remove_front();
	return tmp;
}

template<typename T>
T mlib::List<T>::pop_back(){
	T tmp = end();
	remove_back();
	return tmp;
}

template<typename T>
inline T mlib::List<T>::begin(){
	return get(0);
}

template<typename T>
inline T mlib::List<T>::end(){
	return get(length - 1);;
}

template<typename T>
void mlib::List<T>::purge(){
	for(index_t i = 0;i < length;i++)
		remove_front();
}

template<typename T>
void mlib::List<T>::print(){
	std::cout << "[ ";
	Node<T>* node = head;
	for(index_t i = 0;i < length;i++){
		std::cout << node->value 
				  << ((i == length - 1) ? " " : ",");
		node = node->next;
	}
	std::cout << "] ";
}

template<typename T>
T mlib::List<T>::operator[](index_t index){
	Node<T>* tmp = get(index);
	return tmp->value;
}

template<typename T>
void mlib::List<T>::strip(T value){
	for(index_t i = 0; i < length;i++){
		if(get(i) == value){
			for(index_t j = i;j < length;j++){
				if(get(j) == value)
					remove(j);
			}
		}
	}
}
