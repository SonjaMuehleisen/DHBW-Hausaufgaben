#include <stdio.h>
#include <stdlib.h>
#include"Header.h"

//Sonja M�hleisen 
double z = 0;
double y = 0;
double x = 100;

int main() {

    
    
    //Speicherplatz f�r Array
    double** a = malloc(2 * sizeof(double)); //Reihe
    if (NULL == a) {
        printf("Speicher reicht nicht!\n");
        return EXIT_FAILURE;
    }
    for (int s = 0; s < 2; s++) {
        a[s] = malloc(100 * sizeof(double));//Spalte
        if (NULL == a[s]) {
            printf("Kein Speicher mehr fuer Zeile %d\n", s);
            return EXIT_FAILURE;

        }
    }

    //Variablen definieren
    double g = 0.00000001; //Genauikeit einstellen
    double f = -0.0000001;
    int i = 0; // this is unused
    int k = 0; // this is unused


    //Berechnung
    do {
        y = yfunct(x);
        z = zfunct(x);
        x = xfunct(x, y, z);

       /* a[i][k] = x;
        printf("x=%.8f ", a[i][k]);
        k++;
        a[i][k] = y;
        printf("y=%.8f \n", a[i][k]);
        k--;
        i++;*/
        
        printf("x=%.8f    y=%.8f\n ", x,y);

    } while (y > g | y< f); // consider "||" as locical or in c
       
       
    

}


/*
JW-2020-05-12:
--------------
> nice implementation! (9/10) 
> please same name for c-lib and h-lib file next time :-)
> missing abort criteria max iterations: -1P
*/