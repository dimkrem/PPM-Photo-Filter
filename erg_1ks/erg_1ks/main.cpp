#include <iostream> 
#include <fstream>
#include <string>
#include "ppm.h"
#include "Image.h"
#include "FilterLinear.h"
#include "FilterGamma.h"


using namespace std;
using namespace imaging;
using namespace math;

int main(int argc, char* argv[]){
	Image * img = new Image();

	string file(argv[argc - 1]);   //get the file from the arguments , the last argument given
	
	img->load(file, "ppm"); //load the image

	FilterGamma  *filterptr = new FilterGamma();
	FilterLinear *filterptr1 = new FilterLinear();
	

	Vec3<float> a, c;

	vector<string> argL;
	for (unsigned int i = 1; i < argc - 1; ++i) {
		argL.push_back(argv[i]);
	}

	for (unsigned int i = 0; i < argL.size(); ++i) {
		if (argL[i] == "-f") {
			++i;
			if (argL[i] == "gamma") {
				++i;
				filterptr->setgamma(stof(argL[i]));
				*img = (*filterptr) << (*img);
			}
			else if (argL[i] == "linear") {
				++i;
				a.r = stof(argL[i]); ++i;
				a.g = stof(argL[i]); ++i;
				a.b = stof(argL[i]); ++i;
				c.r = stof(argL[i]); ++i;
				c.g = stof(argL[i]); ++i;
				c.b = stof(argL[i]);
				filterptr1->setvec3(a, c);
				*img = (*filterptr1) << (*img);
			}
			
			
		}
		else {
			cout << "Sorry,wrong input! " << endl;
			break;
		}

	}

	file.insert(0, "filtered_"); //name of new file filtered_Imagexx

	(*img).save(file, "ppm"); //save new ppm filtered image
	
	//free space in memory
	delete img;
	delete filterptr;
	delete filterptr1;
	
	return 0;
	
	system("pause");
}