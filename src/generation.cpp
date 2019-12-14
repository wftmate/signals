/*
 * generation.cpp
 *
 *  Created on: Dec 12, 2019
 *      Author: will
 */
#include <fftw3.h>
#include "generation.h"

std::vector<double> gen_sine(int sample_rate, int length){
	// generate sine wave
	std::vector<double> signal;
	double sample;
	for(int i = 0; i < length*sample_rate; i++){
		sample = sin((2*M_PI/sample_rate)*i);

		//it = signal.begin();
		if(sample < 1e-4 && sample > -1e-4){
			sample = round(sample);
		}
		//sin[i] = sin(i); // sin() fnc from cmath library
		signal.push_back(sample);
	}
//	cout << signal.size() << endl;
	return signal;
}

vector<double> gen_cos(int sample_rate, int length){
	// generate sine wave
	std::vector<double> signal;
	double sample;
	for(int i = 0; i < length*sample_rate; i++){
		sample = cos((2*M_PI/sample_rate)*i);

		//it = signal.begin();
		if(sample < 1e-4 && sample > -1e-4){
			sample = round(sample);
		}
		//sin[i] = sin(i); // sin() fnc from cmath library
		signal.push_back(sample);
	}
//	cout << signal.size() << endl;
	return signal;
}

fftw_complex * gen_complex_sin(int sample_rate, int length){
	fftw_complex sine;
	for(int i = 0; i < length; i++)
		sine[i][0] = (sin((2*M_PI/sample_rate)*i));

	return sine;
}
