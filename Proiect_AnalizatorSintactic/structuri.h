 #ifndef STRUCTURI_H_INCLUDED
#define STRUCTURI_H_INCLUDED

struct punct
{
    int x,y;
};
struct dreptunghi
{
    punct ss,dj; //ss - stanga sus //dj - dreapta jos
};
struct buton
{
    dreptunghi D;
    char text[200];

}B[13];

int nrCuv=0;
char PROPOZITIE[20][50];
struct tip_regula
{
    char st[20];
    char dr1[20];
    char dr2[20];

};

tip_regula regula[150];
int nrReguli;
struct multime
{
     int nrElem;
    char element[6][10]={NULL};

};
multime chart[20][20];
char d[200];
int capat,inceput=-1,capat2,t1=0,t2=0,t3,t4;
int inceput2=0;
#endif // STRUCTURI_H_INCLUDED
