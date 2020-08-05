#ifndef _FILTER_
#define _FILTER_

#include "Image.h"
#include <iostream>

namespace imaging{

	class Filter{
	public:
		virtual Image operator << (const Image & image) = 0;

		Filter(){}

		Filter(const Filter & F){}

		virtual ~Filter(){}

	};
}
#endif