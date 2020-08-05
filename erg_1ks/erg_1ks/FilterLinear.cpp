#include "FilterLinear.h"

using namespace std;
using namespace imaging;
using namespace math;

Image FilterLinear :: operator << (const Image & image){

	Image img(image.getWidth(), image.getHeight());

	for (unsigned int y = 0; y < image.getHeight(); y++) {
		for (unsigned int x = 0; x < image.getWidth(); x++) {
			T &temp = image.getElement(x, y); 
			temp = (this->a*temp) + this->c;
			temp = temp.clampToLowerBound(0.0f);
			temp = temp.clampToUpperBound(1.0f);
			img.setElement(x, y, temp);
		}
	}
	return img;
}

//constructors
FilterLinear:: FilterLinear() : FilterLinear(0,0){}

FilterLinear :: FilterLinear (Vec3<float> a, Vec3<float> c){
	this->a = a;
	this->c = c;
}

void FilterLinear::setvec3(Vec3<float> a, Vec3<float> c) {
	a.clampToLowerBound(0.0f).clampToUpperBound(1.0f);
	c.clampToLowerBound(0.0f).clampToUpperBound(1.0f);
	this->a = a;
	this->c = c;
}

//destructor
FilterLinear::~FilterLinear() {}

