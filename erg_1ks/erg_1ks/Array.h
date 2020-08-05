
#ifndef _ARRAY
#define _ARRAY

#include <vector>
#include <string>

using namespace std;

namespace math
{

	template<typename T>
	class Array
	{

	protected:
		vector<T>  buffer;
		unsigned int width,
			height;

	public:
		const unsigned int getWidth() const {
			return width;
		}

		const unsigned int getHeight() const {
			return height;
		}

		vector<T> * getRawDataPtr();

		T getElement(unsigned int x, unsigned int y) const;

		void setElement(unsigned int x, unsigned int y, T & value);

		void setData(const vector<T>  & data_ptr);

		Array();

		Array(unsigned int width, unsigned int height);

		Array(unsigned int width, unsigned int height, const vector<T> & other_vector);

		Array(const Array &src);

		~Array();

		Array & operator = (const Array & right);

		T & operator() (unsigned int i, unsigned int j);

	}; //end class Array

	/*-------------------------------------------------------------------------------------*/

	template<typename T>
	vector<T> * Array<T>::getRawDataPtr() {
		return &buffer;
	}

	//get the element at a particular (x,y) position
	template<typename T>
	T Array<T>::getElement(unsigned int x, unsigned int y) const {
		T b;
		if (x >= width || y >= height) {
			return b;
		}
		else {
			return buffer[y*width + x];
		}
	}

	//set a certain value at a certain (x,y) element
	template<typename T>
	void Array<T>::setElement(unsigned int x, unsigned int y, T & value) {
		if (x >= width || y >= height) {
			return;
		}
		
		buffer[y*width + x] = value;
		
	}

	template<typename T>
	void Array<T>::setData(const vector<T>  & data_ptr) {
		this->buffer = data_ptr;
	}

	//constructors

	template<typename T>      
	Array<T>::Array()
		:Array(0, 0, vector<T>(width*height, 0)){
	}

	template<typename T>
	Array<T>::Array(unsigned int width, unsigned int height)
		: width(width), height(height), buffer(std::vector<T>(width*height, 0)) {

	}

	template<typename T>
	Array<T>::Array(unsigned int width, unsigned int height, const vector<T> & other_vector) {
		this->width = width;
		this->height = height;
		setData(other_vector);
	}

	template<typename T>
	Array<T>::Array(const Array &src) {
		this->width = src.width;
		this->height = src.height;
		unsigned int size = width * height;
		this->buffer = src.buffer;
	}

	template<typename T>
	Array<T>::~Array() {
		buffer.clear();
		this->width = 0;
		this->height = 0;
	}

	template<typename T>
	Array<T> & Array<T>:: operator = (const Array & right) {

		if (&right != this) {
			buffer.clear();
			this->height = right.height;
			this->width = right.width;

			for (unsigned int i = 0; i < width*height; ++i) {
				buffer.push_back(right.buffer[i]);
			}
		}

		return *(this);
	}

	template<typename T>
	T & Array<T>::operator() (unsigned int i, unsigned int j) {

		if (i < width && j < height) {
			return buffer[width*i + j];
		}
	}

} //end using namespace math



#endif