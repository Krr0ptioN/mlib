#pragma once

namespace mlib {

   	template<typename T>
	class Stack {
	public:
		virtual void push_back(T value) = 0;
		virtual T pop_back() = 0;
	};
}