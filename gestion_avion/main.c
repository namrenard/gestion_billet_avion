#include <stdio.h>
#include "avion.h"

int main(void) {
    billet a, b, c, d;
    char num[] = "LX4456";
    char num2[] = "d5g456";
    char num3[] = "LG8456";
    char num4[] = "AF0759";
    b = creaVol(8,35,15,45,num);
    c = creaVol(9,50,18,55,num2);
    int dVol_b = dureeVol(b);
    printf("Duree du VOL numero %s:\n %d min\n", b.numVol, dVol_b);
    printf("\n");
    a = creaVol(8,10,9,5,num3);
    afficheVol(a);
    printf("\n");
    afficheVol(b);
    printf("\n");
    afficheVol(c);
    printf("\n");
    d = creaVol(20,55,9,10,num4);
    afficheVol(d);
    int bool = 0;
    int res = dureeVol2(d, &bool);
    printf("Duree du VOL numero %s:\n %d min.\n %s", num4, res, (bool == 1) ? "Vol arrivant apres minuit." : "");
    return 0;
}
