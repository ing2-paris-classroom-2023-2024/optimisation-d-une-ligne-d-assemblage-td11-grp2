//
// Created by Mathis Bretonne on 26/11/2023.
//
#include <stdio.h>

#include "donnees.h"

int main() {
    // Déclaration des variables
    int nombre1, nombre2, somme , produit ;

    // Demande à l'utilisateur d'entrer le premier nombre
    printf("Entrez le premier nombre : ");
    scanf("%d", &nombre1);

    // Demande à l'utilisateur d'entrer le deuxième nombre
    printf("Entrez le deuxième nombre : ");
    scanf("%d", &nombre2);

    // Calcul de la somme
    somme = nombre1 + nombre2;

    // Affichage du résultat
    printf("La somme de %d et %d est : %d\n", nombre1, nombre2, somme);


    produit = nombre1 * nombre2;

    // Affichage du résultat
    printf("Le produit de %d et %d est : %d\n", nombre1, nombre2, produit);
    return 0;
}
// histoire de faire des commit quoi + 1 encore