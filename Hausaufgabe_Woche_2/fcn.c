#include <stdio.h>
#include <math.h>

/* Cedrik Holzwarth
   Sonja Mühleisen
   15.05.2020
   file name: mainkomplexe
   Hausaufgabe Woche 2
*/

double fcnphi(double real, double imag) {

	double erg, temp;
	temp = imag / real;

	erg =atan(temp);

	return erg;
}
double fcnleng(double real, double imag) {
	double erg;

	erg = sqrt((pow(real, 2) + pow(imag, 2)));



	return erg;
}


double fcnadd(double zahl1, double zahl2) {

	double erg = zahl1 + zahl2;

	return erg;

}

double fcnsub(double zahl1, double zahl2) {

	double erg = zahl1 - zahl2;

	return erg;

}

double fcnmult(double leng1, double leng2) {

	double erg = leng1 * leng2;

	return erg;

}

double fcndiv(double leng1, double leng2) {

	double erg = leng1 / leng2;

	return erg;

}

//Rückrechnung
double fcncos(double leng,double phi){
	
	
	double erg = leng * cos(phi);
	return erg;
}

double fcnsin(double leng, double phi) {


	double erg = leng * sin(phi);
	return erg;
}