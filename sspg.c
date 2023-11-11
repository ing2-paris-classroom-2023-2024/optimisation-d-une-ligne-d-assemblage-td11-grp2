//
// Created by Frank BRAUD on 11/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "donnees.h"

struct exclu chargementDonnes(const char* nom_fichier) {
    struct exclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    //exclu.op = (struct arete*)malloc(graphe.taille * sizeof(struct arete));
    for (int i = 0; i < graphe.taille; i++) {
        fscanf(fichier, "%d %d\n", &exclusion.op1[i], &exclusion.op2[i]);
        exclusion.nbtotal=exclusion.nbtotal+1
    }
    fclose(fichier);
    return exclusion;
}