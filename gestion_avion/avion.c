#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "avion.h"

int verifNumVol(char numVol[])
{
    int i;
    if (!(toupper(numVol[0]) >= 'A' && toupper(numVol[0]) <= 'Z') &&
            !(toupper(numVol[1]) >= 'A' && toupper(numVol[1]) <= 'Z')) {
            return 0;
        }
        for (i = 2; i < strlen(numVol); i++) {
            if (numVol[i] >= 'a' && numVol[i] <= 'z' || numVol[i] >= 'A' && numVol[i] <= 'Z') {
                return 0;
            }
        }
    return 1;
}

billet creaVol(int dep_h, int dep_m, int arr_h, int arr_m, char numVol[])
{
    billet v;
    char numVolError[] = "Error number\0";
    v.dep_h = dep_h;
    v.dep_m = dep_m;
    v.arr_h = arr_h;
    v.arr_m = arr_m;

    if(verifNumVol(numVol) == 1){
         strcpy(v.numVol, numVol);}
    else{
         strcpy(v.numVol, numVolError);}
    return v;
}

int dureeVol(billet v)
{
    int d_tot, h_duree, min_duree, h_to_min;
    if (v.dep_h > v.arr_m){
        h_duree =  (v.dep_h - v.arr_h);
    }else{
        h_duree = v.arr_h - v.dep_h;
    }
    if(v.arr_m > v.dep_m){
        min_duree = v.arr_m - v.dep_h;
    }else{
        min_duree = v.arr_m - v.dep_m;
    }

    if (h_duree > 0) {
        h_to_min = h_duree * 60;
    }else{
        h_to_min = 0;
    }
    d_tot = h_to_min + min_duree;
    return d_tot;
}

void afficheVol(billet v)
{
    printf("Vol numero \"%s\"  :\n depart -> %dH%d\n arrivee -> %dH%d\n", v.numVol,v.dep_h
            ,v.dep_m, v.arr_h, v.arr_m);
    int duree = dureeVol(v);
    int d_h = duree / 60;
    int d_m = duree % 60 ;
    if(duree > 60){
        printf("Duree du vol -> %dH%d\n",d_h,d_m);
    }else{
        printf("Duree du vol -> %d minutes\n",d_m);
    }
}
int dureeVol2(billet v, int *p)
{
    int d_tot, h_duree, min_duree, h_to_min, minuit, bool;

    if (v.dep_h > v.arr_h){
        h_duree =  (v.dep_h - v.arr_h);
    }else{
        h_duree = v.arr_h - v.dep_h;
    }
    if(v.arr_m > v.dep_m){
        min_duree = v.arr_m - v.dep_m;
    }else{
        min_duree = v.dep_m - v.arr_m;
    }
    if (h_duree > 0) {
        h_to_min = h_duree * 60;
    }else{
        h_to_min = 0;
    }
    d_tot = h_to_min + min_duree;
    minuit = h_duree+v.dep_h;
    if(minuit >24){
       bool = 1;
    }else{
        bool = 0;
    }
    *p = bool;
    return d_tot;
}