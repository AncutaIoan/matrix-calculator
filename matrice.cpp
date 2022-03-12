///custom stuff
#include "matrice.h"
#include "afisare.h"
//basic ugly stuff
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define nrciudat -99999999999
using namespace std;
//determinant

float determinant(int matrix[10][10], int n)
{

    int det = 0;
    int submatrix[10][10];
    if(n==1)
        return matrix[0][0];

    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
        }
    }
    return det;






}
/// mai vezi pe aici :(
int caltermen(int m[10][10],int lt,int ct,int n)
{
    int i,j,si=0,sj=0;
    int sm[10][10];
    for(i=0; i<n; i++)
    {
        if(i!=lt)
        {

            for(j=0; j<n; j++)
                if(j!=ct)
                {
                    sm[si][sj++]=m[i][j];

                }
            if(sj>=n-2)
            {
                si++;
                sj=0;

            }
        }
    }

///verificare in caz ca  nu o sa mearga ceva :)

    /*   for( i=0; i<n-1; i++)
       {

           for( j=0; j<n-1; j++)
               cout<<submatrix[i][j]<<' ';

                   cout<<std::endl;
       }
    */
    std::setprecision(2);
    return determinant(sm, n-1);



}
Matrice Matrice::inversastart()
{
    if(deterstart()==0)
        throw  std::string("Nu  se poate calcula !- posibila det matrice nula");

    Matrice Invs;
    Invs.n=n;
    Invs.m=n;

    int matrix[10][10];
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            matrix[i][j]=A[i][j];


    }
    float b=deterstart();
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
            Invs.A[i][j]=pow(-1,i+j)*caltermen(matrix,j,i,n)*(1/b);





    }

    cout<<Invs;
    return Invs;



}

float Matrice::deterstart()
{
    if(n!=m)
        throw  std::string("Nu  se poate calcula !");
    int cl, i, j;
    int matrix[10][10];
    cl=n;
    for (i = 0; i < cl; i++)
        for (j = 0; j < cl; j++)
            matrix[i][j]=A[i][j];
    return determinant(matrix, n);
}
/// transpusa
void Matrice::transpusa(const Matrice &ob)
{

    n=ob.m;
    m=ob.n;
    for(int i=0; i<ob.n; i++)
    {

        for(int j=0; j<ob.m; j++)
            A[j][i]=ob.A[i][j];

    }
    /*for(int i=0;i<n;i++)
    {
         for(int j=0;j<m;j++)
            cout<<A[i][j]<<' ';
            cout<<endl;

    }*/



}

//initiere prin >>
istream& operator>>(istream &input,Matrice &obj)
{
    cout<<"Introdu nr de linii si coloane : ";
    input>>obj.n>>obj.m;
    for(int i=0; i<obj.n; i++)
    {
        for(int j=0; j<obj.m; j++)
        {
            obj.A[i][j]=nrciudat;




        }




    }
    cout<<obj;

    for(int i=0; i<obj.n; i++)
    {
        for(int j=0; j<obj.m; j++)
        {
            input>>obj.A[i][j];
            system("cls");
            printf("Matricea introdusa:");
            cout<<obj;
        }




    }
    return input;

//            cout<<"matrice["<<i<<"]"<<"["<<j<<"]=";
//            input>>obj.A[i][j];
//            cout<<endl;

}
//afisare prin <<
COORD coord2 = {0, 0};
void gotoxy2 (int x, int y)
{
    coord2.X = x;
    coord2.Y = y; // X and Y are the coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord2);
}
////////////////////////////////void Matrice::afisare()
////////////////////////////////{
////////////////////////////////
////////////////////////////////
////////////////////////////////
////////////////////////////////int i,j,k=0;
//////////////////////////////////
////////////////////////////////    for(int i=0; i<n; i++)
////////////////////////////////    {
////////////////////////////////        for(int j=0; j<m; j++)
////////////////////////////////            {
////////////////////////////////
////////////////////////////////            gotoxy2(31+j+k%m+k%m-1,23+i+1);k++;
////////////////////////////////
////////////////////////////////            if(A[i][j]!=0)
////////////////////////////////            cout<<"["<<A[i][j]<<"]";
////////////////////////////////                else
////////////////////////////////                    cout<<"[0]";
////////////////////////////////            }
////////////////////////////////
////////////////////////////////printf("%s\n\n\n");
////////////////////////////////    }
////////////////////////////////}
ostream& operator<<(ostream &output,const Matrice &obj)
{


    int i,j,k=0;
//
//    for(int i=0; i<obj.n; i++)
//    {
//        for(int j=0; j<obj.m; j++)
//            {gotoxy2(31+j+2,23+i+2);
//            if(obj.A[i][j]!=0)
//            output<<obj.A[i][j]<<'\t';
//        else
//            output<<'0'<<'\t';}
//
//
//        output<<'\n';
//
//
//    }

//


    for(int i=0; i<obj.n; i++)
    {
        gotoxy2(26,22+i);
        for(int j=0; j<obj.m; j++)
        {


            if(obj.A[i][j]!=nrciudat)
            {
                if(obj.A[i][j]!=0)
                    if(obj.A[i][j]==floor(obj.A[i][j]))
                        output<<"["<<floor(obj.A[i][j])<<"]"<<'\t';
                    else if(obj.A[i][j]==ceil(obj.A[i][j]))
                        output<<"["<<ceil(obj.A[i][j])<<"]"<<'\t';
                    else
                        output<<"["<<obj.A[i][j]<<"]"<<'\t';

                else
                    output<<"[0]"<<'\t';
            }
            else
                output<<"[ ]"<<'\t';


        }
        output<<endl;


    }
//             for (i=0; i<obj.n; i++)
// {
//
//                for(j=0;j<obj.m;j++)
//                    {gotoxy2(31+j+2,23+i+2);
//                   printf("%d",obj.A[i][j]);
//
//
//
//                    }
//                  printf("%s\n\n\n");
//}

}




//inmultirea a doua matrici

operator*(const Matrice &obj,const Matrice &obie)
{
    Matrice C;
    if(obj.m!=obie.n)
    {
        cout<<"Acesta inmultire nu este valabila !! " ;
        return 0;
    }

    int d=0,f=0,k=0;

    int ok=1;
    int s;

    // o jum de ora pt asta sa fie <3, iubirea invingeeeeeeeeeeeeeeeeeeeeeeee
    for(int i=0; i<obj.n; i++)
    {
        k=0;
        while(k<obie.m)
        {
            s=0;
            for(int j=0; j<obj.m; j++)
            {


                /* cout<<i<<' '<<j<<' '<<j<<'-'<<k<<'\n';
                 */s+=obj.A[i][j]*obie.A[j][k];



            }/*
            cout<<endl;
            cout<<s;
            cout<<endl;*/
            C.A[i][k]=s;
            k++;

        }
    }
    C.m=obie.m;
    C.n=obj.n;
    cout<<C;
}
operator+(const Matrice &obj,const Matrice &obie)
{

    if(obj.n!=obie.n || obj.m!=obie.m)
    {

        cout<<"Nu se poate efectua, apasa Enter pt a continua";
        return 0;

    }
    Matrice Rez;
    Rez.n=obj.n;
    Rez.m=obj.m;
    int i,j;
    for(i=0;i<obj.n;i++)
        for(j=0;j<obj.m;j++)
    {
        Rez.A[i][j]=obj.A[i][j]+obie.A[i][j];

    }

cout<<Rez;

}operator-(const Matrice &obj,const Matrice &obie)
{

    if(obj.n!=obie.n || obj.m!=obie.m)
    {

        cout<<"Nu se poate efectua, apasa Enter pt a continua";
        return 0;

    }
    Matrice Rez;
    Rez.n=obj.n;
    Rez.m=obj.m;
    int i,j;
    for(i=0;i<obj.n;i++)
        for(j=0;j<obj.m;j++)
    {
        Rez.A[i][j]=obj.A[i][j]-obie.A[i][j];

    }

cout<<Rez;

}
