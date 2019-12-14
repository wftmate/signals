/*
 * display.h
 *
 *  Created on: Dec 12, 2019
 *      Author: will
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>
#include <iostream>

using namespace std;

// to get this to work make sure to do the following
// from terminal: "sudo apt install libgnuplot-iostream-dev"
#include "gnuplot-iostream.h"

void plot(std::vector<double> list);
void print(std::vector<double> sine);


#endif /* DISPLAY_H_ */
