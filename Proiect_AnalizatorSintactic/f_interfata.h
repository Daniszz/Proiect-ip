#ifndef F_INTERFATA_H_INCLUDED
#define F_INTERFATA_H_INCLUDED

#include "structuri.h"
#include "functii.h"

int aight=0;
int nrButoaneM = 3;
int nrButoane = 13; ///5 daca merge infobuton
   bool apartine(punct P, dreptunghi D)
{
    if(D.ss.x<=P.x && P.x<=D.dj.x && D.ss.y<=P.y && P.y<=D.dj.y)
        return 1;
    return 0;
}

void clean_coord()
{
    for(int i=0;i<nrButoane;i++)
    {
        B[i].D.ss.x = 0;
        B[i].D.ss.y = 0;
        B[i].D.dj.x = 0;
        B[i].D.dj.y = 0;

    }

}

void sageti_st_dr()
{
    setcolor(BLACK);
    rectangle(50,getmaxy()-60,110,getmaxy()-30);
    rectangle(getmaxx()-110,getmaxy()-60,getmaxx()-50,getmaxy()-30);
    setcolor(WHITE);
    floodfill(51,getmaxy()-49,BLACK);
    floodfill(getmaxx()-109,getmaxy()-59,BLACK);
    setcolor(BLACK);
    line(60,getmaxy()-45,100,getmaxy()-45);
    line(60,getmaxy()-45,80,getmaxy()-40);
    line(60,getmaxy()-45,80,getmaxy()-50);
    line(getmaxx()-100,getmaxy()-45,getmaxx()-60,getmaxy()-45);
    line(getmaxx()-60,getmaxy()-45,getmaxx()-80,getmaxy()-40);
    line(getmaxx()-60,getmaxy()-45,getmaxx()-80,getmaxy()-50);

}
void sageti_sus_jos()
{
    setcolor(BLACK);
    rectangle(getmaxx()-40,150,getmaxx()-10,210);
    rectangle(getmaxx()-40,getmaxy()-129,getmaxx()-10,getmaxy()-69);
    setcolor(WHITE);
    floodfill(getmaxx()-39,151,BLACK);
    floodfill(getmaxx()-39,getmaxy()-128,BLACK);
    setcolor(BLACK);
    line(getmaxx()-25,160,getmaxx()-25,200);
    line(getmaxx()-25,160,getmaxx()-20,180);
    line(getmaxx()-25,160,getmaxx()-30,180);
    line(getmaxx()-25,getmaxy()-119,getmaxx()-25,getmaxy()-79);
    line(getmaxx()-25,getmaxy()-79,getmaxx()-30,getmaxy()-99);
    line(getmaxx()-25,getmaxy()-79,getmaxx()-20,getmaxy()-99);
}
void buton_exit()
{
    setcolor(BLACK);
    rectangle(getmaxx()-30,5,getmaxx()-10,30);
    setcolor(WHITE);
    floodfill(getmaxx()-29,6,BLACK);
    setcolor(BLACK);
    line(getmaxx()-30,5,getmaxx()-10,30);
    line(getmaxx()-30,30,getmaxx()-10,5);
}

void buton_back()
{
    bar(getmaxx()-80,5,getmaxx()-40,30);
    rectangle(getmaxx()-80,5,getmaxx()-40,30);
    setcolor(BLACK);
    setbkcolor(WHITE);
    outtextxy(getmaxx()-75,10,"Back");
    setcolor(WHITE);
    floodfill(getmaxx()-79,6,BLACK);
    setcolor(BLACK);
}

void coordonate_pgP()
{
    ///CadruText
        B[3].D.ss.x = 50;
        B[3].D.ss.y = 80;
        B[3].D.dj.x = 800;
        B[3].D.dj.y = 130;

    ///ExitButon
        B[4].D.ss.x = getmaxx()-30;
        B[4].D.ss.y = 5;
        B[4].D.dj.x = getmaxx()-10;
        B[4].D.dj.y = 30;

   ///BackButon
        B[6].D.ss.x = getmaxx()-80;
        B[6].D.ss.y = 5;
        B[6].D.dj.x = getmaxx()-40;
        B[6].D.dj.y = 30;

    ///Sageti
     ///50,getmaxy()-90,110,getmaxy()-60
        B[7].D.ss.x = 50;
        B[7].D.ss.y = getmaxy()-60;
        B[7].D.dj.x = 110;
        B[7].D.dj.y = getmaxy()-30;

        ///getmaxx()-110,getmaxy()-90,getmaxx()-50,getmaxy()-60
        B[8].D.ss.x = getmaxx()-110;
        B[8].D.ss.y = getmaxy()-60;
        B[8].D.dj.x = getmaxx()-50;
        B[8].D.dj.y = getmaxy()-30;


        ///rectangle(getmaxx()-40,150,getmaxx()-10,210);
        B[10].D.ss.x = getmaxx()-40;
        B[10].D.ss.y = 150;
        B[10].D.dj.x = getmaxx()-10;
        B[10].D.dj.y = 210;


        ///rectangle(getmaxx()-40,getmaxy()-129,getmaxx()-10,getmaxy()-69);
        B[11].D.ss.x = getmaxx()-30;
        B[11].D.ss.y = getmaxy()-129;
        B[11].D.dj.x = getmaxx()-10;
        B[11].D.dj.y = getmaxy()-69;
}

void pagPrin()
{
if(aight>=1)
{chart[11][11]={NULL};
PROPOZITIE[20][50]={NULL};
nrCuv=0;
d[0]=NULL;} //reset tabel

    int width=GetSystemMetrics(SM_CXSCREEN);
    int height=GetSystemMetrics(SM_CYSCREEN);
    initwindow(width+6, height+6, "", -3, -3);
    setbkcolor(COLOR(247,180,180));
    cleardevice();

    clean_coord();
    coordonate_pgP();

    setcolor(BLACK);
    rectangle(50,80,800,120);
    setcolor(BLACK);
    outtextxy(54,100,"Aici se introduce textul de parsat");
    setcolor(WHITE);
    floodfill(799,119,BLACK);
    setcolor(WHITE);
    outtextxy(820,100,"Rezultatul analizei sintactice si lexicale va fi afisat aici.");
    buton_exit();
    buton_back();
    aight++;

}

void coordonate_pgI()
{
     ///ExitButon
        B[4].D.ss.x = getmaxx()-30;
        B[4].D.ss.y = 5;
        B[4].D.dj.x = getmaxx()-10;
        B[4].D.dj.y = 30;

    ///InapoiButon
        B[9].D.ss.x = 40;
        B[9].D.ss.y = 15;
        B[9].D.dj.x = 100;
        B[9].D.dj.y = 40;
}


void defaultText()
{
    settextjustify(RIGHT_TEXT , CENTER_TEXT);
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT , HORIZ_DIR ,1);
}

void titluText()
{
    setcolor(COLOR(247,180,180));
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    settextjustify(CENTER_TEXT,CENTER_TEXT);

}

void tabel1()
{

  setcolor(WHITE);
  bar(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(BLACK);
   rectangle(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(WHITE);
   floodfill(51,151,BLACK);
   setcolor(BLACK);
   int x1,x2,y1,y2;

   char aux[3],nj[100];
   int w=144;
   if(nrCuv>9)
    {capat=9;
    sageti_st_dr();}
   else
    capat=nrCuv;
    if(nrCuv>12)
    {
        sageti_sus_jos();

        capat2=12;

    }
    else capat2=nrCuv;
   x1=50;
          x2=x1+w;
          y1=150;
          y2=y1+50;

settextjustify(CENTER_TEXT,TOP_TEXT);
  for(int i=0;i<=capat;i++)
  {
      rectangle(x1,y1,x2,y2);
      if(i!=0)
      {
         outtextxy(x1+w/2,y1+10,PROPOZITIE[i]);
      }
      x1=x2;
      x2=x1+w;
  }

for(int i=0;i<capat2;i++)
{
    y1=y2;
     y2=y1+50;
     x1=50;
     x2=x1+w;
      if(i>9)
      {
          aux[0]=i/10+'0';
          aux[1]=i%10+'0';
      aux[2]=NULL;
      }
      else
      {
          aux[0]=i%10+'0';
          aux[1]=NULL;
      }

    rectangle(x1,y1,x2,y2);
    outtextxy(x1+w/2,y1+10,aux);

    x1=x2;
    x2=x1+w;
    for(int j=1;j<=capat;j++)
    {
        nj[0]=NULL;
      rectangle(x1,y1,x2,y2);
      for(int l=1;l<=chart[i][j].nrElem;l++)
      {
          strcat(nj,chart[i][j].element[l]);
          strcat(nj,",");
      }
      nj[strlen(nj)-1]=NULL;
      outtextxy(x1+w/2,y1+10,nj);
      x1=x2;
      x2=x1+w;
    }
}

}
void tabel2()
{
 setcolor(WHITE);
  bar(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(BLACK);
   rectangle(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(WHITE);
   floodfill(51,151,BLACK);
   setcolor(BLACK);


   int x1,x2,y1,y2;

   char aux[3],nj[100];
   int w=144;
sageti_st_dr();
   x1=50;
          x2=x1+w;
          y1=150;
          y2=y1+50;

settextjustify(CENTER_TEXT,TOP_TEXT);

  for(int i=inceput2;i<=capat+inceput2;i++)
  {
      rectangle(x1,y1,x2,y2);
      if(i!=0)
      {
         outtextxy(x1+w/2,y1+10,PROPOZITIE[i]);
      }
      x1=x2;
      x2=x1+w;
  }

for(int i=0;i<capat2;i++)
{
    y1=y2;
     y2=y1+50;
     x1=50;
     x2=x1+w;

    for(int j=inceput2;j<=capat+inceput2;j++)
    {
        nj[0]=NULL;
      rectangle(x1,y1,x2,y2);
      for(int l=1;l<=chart[i][j].nrElem;l++)
      {
          strcat(nj,chart[i][j].element[l]);
          strcat(nj,",");
      }
      nj[strlen(nj)-1]=NULL;
      outtextxy(x1+w/2,y1+10,nj);
      x1=x2;
      x2=x1+w;
    }
}

}
void tabel3()
{
 setcolor(WHITE);
  bar(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(BLACK);
   rectangle(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(WHITE);
   floodfill(51,151,BLACK);
   setcolor(BLACK);


   int x1,x2,y1,y2;

   char aux[3],nj[100];
   int w=144;
sageti_st_dr();
   x1=50;
          x2=x1+w;
          y1=150;
          y2=y1+50;

settextjustify(CENTER_TEXT,TOP_TEXT);


for(int i=inceput;i<=capat2+inceput;i++)
{

     x1=50;
     x2=x1+w;
 if(i>9)
      {
          aux[0]=i/10+'0';
          aux[1]=i%10+'0';
      aux[2]=NULL;
      }
      else
      {
          aux[0]=i%10+'0';
          aux[1]=NULL;
      }
      rectangle(x1,y1,x2,y2);
    outtextxy(x1+w/2,y1+10,aux);

    x1=x2;
    x2=x1+w;
    for(int j=1;j<=capat;j++)
    {
        nj[0]=NULL;
      rectangle(x1,y1,x2,y2);
      for(int l=1;l<=chart[i][j].nrElem;l++)
      {
          strcat(nj,chart[i][j].element[l]);
          strcat(nj,",");
      }
      nj[strlen(nj)-1]=NULL;
      outtextxy(x1+w/2,y1+10,nj);
      x1=x2;
      x2=x1+w;
    }
y1=y2;
     y2=y1+50;
}

}
void tabel4()
{
 setcolor(WHITE);
  bar(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(BLACK);
   rectangle(50,150,getmaxx()-50,getmaxy()-69);
   setcolor(WHITE);
   floodfill(51,151,BLACK);
   setcolor(BLACK);


   int x1,x2,y1,y2;

   char aux[3],nj[100];
   int w=144;
sageti_st_dr();
   x1=50;
          x2=x1+w;
          y1=150;
          y2=y1+50;

settextjustify(CENTER_TEXT,TOP_TEXT);


for(int i=inceput;i<=capat2+inceput;i++)
{

     x1=50;
     x2=x1+w;

    for(int j=inceput2;j<=capat+inceput2;j++)
    {
        nj[0]=NULL;
      rectangle(x1,y1,x2,y2);
      for(int l=1;l<=chart[i][j].nrElem;l++)
      {
          strcat(nj,chart[i][j].element[l]);
          strcat(nj,",");
      }
      nj[strlen(nj)-1]=NULL;
      outtextxy(x1+w/2,y1+10,nj);
      x1=x2;
      x2=x1+w;
    }
y1=y2;
     y2=y1+50;
}

}
void coordonate()
{

 ///Restart
        B[5].D.ss.x = getmaxx()-145;
        B[5].D.ss.y = 5;
        B[5].D.dj.x = getmaxx()-90;
        B[5].D.dj.y = 30;
}

void buton_restart()
{
        bar(getmaxx()-145,5,getmaxx()-90,30);
        rectangle(getmaxx()-145,5,getmaxx()-90,30);
        setcolor(RED);
        outtextxy(getmaxx()-141,10,"Restart");
        setcolor(BLACK);


    coordonate();
}

 void buton_inapoi()
{
        setcolor(WHITE);
        rectangle(40,15,100,40);
        setcolor(BLUE);
        outtextxy(50,20,"Inapoi");
        setcolor(BLACK);
}

void sectiune_reguli()
{
    setcolor(WHITE);
    rectangle(40,85,getmaxx()/2-300,getmaxy()-50);

    FILE *fisier1;
    char linie[100];
    int h=100;
    fisier1 = fopen("rules.txt","r");
    setcolor(BLUE);

    while(!feof(fisier1))
    {
            if(!fgets(linie,50,fisier1))
                break;
            outtextxy(55,h,linie);
            h+=textheight(linie)+2;
    }

    fclose(fisier1);
}

void sectiune_dict()
{
    setcolor(WHITE);
    rectangle(getmaxx()/2-290,85,getmaxx()-40,getmaxy()-50);

    FILE *fisier2;

    char linie[100];
    int h=100;
    int l=getmaxx()/2-280;
    int ok=0;
    char *p;
    char cuv[20];
    fisier2 = fopen("lex.txt","r");
    setcolor(BLUE);

    while(!feof(fisier2))
    {
        if(!fgets(linie,50,fisier2))
            break;

            p=strstr(linie,">");
            if(p==NULL)
                break;

            strcpy(cuv,p+1);
            //strtok(linie,">");
            //p=strtok(NULL,"\n");
            //strcpy(cuv,p);
        outtextxy(l,h,cuv);
        h+=textheight(cuv)+2;
        ok++;
        if(ok==39)
        {
            h=100;
            l+=textwidth(cuv)+50;
            ok=0;
        }

    }

    fclose(fisier2);
}

int butonAles()
{
    int i;
    punct p;

    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();

        for (i=1; i<= nrButoane; i++)
            if (apartine(p,B[i-1].D))
                return i;
    }
    return 0;
}

void meniu()
{
    int width=GetSystemMetrics(SM_CXSCREEN);
    int height=GetSystemMetrics(SM_CYSCREEN);
    initwindow(width+6, height+6, "", -3, -3);
    ///TITLU, OUTLINE, FUNDAL

    clean_coord();

    setcolor(COLOR(247,180,180));
    cleardevice();

    for(int i=1;i<=5;i++)
    rectangle(i,i,getmaxx()-i,getmaxy()-i);

    setfillstyle(SOLID_FILL,BLACK);
    bar(3,3,getmaxx()-3,getmaxy()-3);

    punct titlu;
    titlu.x=getmaxx()/2;
    titlu.y=getmaxy()/4;

    titluText();
    outtextxy(titlu.x , titlu.y, "ANALIZATOR SINTACTIC");


    ///SUBSOL
        titluText();
        int size=1;
        punct jos;
        jos.x = getmaxx()/2;
        jos.y = getmaxy()-10;
        int style = SIMPLEX_FONT;
        setcolor(COLOR(255,230,230));
        settextstyle(style,HORIZ_DIR,size);
        outtextxy(jos.x , jos.y , "");
    ///BUTOANE
    size = 2;
    style = GOTHIC_FONT;
    settextstyle(style, HORIZ_DIR, size);

    int i;
    for(i = 0 ;i < nrButoaneM; i++)
    {
        B[i].D.ss.x = getmaxx()/2-70;
        B[i].D.ss.y = getmaxx()/3+(i)*100-130;
        B[i].D.dj.x = B[i].D.ss.x+140;
        B[i].D.dj.y = B[i].D.ss.y+70;

        switch(i)
        {
        case 0:
            strcpy(B[i].text,"START");
            break;
        case 1:
            strcpy(B[i].text,"IESIRE");
            break;
        case 2:
            strcpy(B[i].text,"INFO");
        }

        setfillstyle(SOLID_FILL,COLOR(247,180,180));
        setcolor(COLOR(247,180,180));

        if(i==2)
            setcolor(COLOR(104,156,179)),setfillstyle(SOLID_FILL,COLOR(104,156,179));

        rectangle(B[i].D.ss.x , B[i].D.ss.y , B[i].D.dj.x , B[i].D.dj.y);
        bar(B[i].D.ss.x, B[i].D.ss.y, B[i].D.dj.x, B[i].D.dj.y);
        outtextxy(B[i].D.ss.x+70,B[i].D.ss.y+40,B[i].text);
    }

}
 void pagInfo()
{

    int width=GetSystemMetrics(SM_CXSCREEN);
    int height=GetSystemMetrics(SM_CYSCREEN);
    initwindow(width+6, height+6, "", -3, -3);
    setbkcolor(COLOR(104, 156, 179)); //COLOR(247,180,180)
    cleardevice();

    clean_coord(); //sterge coordonatele butoanelor
    coordonate_pgI();
     buton_inapoi();
     sectiune_reguli();
     sectiune_dict();
     settextstyle(BOLD_FONT,HORIZ_DIR,2);
     setcolor(BLUE);
     outtextxy(40,60,"Semnificatii abrevieri");
     outtextxy(getmaxx()/2-290,60,"Cuvinte existente");
     buton_exit();
    //outtextxy(20,20,"Ce inseamna fiecare simbol din analiza sintactica:");

}

#endif // F_INTERFATA_H_INCLUDED
