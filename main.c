//
// Created by Mathis Bretonne on 26/11/2023.
//
#include <stdio.h>

#include "donnees.h"

int main() {
    int a=1;

    int b=1000;
    int c=0;
    c=a+b;



    printf(" Choisissez la contrainte que vous voulez utiliser : \n\n");
    printf("           1- Contrainte de precedence seule \n");
    printf("           2- contrainte de destruction seule \n");
    printf("           3- contrainte de temps de cycle seule \n");
    printf("           4- Multicontrainte \n\n\n ");
    scanf("%d",&a);




    return 0;


}

