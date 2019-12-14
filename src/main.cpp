#include <iostream>
//#include <fstream>
//#include <cstring>
#include <fftw3.h> // sudo apt isntall fftw3-dev

#include "generation.h"
#include "fourier.h"
#include "display.h"

using namespace std;

#define REAL 0
#define IMAG 1

const string n ="\n";

//define important constants for signal generation
int N = 128; //sampling rate
int length = 2;

// for playing with lists/vectors/iterators
std::vector<double>::iterator it; // still not sure how this shit works...
std::vector<int> list = {1, 2, 3, 4};

int main(){
	// generate sine & cosine functions
	vector<double> sine;
	sine = gen_sine(N, length);
	vector<double> cosine;
	cosine = gen_cos(N, length);
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
	// allocate memory for real input signal
	double* in;
	in = (double*)fftw_malloc(sizeof(double) * N);

	// allocate memory for complex output signal
	fftw_complex* out;
	out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (N/2)+1);

	// create fft plan
	fftw_plan plan;
	plan = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

	// execute fft
	fftw_execute(plan);
	// find magnitude of complex-valued fft

	// plot magnitude

	return 0;
}
