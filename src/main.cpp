#include <iostream>
//#include <fstream>
//#include <cstring>
#include <fftw.h> // sudo apt isntall fftw3-dev
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

	// change

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

//	// -- complex fft using fftw3 ---
//	// create in and out arrays
//	fftw_complex in[N], out[N];
//	// create a plan
//	fftw_plan p;
//	p = fftw_create_plan(N ,FFTW_FORWARD, FFTW_ESTIMATE);
//	// perform fft
//	fftw_one(p, in, out);
//	// print plot(magnitude(fft(signal)))
//
//	// destroy fftw_plan
//	fftw_destroy_plan(p);
//
//	// -- another plan type ---
//	fftw_plan_dft_1d <- what is this for
//
//	// -- real fft using rfftw ---
//	fftw_real in_r[N], out_r[N], power_spectrum[N/2+1];
//	rfftw_plan pr;
//	pr = rfftw_create_plan(N, FFTW_REAL_TO_COMPLEX, FFTW_ESTIMATE);
//	rfftw_one(p, in_r, out_r);
//	power_spectrum[0] = out_r[0]*out_r[0]; /* DC component */
//	for(int k = 1; k < (N+1)/2; k++) /* k < N/2 rounded up */
//		power_spectrum[k] = out_r[k]*out_r[k] + out_r[N-k]*out_r[N-k];
//	if(N % 2 ==0) /* N is even */
//		power_spectrum[N/2] = out_r[N/2]*out_r[N/2]; /* Nyquist freq */
//
//	rfftw_destroy_plan(pr);
	return 0;
}
