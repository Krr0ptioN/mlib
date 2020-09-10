template<typename T>
mlib::array<T>::array(index_t entr_size) : size(entr_size) {
	list = new T[size];
}

template<typename T>
mlib::array<T>::array(const array<T> &array2){
	size = array2.getSize();
	list = new T[size];
	for(index_t i = 0; i < array2.length;i++)
		list[length++] = array2[i];
}

template<typename T>
mlib::array<T>::~array(){
	purge();
	this->size = this->length = 0;

}

template<typename T>
index_t mlib::array<T>::getSize(){
	return this->size;
}

template<typename T>
index_t mlib::array<T>::getLength(){
	return this->length;
}

template<typename T>
inline T mlib::array<T>::get(index_t index){
	if(not(index >= length)){
		if(index < 0) 
			return list[length + (index - 1)];
		else
			return list[index];
	} else {
		throw std::out_of_range("Index elements out of range");
	}
}

template<typename T>
T mlib::array<T>::operator[](index_t index){
	return get(index);
}

template<typename T>
void mlib::array<T>::append_back(T value){
	if (length >= size)
		resize(1);
	list[length++] = value;
}

template<typename T>
void mlib::array<T>::append_back(array& array2){
	index_t size2 = array2.getSize();
	int append_size = size - size2;
	append_size = abs(append_size);
	if(append_size != 0)
		resize(append_size);
	for(index_t i = length;i < length+size2;i++){
		list[length++] = array2[i];
	}
}

template<typename T>
void mlib::array<T>::append_front(T value){
	if (length >= size)
		resize(1);
	for(unsigned int i = 0;i < length - 1;i++)
		list[i] = list[i+1];
	list[0] = value;
	++length;

}


template<typename T>
void mlib::array<T>::resize(index_t add_size){
	if(add_size > 0){
		this->size += add_size;
		T *tmpList = new T[this->size];
		for(index_t i = 0;i <= length;i++)
			tmpList[i] = list[i];
		delete[] list;
		list = tmpList;
	}
} 

template<typename T>
void mlib::array<T>::insert(index_t index,T value){
	index_t neg_index = length + index;
	if(neg_index >= size or index >= size)
		resize(length);
	if(index < 0) {
		for(index_t i = length;i > neg_index;i--)
			list[i] = list[i- 1];
		list[neg_index] = value;
	} else {
		for(index_t i = length;i > index;i--)
			list[i] = list[i - 1];
		list[index] = value;
	}
	length++;
}

template<typename T>
index_t mlib::array<T>::search(T value){
	index_t mid = (length - 1)/2;
	if(list[mid] == value)
		return mid;
	for(index_t i = 0;i < mid;i++){
		if(list[i] == value)
			return i;
		else if(list[length - (i+1)] == value)
			return length - (i+1);
	}

	return -1;
}

template<typename T>
void mlib::array<T>::remove(index_t index){
    for(;index < length;index++)
		list[index] = list[index + 1];
	length--;
}

template<typename T>
void mlib::array<T>::remove_back(){
    remove(0);
}

template<typename T>
void mlib::array<T>::remove_front(){
    remove(length - 1);
}

template<typename T>
inline void mlib::array<T>::swap(index_t index,index_t index2){
	T tmp = list[index];
	list[index] = list[index2];
	list[index2] = tmp;
}

template<typename T>
void mlib::array<T>::reverse(){
	index_t mid = (length - 1)/2;
	for(index_t i = 0;i <= mid;i++)
		swap(i,(length - i - 1));
}


template<typename T>
void mlib::array<T>::print(){
	std::cout << "[ ";
	for(index_t i = 0;i < length;i++)
		std::cout << list[i]
			  << ((i == (length - 1)) ? " ] " : ",");
}

template<typename T>
void mlib::array<T>::shiftRight(){
	T tmp = get(-1);
	for(unsigned int i = length;i > 0;i--)
		list[i] = list[i - 1];
	list[0] = tmp;
}

template<typename T>
void mlib::array<T>::shiftLeft(){
	T tmp = list[0];
	for(unsigned int i = 0;i < length - 1;i++)
		list[i] = list[i+1];
	list[length-1] = tmp;
}
template<typename T>
T mlib::array<T>::begin(){
	return get(0);
}

template<typename T>
inline T mlib::array<T>::end(){
	return get(-1);
}

template<typename T>
inline void mlib::array<T>::strip(T value){
	for(index_t i = 0; i < length;i++){
		if(list[i] == value){
			for(index_t j = i;j < length;j++){
				if(list[j] == value)
					remove(j);
			}
		}
	}
}

template<typename T>
inline void mlib::array<T>::freedup(){
	T end_value = end();
	for(index_t i = 0;i < length;i++)
		strip(list[i]);
}


template<typename T>
inline T mlib::array<T>::pop_front(){
	T tmp = begin();
	remove_back();
	return tmp;
}


template<typename T>
inline T mlib::array<T>::pop_back(){
	T tmp = end();
	remove_front();
	return tmp;
}

template<typename T>
inline void mlib::array<T>::push_front(T value){
	insert(0,value);
}

template<typename T>
inline void mlib::array<T>::push_back(T value){
	append_back(value);
}

template<typename T>
void mlib::array<T>::purge(){
	delete[] this->list;
}