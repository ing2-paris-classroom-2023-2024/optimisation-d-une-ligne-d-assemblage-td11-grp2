#include <stdio.h>
#include <stdlib.h>

struct precede {
    int pre1, pre2;
};

typedef struct mesprecedent {
    int tailles;
    struct precede precedent[100] ;
} Mespreced;

typedef struct Graphe {
    int nbSom;
    int **adjMatrix;
} graphe;

struct tempsop{
    int operation;
    float temps;
};

/*struct mesope{
    struct tempsop tabop[100];
    int tailles;
};

struct grapheop{
    int nbSom;
    float **ajdOpe;
};*/

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
}  /// renvoie la taille

/*struct mesope chargementDonnesOP(const char* nom_fichier) {
    struct mesope ope;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    else{printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        ope.tabop[i].operation=0;
        ope.tabop[i].temps=0;
    }
    ope.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %.2f",&valeur1,&valeur2)==2){
        ope.tabop[ope.tailles].operation=valeur1;
        ope.tabop[ope.tailles].temps=valeur2;
        ope.tailles=ope.tailles+1;
    }
    printf("taille:%d\n",ope.tailles);
    fclose(fichier);
    return ope;
}*/
/*void initGraphOP(struct mesope ope,struct Graphe *oper2) {

    oper2->nbSom = ope.tailles;
    oper2->adjMatrix = malloc(2* sizeof(int *));
    for (int i = 0; i < 2; ++i) {
        oper2->adjMatrix[i] = calloc(oper2->nbSom, sizeof(int));
    }
    if (oper2->adjMatrix == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice d'adjacence.\n");
    }
    for (int i = 0; i < oper2->nbSom; i++) {
        oper2->adjMatrix[i] = (int*)malloc(oper2->nbSom * sizeof(int));
        // Initialiser la matrice à zéro
    }
    if (oper2->adjMatrix == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice d'adjacence.\n");
    }

    printf("matrice initialise\n");
}*/
/*void remplirGrapheOP(struct mesope ope,struct grapheop *oper2) {

    /*for (int i = 0; i<preced.tailles; i++) {
        printf("ligne %d valeur: %d %d\n", i, preced.precedent[i].pre1, preced.precedent[i].pre2);
    }*
    for(int b=0;b<ope.tailles;b++){
        //printf("b=%d et taille=%d\n",b,preced.tailles);
        oper2->ajdOpe[0][b]=ope.tabop[b].operation;
        oper2->ajdOpe[1][b]=ope.tabop[b].temps;
        printf("|%d||%.2f|\n",oper2->ajdOpe[0][b],oper2->ajdOpe[1][b]);
    }
}*/

Mespreced chargementDonnes(const char* nom_fichier) {
    Mespreced preced;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    else{
        //printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        preced.precedent[i].pre1=0;
        preced.precedent[i].pre2=0;
    }

    preced.tailles = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        preced.precedent[preced.tailles].pre1=valeur1;
        preced.precedent[preced.tailles].pre2=valeur2;
        preced.tailles=preced.tailles+1;
    }
    fclose(fichier);
    printf("\ntaille:%d\n\n",preced.tailles);
    fclose(fichier);
    return preced;
}

void initGraph(struct mesprecedent preced,struct Graphe *mongraphe2) {
    /*graphe* mongraphe = (graphe*)malloc(sizeof(graphe));
    if (mongraphe == NULL) {
        printf("Erreur d'allocation\n");
    }*/
    mongraphe2->nbSom = preced.tailles;
    mongraphe2->adjMatrix = malloc(2* sizeof(int *));
    for (int i = 0; i < 2; ++i) {
        mongraphe2->adjMatrix[i] = calloc(mongraphe2->nbSom, sizeof(int));
    }
    if (mongraphe2->adjMatrix == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice d'adjacence.\n");
    }
    for (int i = 0; i < mongraphe2->nbSom; i++) {
        mongraphe2->adjMatrix[i] = (int*)malloc(mongraphe2->nbSom * sizeof(int));
        // Initialiser la matrice à zéro
    }
    if (mongraphe2->adjMatrix == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice d'adjacence.\n");
    }
    //printf("taille1:%d\n",preced.tailles);
    //printf("matrice initialise\n");
}

void remplirGraphe(struct mesprecedent preced,struct Graphe *mongraphe1) {

    /*for (int i = 0; i<preced.tailles; i++) {
        printf("ligne %d valeur: %d %d\n", i, preced.precedent[i].pre1, preced.precedent[i].pre2);
    }*/
    for(int b=0;b<preced.tailles;b++){
        //printf("b=%d et taille=%d\n",b,preced.tailles);
        mongraphe1->adjMatrix[0][b]=preced.precedent[b].pre1;
        mongraphe1->adjMatrix[1][b]=preced.precedent[b].pre2;
        printf("|%d||%d|\n",mongraphe1->adjMatrix[0][b],mongraphe1->adjMatrix[1][b]);
    }
} /// lire le fichier a l'envers pour gerer les doublons

void classerinit(int* tableau,struct Graphe *mongraphe1,struct mesprecedent preced, int compteurtab,int* bool1) {
    //printf("classer ok\n");
    int reserve = 0;
    int compteur = 0;

    for(int i=0;i<preced.tailles;i++) {
        tableau[i]=0;
    }
    for (int b = 0; b < mongraphe1->nbSom; b++) {
        reserve = mongraphe1->adjMatrix[0][b];
        for (int c = 0; c < mongraphe1->nbSom; c++) {
            if (reserve == mongraphe1->adjMatrix[1][c]) {
                compteur=compteur+1;
            }
        }
        if(compteur==0){
            //printf("%d n'a pas de precedent\n",reserve);
            tableau[compteurtab]=reserve;
            compteurtab=compteurtab+1;
            //printf("compteur tab: %d \n",compteurtab);
        }
        //printf("%d compteur:%d\n",reserve,compteur);
        compteur=0;
    }

    //printf("compteur: %d\n",compteurtab);
    for(int terme=0; terme<preced.tailles;terme++){
        for(int i=0; i<preced.tailles; i++) {
            if (tableau[terme] == mongraphe1->adjMatrix[0][i]) {
                if(bool1[mongraphe1->adjMatrix[1][i]]==0 || bool1[mongraphe1->adjMatrix[0][i]]==0) {
                    tableau[compteurtab] = mongraphe1->adjMatrix[1][i];
                    //printf("%d\n",mongraphe1->adjMatrix[1][i]);
                    bool1[mongraphe1->adjMatrix[1][i]]=1;
                }
                compteurtab = compteurtab + 1;
            }
        }
    }

    printf("\n\ntableau: ");
    for (int i = 0; i < preced.tailles; i++) {
        if(tableau[i]!=0) {
            printf("%d\t", tableau[i]);
        }
    }
    printf("\n\n");

}

int lireFichier(struct tempsop tableau_operations[], const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 0;
    }

    int operation;
    float temps;
    int taille = 0;

    while (fscanf(fichier, "%d %f", &operation, &temps) == 2) {
        tableau_operations[taille].operation = operation;
        tableau_operations[taille].temps = temps;
        taille++;

        if (taille >= 100) {
            printf("Erreur: Tableau de taille dépassée\n");
        }
    }
    fclose(fichier);
    return taille;
}

void calcultemps(struct tempsop tableau_operations[], int *tableau, struct mesprecedent preced,struct tempsop classement[]) {
    int place=0;
    for (int i = 0; i < preced.tailles; i++) {
        int j = 0;  // Initialisez j à zéro avant de l'utiliser
        while (j < preced.tailles && tableau[i] != tableau_operations[j].operation) {
            j++;
        }

        if (j < preced.tailles) {
            classement[place]=tableau_operations[j];
            place=place+1;
            //printf("%d = %d\n", tableau[i], tableau_operations[j].operation);

            //printf("place %d\n",place);

        } else {
            //printf("Pas de correspondance pour %d\n", tableau[i]);
        }
    }
    float tempsadd=0;
    int r=1;
    for (int i = 0; i < place; i++) {
        tempsadd = tempsadd + classement[i].temps;
        if(tempsadd<10*r) {
            printf("operation %d duree: %.2f --> %.2f\n", classement[i].operation, classement[i].temps, tempsadd);
        }else{
            printf("------------------------\n");
            printf("operation %d duree: %.2f --> %.2f\n", classement[i].operation, classement[i].temps, tempsadd);
            r=r+1;
        }
    }

}


int main() {

    Mespreced test = chargementDonnes("precedent.txt");
    //printf("taille %d",test.tailles);
    struct Graphe mongraphe1;
    int* bool = calloc(test.tailles, sizeof(int));
    if (bool == NULL) {
        printf("Erreur d'allocation bool\n");
    }
    initGraph(test,&mongraphe1);
    remplirGraphe(test,&mongraphe1);

    int ordre[test.tailles];
    int compteurtab1=0;
    classerinit(&ordre,&mongraphe1,test,compteurtab1,bool);
    /*struct mesope ope1=chargementDonnesOP("operations.txt");
    struct grapheop monope1;
    initGraphOP(ope1,&monope1);
    remplirGrapheOP(ope1,&monope1);*/
    struct tempsop tableau_operations[100];
    int tailleope= lireFichier(tableau_operations,"operations.txt");
    /*for (int i = 0; i < tailleope; i++) {
        printf("Opération %d: Temps %.2f\n", tableau_operations[i].operation, tableau_operations[i].temps);
    }*/
    struct tempsop classement[100];
    calcultemps(tableau_operations,&ordre,test,classement);
    return 0;
}