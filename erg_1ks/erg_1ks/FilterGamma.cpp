#include "FilterGamma.h"
#include "Image.h"
#include <cmath>

using namespace std;
using namespace imaging;
using namespace math;

Image FilterGamma :: operator << (const Image & image) {

	Image img(image.getWidth(), image.getHeight());

	for (unsigned int y = 0; y < image.getHeight(); y++) {
		for (unsigned int x = 0; x < image.getWidth(); x++) {
			T &temp = image.getElement(x, y); 
			temp.r = pow(temp.r, gamma);
			temp.g = pow(temp.g, gamma);
			temp.b = pow(temp.b, gamma);

			img.setElement(x, y, temp);
		}
	}
	return img;
}

FilterGamma::FilterGamma() : FilterGamma(0.5){}

FilterGamma::FilterGamma(float g){
	if (g >= 0.5 && g <= 2.0) {
		gamma = g;
	}
	else {
		gamma = 0.5; 
	}
}

//check gamma parameter user entered, it has to be 0.5 < = gamma <= 2.0
void FilterGamma::setgamma(float gamma) {
	if (gamma >= 0.5 && gamma <= 2.0) {
		this->gamma = gamma;
	}
	else {
		cout << "You must enter a float between 0.5 and 2.0" << endl;
	}
}

FilterGamma::~FilterGamma(){}

