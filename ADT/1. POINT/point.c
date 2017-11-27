#include "point.h"
#include <stdio.h>
#include <math.h>
#define mathPI 3.14159265

POINT MakePOINT (int X, int Y) {
    POINT P;
    Absis(P)=X;
    Ordinat(P)=Y;
    return P;
}

void BacaPOINT (POINT * P) {
    int x,y;
    scanf("%d %d",&x,&y);
    *P=MakePOINT(x,y);
}

void TulisPOINT (POINT P) {
    printf("(%d,%d)",Absis(P),Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) {
    return (Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2){
    return (Absis(P1)!=Absis(P2))||(Ordinat(P1)!=Ordinat(P2));
}

boolean IsOrigin (POINT P) /* Menghasilkan true jika P adalah titik origin */ {
    return (Absis(P)==0)&&(Ordinat(P)==0);
}
boolean IsOnSbX (POINT P)/* Menghasilkan true jika P terletak Pada sumbu X */ {
    return Ordinat(P)==0;
}
boolean IsOnSbY (POINT P) {
    return Absis(P)==0;
}

int Kuadran (POINT P) {
    if ((Absis(P)>0)&&(Ordinat(P)>0)) {
        return 1;
    } else if ((Absis(P)<0)&&(Ordinat(P)>0)){
        return 2;
    } else if ((Absis(P)<0)&&(Ordinat(P)<0)){
        return 3;
    } else {
        return 4;
    }
}
POINT NextX (POINT P){
    return MakePOINT(Absis(P)+1,Ordinat(P));
}
POINT NextY (POINT P) {
    return MakePOINT(Absis(P),Ordinat(P)+1);
}
POINT PlusDelta (POINT P, int deltaX, int deltaY) {
    return MakePOINT(Absis(P)+deltaX,Ordinat(P)+deltaY);
}
POINT MirrorOf (POINT P, boolean SbX) {
    if (SbX) {
        return MakePOINT(Absis(P),-Ordinat(P));
    } else {
        return MakePOINT(-Absis(P),Ordinat(P));
    }
}

int Jarak0 (POINT P) {
    return (sqrt(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P)));
}

int Panjang (POINT P1, POINT P2) {
    Absis(P1)=Absis(P1)-Absis(P2);
    Ordinat(P1)=Ordinat(P1)-Ordinat(P2);
    return (sqrt(Absis(P1)*Absis(P1)+Ordinat(P1)*Ordinat(P1)));
}
void Geser (POINT *P, int deltaX, int deltaY) {
    *P = PlusDelta(*P,deltaX,deltaY);
}
void GeserKeSbX (POINT *P) {
    Ordinat(*P)=0;
}
void GeserKeSbY (POINT *P) {
    Absis(*P)=0;
}
void Mirror (POINT *P, boolean SbX) {
    if (SbX) {
        Ordinat(*P)=-Ordinat(*P);
    } else {
        Absis(*P)=-Absis(*P);
    }
}
void Putar (POINT *P, int Sudut) {
    int x,y;
    Sudut= Sudut*mathPI/180;
    x=Absis(*P)*cos(Sudut)-Ordinat(*P)*sin(Sudut);
    y=Absis(*P)*sin(Sudut)+Ordinat(*P)*cos(Sudut);
    *P=MakePOINT(x,y);
}
