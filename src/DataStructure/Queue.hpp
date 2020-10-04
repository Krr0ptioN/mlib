
#pragma once

namespace mlib {
	
    template<typename T>
	class Queue {
	public:
		virtual void push_front(T value) = 0;
		virtual T pop_front() = 0;
		virtual T pop_back() = 0;
	};
}