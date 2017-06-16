#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

FILE *f,*g;

int main()
{
    f = fopen("sudoku.in","r");
    g = fopen("sudoku.out","w");

    int linie,coloana,i,j;

    citeste();

    cautare_element_liber(&linie,&coloana);

    scriere(linie, coloana);

    return 0;
}
