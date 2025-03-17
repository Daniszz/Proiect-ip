#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "functii.h"
#include "structuri.h"
#include "f_interfata.h"

using namespace std;

char *fname[] = {"GOTHIC_font", "SCRIPT font", "SIMPLEX font", "TRIPLEX SCRIPT font", "COMPLEX font", "EUROPEAN font", "BOLD font"};

int main()
{
    ///interfata

    int width=GetSystemMetrics(SM_CXSCREEN);
    int height=GetSystemMetrics(SM_CYSCREEN);
    initwindow(width+6, height+6, "", -3, -3);

    meniu();
    int comanda,buton;

   do{
    buton = butonAles();
        if (buton!=0)
            {
                comanda=buton;
                switch(comanda)
                {
                case 1:
                    closegraph();
                    pagPrin();
                    break;
                case 2:

                    break;
                case 3:
                    pagInfo();
                    break;
                case 4:
                    readText();
                    break;
                case 5:

                    break;
                case 6:
                    closegraph();
                    pagPrin();
                    break;
                case 7:
                    closegraph();
                    meniu();
                    break;

                case 8:
if(inceput2>1)
{
inceput2--;
if(t2==1)
    tabel4();
else
    tabel2();

}
else
{inceput2=0;
t1=0;
if(t2==1)
    tabel3();
else
    tabel1();
}
                    break;
                case 9:
if(inceput2+capat<nrCuv)
{
    t1=1;
inceput2++;
if(t2==1)
    tabel4();
else
tabel2();}

break;
                    break;
                case 10:
                    closegraph();
                    meniu();
                    break;
                case 11:

if(inceput>0)
{inceput--;
if(t1==1)
    tabel4();
else
tabel3();}
    else
    {
        t2=0;
    inceput=-1;
    if(t1==1)
        tabel2();
    else
       tabel1();}
                    break;
                case 12:
                    if(inceput+capat2<nrCuv)
                      { t2=1;
                          inceput++;
                        if(t1==1)
                            tabel4();
                        else
                          tabel3();
                      }
                    break;
                }
            }
    }
    while (comanda!=2 && comanda!=5);
    closegraph();

    return 0;
}
