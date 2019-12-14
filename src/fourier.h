/*
 * fourier.h
 *
 *  Created on: Dec 12, 2019
 *      Author: will
 */

#ifndef FOURIER_H_
#define FOURIER_H_

#include <cmath>
#include <vector>
#include <complex>

using namespace std;

// imaginary number i = sqrt(-1) represented as a complex object containing doubles
const complex<double> J(0.0, 1.0);

vector<complex<double>> fourier(vector<double> signal, int N);
vector<double> magnitude(vector<complex<double>> spectrum);


#endif /* FOURIER_H_ */
