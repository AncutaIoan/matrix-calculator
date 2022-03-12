//#include <iostream>
#include "matrice.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

using namespace std;
Matrice A,B,C,I,T;
int cont=1;
COORD coord = {0, 0};
void ClearConsoleInputBuffer()
{
    // If you happen to have any trouble clearing already cleared buffer, uncomment the section below.
    /* keybd_event('S', 0, 0, 0);
    keybd_event('S', 0,KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0, 0, 0);
    keybd_event(VK_BACK, 0,KEYEVENTF_KEYUP, 0); */
    PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[256];
    DWORD ClearingVar2;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),ClearingVar1,256,&ClearingVar2);
    delete[] ClearingVar1;
}
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y are the coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void window(int a,int b,int c,int d)
{

    int i;
    system("cls");
    gotoxy(20,10);
//textcolor(1);
    for (i=1; i<=10; i++)
        printf("*");
    printf(" * LUCRU CU MATRICE * ");
    for (i=1; i<=10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30,11);
    printf("Ancuta Ioan");
//textcolor(4);
    for (i=a; i<=b; i++)
    {
        gotoxy(i,17);
        printf("\xcd");
        gotoxy(i,19);
        printf("\xcd");
        gotoxy(i,c);
        printf("\xcd");
        gotoxy(i,d);
        printf("\xcd");
    }

    gotoxy(a,17);
    printf("\xc9");
    gotoxy(a,18);
    printf("\xba");
    gotoxy(a,19);
    printf("\xc8");
    gotoxy(b,17);
    printf("\xbb");
    gotoxy(b,18);
    printf("\xba");
    gotoxy(b,19);
    printf("\xbc");
//textcolor(4);
    for(i=c; i<=d; i++)
    {
        gotoxy(a,i);
        printf("\xba");
        gotoxy(b,i);
        printf("\xba");
    }
    gotoxy(a,c);
    printf("\xc9");
    gotoxy(a,d);
    printf("\xc8");
    gotoxy(b,c);
    printf("\xbb");
    gotoxy(b,d);
    printf("\xbc");
//textbackground(11);
//textcolor(0);
}
void sleep(int ms)
{

    clock_t time_end;
    time_end = clock() + ms * CLOCKS_PER_SEC/1000;
    while (clock() < time_end);

}
void opt(int n)
{
    switch(n)
    {
//    case 0:
//        system("cls");
//        ClearConsoleInputBuffer();
//        cin>>A;
//        window(20,60,20,32);
//        gotoxy(30,18);
//        printf("Matricea introdusa :");
//        cout<<A;
//        gotoxy(0,0);
//        cout<<"Apasa S pt a reveni la meniul anterior";
//        break; //optional
    case 0:
        system("cls");
        ClearConsoleInputBuffer();
        cin>>A;
        window(20,60,20,32);
        gotoxy(30,18);
        printf("Rezultat:");
        cout<<A.deterstart();
        cout<<A;
        gotoxy(0,0);
        cout<<"Apasa W pt a reveni la meniul anterior";
        break;
    case 1:
        system("cls");
        ClearConsoleInputBuffer();
        cin>>A;
        window(20,60,20,32);
        gotoxy(30,18);
        printf("Rezultat:");
        T.transpusa(A);
        cout<<T;
        gotoxy(0,0);
        cout<<"Apasa W pt a reveni la meniul anterior";
        break;
    case 2:
        system("cls");
        ClearConsoleInputBuffer();
        cin>>A;
        window(20,60,20,32);
        gotoxy(30,18);
        printf("Rezultat:");
        try{
        I=A.inversastart();
        }
        catch(char s[]){
            gotoxy(0,0);
            cout<<s;

        }
        cout<<I;
        gotoxy(0,0);
        cout<<"Apasa W pt a reveni la meniul anterior";

        break;
    case 3:
        system("cls");
        ClearConsoleInputBuffer();
        cin>>A;
        ClearConsoleInputBuffer(); system("cls");
        cin>>B;
        window(20,60,20,32);
        gotoxy(30,18);
        printf("Rezultat:");
        cout<<A*B;
        gotoxy(0,0);
        cout<<"Apasa W pt a reveni la meniul anterior";
        break;
    case 4:
        system("cls");
        ClearConsoleInputBuffer();
        cin>>A;
        ClearConsoleInputBuffer(); system("cls");
        cin>>B;
        window(20,60,20,32);
        gotoxy(30,18);
        printf("Rezultat:");
        cout<<A+B;
        gotoxy(0,0);
        cout<<"Apasa W pt a reveni la meniul anterior";
        break;

    case 5:
         system("cls");
        ClearConsoleInputBuffer();
        cin>>A;
        ClearConsoleInputBuffer(); system("cls");
        cin>>B;
        window(20,60,20,32);
        gotoxy(30,18);
        printf("Rezultat:");
        cout<<A-B;
        gotoxy(0,0);
        cout<<"Apasa W pt a reveni la meniul anterior";
        break;
    case 6:
        cont=0;
        break;

    }

}

int main()
{



    int i,j;
    char menu[][100]= {"  >Calculeaza det","   Transpusa","   Inversa","   Inmultire  ","   Adunare", "   Scadere","   Exit"};

//textbackground(13);
//textcolor(0);
//_setcursortype(_NOCURSOR);
    int sx=0,sy=2;
    system("cls");
    window(20,60,20,32);
    gotoxy(33,18);
    printf("MAIN MENU");
    for (i=0; i<=6; i++)
    {
        gotoxy(30,22+i+1);
        printf("%s\n\n\n",menu[i]);
    }

    while(cont)
    {
        if(GetAsyncKeyState('S') & 0x8000 && sx<6)
        {
            swap(menu[sx][sy],menu[sx+1][sy] );
            sx++;
            window(20,60,20,32);
            gotoxy(33,18);
            printf("MAIN MENU");
            for (i=0; i<=6; i++)
            {
                gotoxy(30,22+i+1);
                printf("%s\n\n\n",menu[i]);
            }
            sleep(100);

        }
        if(GetAsyncKeyState('W') & 0x8000 && sx>0)
        {
            swap(menu[sx][sy],menu[sx-1][sy]);
            sx--;
            window(20,60,20,32);
            gotoxy(33,18);
            printf("MAIN MENU");
            for (i=0; i<=6; i++)
            {
                gotoxy(30,22+i+1);
                printf("%s\n\n\n",menu[i]);

            }
            sleep(100);


        }
        if(GetAsyncKeyState('O') & 0x8000)
            opt(sx);




    }
    return 0;
}

//#include <string>
//using namespace std;
///// Apelezi obiecte_matrice_nume.deterstart pt calcul determinant
///// Apelezi obiect_matrice_nume.inversastart pt inversa
///// citesti matricea cu cin>>obiect_matrice_nume
///// afisezi matrice cu cout<<..
///// Pt transpusa obiect_nume_matrice.Transpusa(obiect de start);
///// Adunarea+scaderea le faci tu pt ca sunt sb
///// si cam atat have fun ^-^
///// ++++ try and catch, throw sunt in caz de exceptii alea le punea ea in program final
/////
/////
/////
//
//int main()
//{ Matrice A,B;
//
//cout<<"Introdu prima matrice pt inmultire : \n";
//cin>>A;
/////pt a face det test :
//
///*cout<<A.determinant();
//*/
//cout<<"Matricea transpusa pt A: \n";
//B.transpusa(A);
//
//
/////pt a face inmultirea test :*
///*cout<<"Introdu a doua matrice pt inmultire : \n";
//cin>>B;
//cout<<A*B;
//*/
///// calc det numeobiectclasamatrice.deterstart();
////try{
////cout<<B;
////cout<<B.deterstart();
////}
////catch(std::string e)
////{
////    std::cout<<e<<std::endl;
////}
//cout<<A.inversastart();
//
//
//    return 0;
//}
