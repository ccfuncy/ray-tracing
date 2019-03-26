#include<iostream>
#include<fstream>
#include<string>
#include"vec3.h"
#include "dealIm.h"

int main(){
	int nx = 200;
	int ny = 100;
	std::string fileName = "./image/example2.ppm";
	

	std::ofstream out(fileName);
	//std::cout << "P6\n" << nx << " " << ny << "\n255\n";
	out << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			//std::cout << ir << " " << ig << " " << ib << "\n";
			out << ir << " " << ig << " " << ib << "\n";
		}
	}
	Python py = Python();
	py.ppmTojpg(fileName);
}