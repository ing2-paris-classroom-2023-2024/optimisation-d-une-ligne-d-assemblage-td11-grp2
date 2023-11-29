//
// Created by Frank BRAUD on 11/11/2023.
//

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

typedef struct noeud{
    int station;
    struct noeud *predecessor;
}Noeud;


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

Mespreced chargementDonnes(const char* nom_fichier) {
    Mespreced preced;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    else{printf("lecture ok\n");
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
    printf("taille:%d\n",preced.tailles);
    /*printf("Structure precedent: \n");
    for (int i = 0; i < preced.tailles; i++) {
        printf("(%d, %d)\n", preced.precedent[i].pre1, preced.precedent[i].pre2);
    }*/
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
    printf("matrice initialise\n");
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
}

Noeud initNoeud(struct mesprecedent preced) {
    Noeud noeud1[preced.tailles];
    for (int i = 0; i <preced.tailles; i++) {
        noeud1[i].station = i;
        noeud1[i].predecessor = NULL;  // Initialisation de la liste de prédécesseurs
    }
    ///return noeud1; a finir
}

/*void ajoutarc(graphe* mongraphe,int source, int destination){
    mongraphe->adjMatrix[source][destination] = 1;
}

// Appliquer l'algorithme topologique
void topologicalSortUtil(graphe mongraphe, int v, int visite[], int stack[], int* stackIndex) {
    visite[v] = 1;

    // Parcourir tous les sommets adjacents
    for (int i = 0; i < mongraphe.nbSom; i++) {
        if (mongraphe.adjMatrix[v][i] && !visite[i]) {
            topologicalSortUtil(mongraphe, i, visite, stack, stackIndex);
        }
    }

    // Empiler le sommet actuel
    stack[(*stackIndex)++] = v;
}

void topologicalSort(graphe mongraphe) {
    int visited[100] = {0};
    int stack[100];
    int stackIndex = 0;

    // Parcourir tous les sommets et appliquer l'algorithme récursivement
    for (int i = 0; i < mongraphe.nbSom; i++) {
        if (!visited[i]) {
            topologicalSortUtil(mongraphe, i, visited, stack, &stackIndex);
        }
    }

    // Afficher l'ordre topologique (le chemin critique)
    printf("Ordre topologique des opérations:\n");
    while (stackIndex > 0) {
        printf("%d ", stack[--stackIndex]);
    }
}*/

int main() {

    Mespreced test = chargementDonnes("precedent.txt");
    //printf("taille %d",test.tailles);
    struct Graphe mongraphe1;
    initGraph(test,&mongraphe1);
    remplirGraphe(test,&mongraphe1);
    struct noeud monnoeud;
    initNoeud(test);
    /*for(int i=0;i<test.tailles;i++){
        printf("boucle:i");
        ajoutarc(mongraphe,test.precedent[i].pre1, test.precedent[i].pre2);
        printf("ajoute:%d",i);
    }*/
    //topologicalSort(mongraphe);

    return 0;
}
