
#ifndef _IMAGE
#define _IMAGE

#include "Array.h"
#include "Vec3.h"
#include "Image.h"
#include <vector>

typedef math::Vec3<float> T;

using namespace std;
using namespace math;


namespace imaging{
	using  T = math::Vec3 <float>;
	

	class Image : public math::Array<T> {

	public:
		Image();

		Image(unsigned int width, unsigned int height);

		Image(unsigned int width, unsigned int height, const std::vector<T> & other_vector);

		Image(const Image &src);

		~Image();

		Image & operator = (const Image & right);

		bool load(const std::string & filename, const std::string & format);
		bool save(const std::string & filename, const std::string & format);
	};
}

#endif