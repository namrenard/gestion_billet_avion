//avion.h

#ifndef _AVION_H
#define _AVION_H

struct billet_avion
{
    int dep_h, dep_m;
    int arr_h, arr_m;
    char numVol[20];

};
typedef struct billet_avion billet;

billet creaVol(int dep_h, int dep_m, int arr_h, int arr_m, char numVol[]);
int verifNumVol(char numVol[]);
int dureeVol(billet v);
void afficheVol(billet v);
int dureeVol2(billet v, int *p);

#endif 
