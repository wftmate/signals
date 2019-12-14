#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <fftw.h>
#include <fftw3.h> // sudo apt isntall fftw3-dev
#include <rfftw.h>

#include "generation.h"
#include "fourier.h"
#include "display.h"

using namespace std;

const string n ="\n";

//define important constants for signal generation
int N = 128; //sampling rate
int length = 2;

// for playing with lists/vectors/iterators
std::vector<double>::iterator it; // still not sure how this shit works...
std::vector<int> list = {1, 2, 3, 4};

int main(){
	// plot the sine function only
	vector<double> sine;
	sine = gen_sine(N, length);
	//plot(sine);

//	// plot the cosine function
//	vector<double> cosine;
//	cosine = gen_cos(N, length);
//	plot(cosine);

	// get the fourier transform of the sine
	vector<complex<double>> spectrum;
	spectrum = fourier(sine, N);

	// find the magnitude of the fourier transform of the sine
	vector<double> mag;
	mag = magnitude(spectrum);

	// plot the magnitude of the fourier transform of the sine
	Gnuplot mg;
	printf("generating plot\n");
	plot(mag);

//	// -- FFTW3 of real signal (version 3.3.8) ---
	fftw_complex *in, *out;




	return 0;
}
