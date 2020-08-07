#include <iostream>
typedef long int index_t;
namespace mdata{
	template<typename T>

	class CollectionBase {
	public:
		index_t length = 0;
		index_t size = 0;
		virtual inline T get(index_t index) = 0;
		virtual void resize(index_t add_size) = 0;
		virtual void append(T value) = 0;
		virtual void remove(index_t index) = 0;
		virtual void insert(index_t index,T value) = 0;
		virtual index_t search(T value) = 0;
		virtual inline void swap(index_t index,index_t index2) = 0;
		virtual void reverse() = 0;
		virtual void print()  = 0;
		virtual void shiftRight() = 0;
		virtual void shiftLeft() = 0;
		virtual void strip(T value) = 0;
		virtual T begin() = 0;
		virtual T end() = 0;
		virtual inline T pop_front() = 0;
		virtual inline T pop_back() = 0;
		virtual inline void push_front(T value) = 0;
		virtual inline void push_back(T value) = 0;

		virtual T operator[](index_t index) = 0;
	};

}
