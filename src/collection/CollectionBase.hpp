#include <iostream>

namespace mdata{
	template<typename T>

	class CollectionBase {
	public:
		size_t length = 0;
		size_t size = 0;
		virtual inline T get(size_t index) = 0;
		virtual inline void set(size_t index,T value) = 0;
		virtual void resize(size_t add_size) = 0;
		virtual void append(T value) = 0;
		virtual void remove(size_t index) = 0;
		virtual void insert(size_t index,T value) = 0;
		virtual size_t search(T value) = 0;
		virtual inline void swap(size_t index,size_t index2) = 0;
		virtual void reverse() = 0;
		virtual void print() = 0;
		virtual void shiftRight();
		virtual void shiftLeft();
		virtual T operator[](size_t index) = 0;
	};

}
