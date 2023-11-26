//
// Created by Frank BRAUD on 11/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "donnees.h"


int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilisé)

Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/


/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    int nombre_lignes = 0;
    int caractere;

    // Parcourt le fichier caractère par caractère et compte les sauts de ligne
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nombre_lignes++;
        }
    }
    nombre_lignes=nombre_lignes+1;
    fclose(fichier);
    printf("%d\n",nombre_lignes);

    return nombre_lignes;
}  /// renvoie la taille (pas utilise)


Mesexclu chargementDonnes(const char* nom_fichier) {
    Mesexclu exclusion;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }

    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclusion.opposees[i].op1=0;
        exclusion.opposees[i].op2=0;
    }

    exclusion.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclusion.opposees[exclusion.tailles].op1=valeur1;
        exclusion.opposees[exclusion.tailles].op2=valeur2;
        exclusion.tailles=exclusion.tailles+1;
    }

    fclose(fichier);
    printf("taille:%d\n",exclusion.tailles);

    // Affiche les valeurs de la structure Mesexclu
    printf("Structure Mesexclu : \n");
    for (int i = 0; i < exclusion.tailles; i++) {
        printf("(%d, %d)\n", exclusion.opposees[i].op1, exclusion.opposees[i].op2);
    }

    fclose(fichier);
    return exclusion;
}*/

/*int trouvertaille(const char* nom_fichier){

}*/


    fclose(fichier);
    return exclusion;
}
