
#include <iostream>

#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace mlib {
	template<typename T>
	class matrix {
	private:
		T **matrix;
		T *diangonal;
		index_t size = 0;
	public:
		index_t length = 0;
	};
}

#endif
