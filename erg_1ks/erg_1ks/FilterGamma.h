#ifndef _FILTERGAMMA_
#define _FILTERGAMMA_

#include "Filter.h"
#include "Vec3.h"

namespace imaging{

	class FilterGamma : public Filter{
	private:
		float gamma;
	public:
		virtual imaging::Image operator << (const imaging::Image & image) override;

		FilterGamma();

		FilterGamma(float);

		~FilterGamma();

		void setgamma(float);

	};
}
#endif