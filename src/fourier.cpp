/*
 * fourier.cpp
 *
 *  Created on: Dec 12, 2019
 *      Author: will
 */

#include "fourier.h"

/*
 * this function generates a fourier transform of a signal using
 * the definition of the transform
 */
vector<complex<double>> fourier(vector<double> signal, int N){
	vector<complex<double>> spectrum;
//	int count = 0;
	for(int k = 0; k < N; k++){		// outer loop calculates output pnts
		complex<double> tmp(0.0, 0.0);
		for(int n = 0; n < N; n++){	// inner loop sums vals for each pnt k
			tmp += signal[n]*exp(-J*((2.0*M_PI)/N)*(double)n*(double)k);

			// this is just debug code
//			printf("k:%2i,  n:%2i, sig[n]:% f  tmp[real]:% f,  tmp[imag]:% f\n",
//					k,		n, (float)signal[n] ,(float)tmp.real(), (float)tmp.imag());
//			count++;
		}
//		tmp(real() // access real component
//		tmp.real() // access real component
		tmp = tmp/(double)N;
		spectrum.push_back(tmp);
	}
//	cout << count << endl;
	return spectrum;
}

/*
 * this function computes the magnitude of the above fourier transform
 */
vector<double> magnitude(vector<complex<double>> spectrum){
	vector<double> magnitude;

	printf("finding magnitude\n");
	//find magnitude of spectrum
	for(int i = 0; i < (int)spectrum.size(); i++){
		magnitude.push_back(abs(spectrum[i]));

//		this is just debug code
//		printf("magnitude[i] = % f\n", (float)magnitude[i]);
	}
	return magnitude;
}

