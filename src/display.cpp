/*
 * display.cpp
 *
 *  Created on: Dec 12, 2019
 *      Author: will
 */

#include "display.h"

void plot(std::vector<double> list){
//	Gnuplot p;
//	p << "plot [0:15] sin(x)\n";
//	p("plot sin(x)");					 // this gives no linter error but it doesn't work/compile

	Gnuplot gp;
	gp << "set xlabel 'Time' font 'Helvetica, 12'\n" 	<<
	      "set ylabel 'Amplitude' font 'Helvetica, 12'" << endl;
	gp << "set title 'Sine Wave' font 'Helvetica, 13'" 	<< endl;
	gp << "set tics font 'Helvetica, 10'" 				<< endl;
	gp << "set grid xtics lt 0 lw 1 lc 'gray'\n" 		<<
		  "set grid ytics lt 0 lw 2 lc 'gray'" 			<< endl;
	gp << "plot '-' lt 1 lw 2 linecolor 'blue' with line title 'Time domain'\n";
	//gp << "plot '-' lt 1 with points" << endl; // '-' means read from stdin.
	gp.send1d(list);						 // The send1d() function sends data to gnuplot's stdin.
	//gp << "clear\n";
}

void print(vector<double> sine){
	// print sine wave values to console
	printf("the vector contains the following data members\n");
	for(int j = 0; j < sine.size(); j++){
//		std::cout << j << " | " << sine2[j] << std::endl;

		std::printf("i = %3i", j+1);
		//std::printf(" | cos = % 4f", cosine);
		std::printf(" | sin = % 4f\n", sine[j]);
	}
}
