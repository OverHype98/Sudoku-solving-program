#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

FILE *f,*g;

int a[100][100];

void citeste()
{

    int i,j;
    for(i=1; i<=9; i++)
        for(j=1; j<=9; j++)
            fscanf(f,"%d",&a[i][j]);

}

void cautare_element_liber(int *linie,int *coloana)
{

    *linie=0;
    *coloana=0;
    int i,j,ok=0;
    for(i=1;i<=9 && ok==0;i++)
        for(j=1;j<=9&& ok==0;j++)
        if(a[i][j] == 0 )
        {
        *linie = i;
        *coloana=j;
        ok=1;
        }
}

int exista(int linie,int coloana,int k)
{
        int i,j,clinie,rlinie,plinie,l,c,p;
        for(i=1;i<=9;i++)
                if(k==a[i][coloana] || a[linie][i]==k )
                        return 0;

  if(linie>=1 && linie<=3)
        l=1;
    else if(linie>=4 && linie<=6)
        l=4;
    else l=7;

    if(coloana>=1 && coloana<=3)
        c=1;
    else if(coloana>=4 && coloana<=6)
        c=4;
    else
        c=7;

   p=0;
   for (i=l;i<=l+2;i++)
    for(j=c;j<=c+2;j++)
     if (a[i][j]==k)
        p++;
   if (p>0)  return 0;
   return 1;

}



void afisare()
{
    int i,j;
    for (i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
              fprintf(g,"%d ",a[i][j]);
            fprintf(g,"\n");
        }

}

void scriere(int linie,int coloana)
{
    int k,i,j;
    if (linie!=0 && coloana!=0)
        for(k=1;k<=9;k++)
        {
            if(exista(linie,coloana,k)!= 0)
            {
                a[linie][coloana]=k;
                cautare_element_liber(&i,&j);
                if (i!=0 && j!=0)
                    {scriere(i, j);
                    a[i][j]=0;}
                     else
                        {afisare();break;}
            }
        }

}

