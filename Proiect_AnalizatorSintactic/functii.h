#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#include "structuri.h"
#include "f_interfata.h"

bool esteIn(char x[20],multime M)
{
    int i;
    bool este=0;
    for( i=1; i<=M.nrElem; i++)
        if(strcmp(M.element[M.nrElem],x)==0)
            este=1;
    return este;
}
void citire_propozitie(char c[],char PROPOZITIE[20][50],int &nrCuv)
{

    char *p;
    p=strtok(c," ");
    while(p)
    {
        nrCuv++;
        strcpy(PROPOZITIE[nrCuv],p);
        p=strtok(NULL," ");
    }
}
tip_regula citire_reg(tip_regula regula[100],int &nrReguli)
{
    nrReguli=0;
    int k;
    char c[100],*p1,*p2;
    FILE *citire;
    citire=fopen("lex.txt","r");
    while(fgets(c,100,citire))
    {
        if(c[strlen(c)-1]=='\n')
            c[strlen(c)-1]=NULL;
        nrReguli++;
        p1=strtok(c,"->");
        k=0;
        while(p1)
        {
            if(k==0)
            {
                strcpy(regula[nrReguli].st,p1);
                k=1;
            }
            else
                strcpy(regula[nrReguli].dr1,p1);
            p1=strtok(NULL,"->");
        }
    }
    fclose(citire);
    citire=fopen("gram.txt","r");
    while(fgets(c,100,citire))
    {
        if(c[strlen(c)-1]=='\n')
            c[strlen(c)-1]=NULL;

        nrReguli++;
        p1=strtok(c,"->  ");
        k=0;
        while(p1)
        {
            if(k==2)
                strcpy(regula[nrReguli].dr2,p1);
            if(k==1)
            {
                strcpy(regula[nrReguli].dr1,p1);
                k=2;
            }
            if(k==0)
            {
                strcpy(regula[nrReguli].st,p1);
                k=1;
            }
            p1=strtok(NULL,"->  ");
        }
    }
    return regula[100];
}

void Star(multime X, multime Y, multime &S)
{
    int i,j,k;
S.nrElem=0;
    for( i=1; i<=X.nrElem; i++)
    {
        for(j=1; j<=Y.nrElem; j++)
        {
            for( k=1; k<=nrReguli; k++)
                if(strcmp(X.element[i],regula[k].dr1)==NULL)
                    if(strcmp(Y.element[j],regula[k].dr2)==NULL)
                    {
                        S.nrElem++;
                        strcpy(S.element[S.nrElem],regula[k].st);

                    }
        }
    }

}

void closure(multime S, multime &C)
{
    int i,j;
    bool ok;
    C=S;
    do
    {
        ok=1;
        for(i=1; i<=nrReguli; i++)
        {

            if(strlen(regula[i].dr2)==0)
                if(esteIn(regula[i].dr1,C)==1)
                    if(esteIn(regula[i].st,C)==0)
                    {

                        C.nrElem++;
                        strcpy(C.element[C.nrElem],regula[i].st);
                        ok=0;
                    }
        }
    }
    while(!ok);
}

void Lookup(int k, multime &L)
{

    L.nrElem=0;
    int i;
    for(i=1; i<=nrReguli; i++)
        if(strcmp(regula[i].dr1,PROPOZITIE[k])==NULL)
        {
            L.nrElem++;
            strcpy(L.element[L.nrElem],regula[i].st);

        }

}

void aplicare_teorie()
{
    citire_reg(regula,nrReguli);
    int i,j,k,kk;
    citire_propozitie(d,PROPOZITIE,nrCuv);
    multime L;
    multime C;
    multime S;

for( k=1; k<=nrCuv; k++)
    {
        Lookup(k,L);
        closure(L,C);
        chart[k-1][k]=C;
        for(i=k-2; i>=0; i--)
        {
            chart[i][k].nrElem=0;
            for( j=k-1; j>=i+1; j--)
            {
                Star(chart[i][j],chart[j][k],S);
                for( kk=1; kk<=S.nrElem; kk++)
                {
                    if(esteIn(S.element[kk],chart[i][k])==0)
                    {
                        chart[i][k].nrElem++;
                        strcpy(chart[i][k].element[chart[i][k].nrElem],S.element[kk]);
                    }
                }
            }
            closure(chart[i][k],C);
            chart[i][k]=C;
        }}

    }

void valid()
{
  bar(820,80,getmaxx()-50,120);
  rectangle(820,80,getmaxx()-50,120);
    setcolor(GREEN);
  outtextxy(830,95,"PROPOZITIE ACCEPTATA");
   setcolor(BLACK);
  buton_restart();
}
void invalid()
{
  bar(820,80,getmaxx()-50,120);
  rectangle(820,80,getmaxx()-50,120);
   setcolor(RED);
  outtextxy(830,95,"PROPOZITIE GRESITA");
   setcolor(BLACK);
  buton_restart();

}

    void readText()
{

  setcolor(WHITE);
    bar(50,80,800,120);
    setcolor(BLACK);
    rectangle(50,80,800,120);
    char ch,b[2],a[2],poz[100];
    int pl=-1,k=0;
    float j=60,y=60;

    while (1)
    {
        if (kbhit() )
        {
            ch = getch();
            b[0]=ch;
            b[1]='\0';
            if(int(ch)==8)
            {
                if(j>=60)
                {
                    if(k>0)
                    {
                        setcolor(WHITE);
                        bar(50,80,800,120);
                        setcolor(BLACK);
                        rectangle(50,80,800,120);
                        k--;
                        y=60;
                        for(int i=k; d[i]!=NULL; i++)
                        {
                            a[0]=d[i];
                            a[1]='\0';
                            outtextxy(y,100,a);
                            y=y+textwidth(a)+1;
                        }

                       a[0]=d[k];
                    a[1]='\0';
                    j=j+textwidth(a)+1;
                    }
                    setfillstyle(SOLID_FILL,WHITE);
                    a[0]=d[pl];
                    a[1]='\0';
                    rectangle(j-textwidth(a),100+textheight(a),j,100);
                    floodfill(j-textwidth(a),100+textheight(a),WHITE);
                    j=j-textwidth(a)-1;
                    pl--;
                    d[strlen(d)-1]=NULL;
                }
            }
            else
            {
                if(j>=760)
                {
                    k++;
                    setcolor(WHITE);
                    bar(50,80,800,120);
                    setcolor(BLACK);
                    rectangle(50,80,800,120);
                    y=60;
                    for(int i=k; d[i]!=NULL; i++)
                    {
                        a[0]=d[i];
                        a[1]='\0';
                        outtextxy(y,100,a);
                        y=y+textwidth(a)+1;
                    }
                    a[0]=d[k];
                    a[1]='\0';
                    j=y;
                }
                setcolor(BLACK);
                setbkcolor(WHITE);
                outtextxy(j,100,b);
                floodfill(j,100,BLACK);
                j=j+textwidth(b)+1;
                strcat(d,b);
                pl++;
            }


            if (int(ch)== 13)
            {

                d[strlen(d)-1]=NULL;
                aplicare_teorie();
                if(esteIn("S",chart[0][nrCuv]))
                    valid();
                else
                    invalid();
                tabel1();
                    break;

            }

        }
    }

}


#endif // FUNCTII_H_INCLUDED
