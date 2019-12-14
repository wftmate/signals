#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <complex.h>
#include <fftw3.h> // sudo apt isntall fftw3-dev

#include "generation.h"
#include "display.h"
#include "my_fourier.h"

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

vector<double> my_fft(int N, vector<double> in_d){
    vector<double> out_d;
	fftw_complex *in, *out;
    fftw_plan p;

    // put input vector into complex container
    fftw_complex sin;
    sin = gen_complex_sin(N, N);

    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    //fftw_execute(p); /* I had to replace this line with the one below */
    fftw_execute((fftw_plan_s*)p); /* repeat as needed */

    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
    return out_d;
}

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

	return 0;
}
