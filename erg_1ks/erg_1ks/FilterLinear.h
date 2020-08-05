#ifndef _FILTERLINEAR_
#define _FILTERLINEAR_

#include "Filter.h"
#include "Vec3.h"

namespace imaging{

	class FilterLinear : public Filter{

	private:
		math::Vec3<float> a,
			c;

	public:

		virtual Image operator << (const Image & image) override;

		FilterLinear();

		FilterLinear(math::Vec3<float> a, math::Vec3<float> c);

		~FilterLinear();

		void setvec3(math::Vec3<float>, math::Vec3<float>);
	};

}

#endif
