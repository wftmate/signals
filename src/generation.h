/*
 * generation.h
 *
 *  Created on: Dec 12, 2019
 *      Author: will
 */

//use either "#pragma once" or "ifndef ___"

#ifndef GENERATION_H_
#define GENERATION_H_

// only include <vector> & <cmath> here in the header.
// they will be copied to all files which include this file
#include <vector>
#include <cmath>
#include <fftw3.h>

using namespace std;

// if you don't include the above line "using namespace std;"
// you must define the function like this so that it knows where to find the
// vector type
std::vector<double> gen_sine(int sample_rate, int length);

// if you do include "using namespace std;" you don't need to include the
// prefix "std::___"
vector<double> gen_cos(int sample_rate, int length);

fftw_complex * gen_complex_sin(int N, int length);

#endif /* GENERATION_H_ */
