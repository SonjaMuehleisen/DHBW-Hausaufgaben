#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcn.h"


/* Cedrik Holzwarth 
   Sonja M�hleisen
   15.05.2020
   file name: mainkomplexe
   Hausaufgabe Woche 2
*/

 
typedef struct {

	char numb1[10];
	char numb2[10];
	double real;
	double imag;
	double phi;
	double leng;

}komplex;


int main() {

	//Zahlen eingeben und abspeichern
	komplex zahl1;
	komplex zahl2;

	/*printf("Geben Sie den Realteil der ersten Zahl ein:   \n");
	scanf("%lf", &zahl1.real);
	printf("Geben Sie den Imaginaerteil der ersten Zahl ein:   \n");
	scanf("%lf", &zahl1.imag);

	printf("Geben Sie den Realteil der zweiten Zahl ein:   \n");
	scanf("%lf", &zahl2.real);
	printf("Geben Sie den Imaginaerteil der zweiten Zahl ein:   \n");
	scanf("%lf", &zahl2.imag);*/

	printf("geben sie die erste komplexe Zahl im Format: a+bi ein\n");
	scanf("%s", &zahl1.numb1); // JW-2020-06-19: this is technically wrong but handled by the compiler. one needs >zahl.numb1< or >&zahl.numb1[0]<: -1Pkt
	printf("geben sie die zweite komplexe Zahl im Format: a+bi ein\n");
	scanf("%s", &zahl2.numb1);

	
	
	char delimiter[] = "+-i";
	char* ptr;

	ptr = strtok(zahl1.numb1, delimiter);

	//Zahlen aus String auslesen
		//printf("Abschnitt 1 %s\n", ptr);
		zahl1.real = atof(ptr);
		ptr = strtok(NULL, "\n\t ");
		//printf("Abschnitt 2 %s\n", ptr);
		zahl1.imag = atof(ptr);
		//printf(" kommt hier ein i? %lf\n", zahl1.imag);
		ptr = strtok(NULL, "\n\t ");

		ptr = strtok(zahl2.numb1, delimiter);
		zahl2.real = atof(ptr);
		ptr = strtok(NULL, "\n\t ");
		zahl2.imag = atof(ptr);
		ptr = strtok(NULL, "\n\t ");

		//printf(" zahl 1 real %lf\n zahhl 1 imag %lf\n zahl2 real %lf\n zahl 2 imag %lf\n", zahl1.real, zahl1.imag, zahl2.real, zahl2.imag);


	double (*fcnptr)(double, double);
	double (*fcnptreu)(double, double);


	double ergreal = 0;
	double ergimag = 0;
	double ergphi = 0;
	double ergleng = 0;
	int eingabe, auswahl = 0;

	printf("Addieren geben sie ein: 1\nSubtrahieren geben sie ein: 2\nMultiplizieren geben sie ein: 3\nDividieren geben sie ein: 4\n");
	scanf("%d", &eingabe);
		
	fcnptreu = fcnphi;
	zahl1.phi = fcnptreu(zahl1.real , zahl1.imag);
	zahl2.phi = fcnptreu(zahl2.real, zahl2.imag);

	fcnptreu = fcnleng;
	zahl1.leng = fcnleng(zahl1.real, zahl1.imag);
	zahl2.leng = fcnleng(zahl2.real, zahl2.imag);


	//printf("Zahl1:  phi %lf   len%f\n", zahl1.phi, zahl1.leng);
	//printf("Zahl2:  phi %lf   len%f\n", zahl2.phi, zahl2.leng);


	//Addition
	if (eingabe == 1) {
		 
		//kartesische Darstellung
		fcnptr = fcnadd;
        ergreal = fcnptr( zahl1.real, zahl2.real);
		ergimag = fcnptr( zahl1.imag, zahl2.imag);

		//Eulerdarstellung
		fcnptr = fcnphi;
		ergphi = fcnptr(ergreal, ergimag);
        fcnptr = fcnleng;
		ergleng = fcnptr(ergreal, ergimag);
	}

	//Subtraktion
	else if (eingabe == 2) {
		
		//kartesische Darstellung
		fcnptr = fcnsub;
        ergreal = fcnptr(zahl1.real, zahl2.real);
		ergimag = fcnptr(zahl1.imag, zahl2.imag);

		//Eulerdarstellung
		fcnptr = fcnphi;
		ergphi = fcnptr(ergreal, ergimag);
        fcnptr = fcnleng;
		ergleng = fcnptr(ergreal, ergimag);
	}

	//Multiplikation
	else if (eingabe == 3)
	{

		//Eulerdarstellung
		fcnptr = fcnadd;
		ergphi = fcnptr(zahl1.phi, zahl2.phi);
        fcnptr = fcnmult;
		ergleng = fcnptr(zahl1.leng, zahl2.leng);

		//kartesische Darstellung
		fcnptr = fcncos;
		ergreal = fcnptr(ergleng, ergphi);
        fcnptr = fcnsin;
		ergimag = fcnptr(ergleng, ergphi);
	}

	//Division
	else if (eingabe == 4) {

		//Eulerdarstellung
		fcnptr = fcnsub;
		ergphi = fcnptr(zahl1.phi, zahl2.phi);
        fcnptr = fcndiv;
		ergleng = fcnptr(zahl1.leng, zahl2.leng);

		//kartesische Darstellung
		fcnptr = fcncos;
		ergreal = fcnptr(ergleng, ergphi);
        fcnptr = fcnsin;
		ergimag = fcnptr(ergleng, ergphi);

	}
	else {
		printf("Bitte richtige eingabe waehlen\n");
	}

	printf("fuer kartesische Form:1 druecken\nFuer Polar1: 2 druecken\nFuer Polar2: 3 druecken\n");
	scanf("%d", &auswahl);
	if (auswahl == 1) 	printf(" Erg: %lf + (%lf)i\n", ergreal, ergimag);
	else if (auswahl == 2) printf(" Erg: %lf e^i(%lf)\n ", ergleng, ergphi);
	else if (auswahl == 3) printf(" Erg: %lf*(cos(%lf) + i*sin(%lf))\n", ergleng, ergphi, ergphi);
	else printf("lern auf 3 zu zuehlen");

	return 0;
	
}
/*
JW-2020-06-19:
--------------
> very nice implementation! (10/10) 
> check the scanf statements: -1Pkt
> if user enters a number > 4 as operation the else statement will be executed. there is no catch so the programm ends with imag = 0, real = 0: -1Pkt
> bonus well done: +2Pkt
> nice use of the string lib as well as pointers to functions :-) 
*/
