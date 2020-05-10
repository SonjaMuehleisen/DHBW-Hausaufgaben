#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double yfunct(double x){

	double i = 0;

	i = pow((x - 3),2);

	return i;

}


double zfunct(double x){

	double i = 0;

    i = 2*(x - 3);

	return i;

}

double xfunct(double x, double y, double z){

	double i = 0;
    i = x - (y / z);

    return i;
}