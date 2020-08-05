#include "Image.h"
#include "Array.h"
#include "ppm.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

typedef math::Vec3<float> T;

using namespace std;
using namespace imaging;
using namespace math;


using  T = math::Vec3 <float>;

Image::Image() : Array() {}

Image::Image(unsigned int width, unsigned int height) : Array(width, height) {}

Image::Image(unsigned int width, unsigned int height, const vector<Vec3<float>> & data_ptr) : Array(width, height, data_ptr) {}

Image::Image(const Image &src) : Array(src) {}

Image::~Image() {}

Image & Image::operator = (const Image & right) {
	if (&right != this) {
		width = right.width;
		height = right.height;
		buffer = right.buffer;
	}
	return *this;
}

//load image 
bool Image::load(const string & filename, const string & format) {

	if (filename.substr(filename.find_last_of(".") + 1) != format) {
		cerr << "Wrong image format" << endl;
		return false;
	}
	else {

		buffer.clear();
		int new_width;
		int new_height;

		float *myArray = ReadPPM(filename.c_str(), &new_width, &new_height);

		this->width = new_width; this->height = new_height;

		unsigned int size = width * height;
		buffer.resize(size);

		for (unsigned int i = 0; i < size; i++) {
			T &c = buffer[i];
			c.r = myArray[3 * i];
			c.g = myArray[3 * i + 1];
			c.b = myArray[3 * i + 2];
		}

		cout << "Image successfully loaded" << endl;
		delete[] myArray;
		return true;
	}

}

//new image saved
bool Image::save(const std::string & filename, const std::string & format) {

	if (filename.substr(filename.find_last_of(".") + 1) != format) {

		cerr << "Wrong image format" << endl;
		return false;
	}
	unsigned int size = this->buffer.size();
	float *myArray = new float[3 * size];

	for (unsigned int i = 0; i < size; i++) {
		T &c = buffer[i];
		myArray[i * 3] = c.r;
		myArray[i * 3 + 1] = c.g;
		myArray[i * 3 + 2] = c.b;
	}

	bool ft = WritePPM(myArray, width, height, filename.c_str());
	cout << "Image successfully saved" << endl;
	return ft;
}