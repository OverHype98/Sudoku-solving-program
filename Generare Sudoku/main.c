#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sudoku[9][9],aparitii_linii[9][9],aparitii_coloane[9][9];   //aparitii linii si aparitii coloane  vor fi completate cu 1 pe linia 0 si coloana valorii cand  vom pune un element nou
FILE *g;
void generare_pozitii(int nr_patratului)
{

    int nr_de_pozitii,iterator,pozitie,valoare,linie,coloana,nlinie,ncoloana,linceput,cinceput,ok,i,j;

    nr_de_pozitii=rand()%4+2;
    for(iterator=1; iterator<=nr_de_pozitii; iterator++)
    {
            pozitie = rand()%8+1;
            linie=pozitie/3+1;
            coloana=pozitie%3+1;
            linceput=(nr_patratului/3)*3+1;//linceput contine linia de inceput a matricei sudoku
            cinceput=(nr_patratului%3)*3+1;//cinceput contine coloana de inceput a matricei sudoku
            nlinie=linceput+linie-1;
            ncoloana=cinceput+coloana-1;
            //int tt=0;
            do
            {
                    ok=1;
                    valoare=rand()%9+1;
                    if(aparitii_linii[nlinie][valoare]!=0)
                    {
                            ok=0;
                    }
                    else if(aparitii_linii[0][valoare]!=0)
                    {
                            ok=0;
                    }
                    else if(aparitii_coloane[valoare][ncoloana]!=0)
                    {
                            ok=0;
                    }
                    // if (tt>100000) break;
            }
            while(ok==0);
        //if (ok==1)
        //{
        aparitii_linii[nlinie][valoare]=1;
        aparitii_coloane[valoare][ncoloana]=1;
        aparitii_linii[0][valoare]=1;
        sudoku[nlinie][ncoloana]=valoare;
        //}
    }
}

int main()
{
        g=fopen("sudoku.out","w");
        time_t t;
        int i,j,p;
        srand((unsigned) time(&t));
        for(p=0; p<=8; p++)
        {
                for(i=0; i<=9; i++)
                aparitii_linii[0][i]=0;
                generare_pozitii(p);
        }

        for(i=1; i<=9; i++)
        {
                for(j=1; j<=9; j++)
                fprintf(g,"%d ",sudoku[i][j]);
                fprintf(g,"\n");
        }
        return 0;
}
