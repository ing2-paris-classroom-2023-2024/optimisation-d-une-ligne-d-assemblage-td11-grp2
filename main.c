#include <stdio.h>
#include <stdlib.h>
typedef struct tache {
    int exclu1, exclu2;
}t_tache1;
typedef struct tache2 {
    int taille;
    int nbTachesDifferentes;
    struct tache stockage[100] ;
} t_tache2;
typedef struct Graphe_exclusion {
    int nbSom;
    int **adjMatrix;
} t_graphe_exclu;
typedef struct machines{
    int tableau[100];

}t_machines;
/*struct tempexclu{
    int operation;
    unsigned int couleur;
};*/
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
    unsigned int couleur;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int compter_taches2(int taches[100]){

    FILE *file = fopen("exclusion.txt", "r");
    t_tache1 exclusion1;
    int nb_taches_differentes = 0;

    while (fscanf(file, "%d %d", &exclusion1.exclu1, &exclusion1.exclu2) == 2) {
        int i;
        for (i = 0; i < nb_taches_differentes; i++) {
            if (taches[i] == exclusion1.exclu1) {
                break;
            }
        }
        if (i == nb_taches_differentes) {
            taches[nb_taches_differentes++] = exclusion1.exclu1;
        }

        // Vérifier si exclusion1.exclu2 est une nouvelle tâche
        for (i = 0; i < nb_taches_differentes; i++) {
            if (taches[i] == exclusion1.exclu2) {
                break;  // Tâche déjà présente, sortir de la boucle
            }
        }
        if (i == nb_taches_differentes) {
            taches[nb_taches_differentes++] = exclusion1.exclu2;
        }
    }

    //printf("Taches differentes : ");
    for (int j = 0; j < nb_taches_differentes; j++) {
        printf("%d ", taches[j]);
    }
    //printf("\n\n ");
    //printf("il y a %d taches differentes\n\n",nb_taches_differentes);

    return nb_taches_differentes;

}

t_tache2 lire_infos( char* nom_fichier , int taches[100]) {

    FILE *file = fopen("exclusion.txt", "r");
    t_tache2 exclu;

    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur de lecture du fichier\n");
        exit(-1);
    }
    else{//printf("lecture ok\n");
    }
    for(int i=0;i<100;i++){
        exclu.stockage[i].exclu1=0;
        exclu.stockage[i].exclu2=0;
    }


    exclu.taille = 0;
    int valeur1, valeur2;
    while(fscanf(fichier,"%d %d",&valeur1,&valeur2)==2){
        exclu.stockage[exclu.taille].exclu1=valeur1;
        exclu.stockage[exclu.taille].exclu2=valeur2;
        exclu.taille=exclu.taille+1;
    }
    fclose(fichier);
    printf("taille:%d\n",exclu.taille);

    exclu.nbTachesDifferentes = compter_taches2(taches);


    fclose(fichier);
    return exclu;
}

void initGraphExclu(struct tache2 exclu,struct Graphe_exclusion *graphe_exclu) {
    /*graphe* mongraphe = (graphe*)malloc(sizeof(graphe));
    if (mongraphe == NULL) {
        printf("Erreur d'allocation\n");
    }*/
    graphe_exclu->nbSom = exclu.nbTachesDifferentes;
    graphe_exclu->adjMatrix = malloc(2* sizeof(int *));
    for (int i = 0; i < 2; ++i) {
        graphe_exclu->adjMatrix[i] = calloc(graphe_exclu->nbSom, sizeof(int));
    }
    if (graphe_exclu->adjMatrix == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice d'adjacence.\n");
    }
    for (int i = 0; i < graphe_exclu->nbSom; i++) {
        graphe_exclu->adjMatrix[i] = (int*)malloc(graphe_exclu->nbSom * sizeof(int));
        // Initialiser la matrice à zéro
    }
    if (graphe_exclu->adjMatrix == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice d'adjacence.\n");
    }
    //printf("taille1:%d\n",exclu.taille);

    printf("matrice initialise\n");
}

void compter_taches(int taches[100],struct tempsop *tabexclu){

    FILE *file = fopen("exclusion.txt", "r");

    t_tache1 exclusion1;

    int nb_taches_differentes = 0;


    while (fscanf(file, "%d %d", &exclusion1.exclu1, &exclusion1.exclu2) == 2) {
        int i;
        for (i = 0; i < nb_taches_differentes; i++) {
            if (taches[i] == exclusion1.exclu1) {
                break;
            }
        }
        if (i == nb_taches_differentes) {
            taches[nb_taches_differentes++] = exclusion1.exclu1;
        }

        // Vérifier si exclusion1.exclu2 est une nouvelle tâche
        for (i = 0; i < nb_taches_differentes; i++) {
            if (taches[i] == exclusion1.exclu2) {
                break;  // Tâche déjà présente, sortir de la boucle
            }
        }
        if (i == nb_taches_differentes) {
            taches[nb_taches_differentes++] = exclusion1.exclu2;
        }
    }

    //printf("Taches differentes : ");
    for (int j = 0; j < nb_taches_differentes; j++) {
        //printf("%d ", taches[j]);
        tabexclu[j].operation=taches[j];
    }
    //printf("\n\n ");
    //printf("il y a %d taches differentes\n\n",nb_taches_differentes);

}

void remplirGrapheExclu(struct tache2 exclu,struct Graphe_exclusion *graphe_exclu) {

    /*for (int i = 0; i<exclu.taille; i++) {
        printf("ligne %d valeur: %d %d\n", i, exclu.stockage[i].exclu1, exclu.stockage[i].exclu2);
    }*/

    for(int b=0;b<exclu.taille;b++){
        //printf("b=%d et taille=%d\n",b,exclu.taille);
        graphe_exclu->adjMatrix[0][b]=exclu.stockage[b].exclu1;
        graphe_exclu->adjMatrix[1][b]=exclu.stockage[b].exclu2;
        printf("|%d||%d|\n",graphe_exclu->adjMatrix[0][b],graphe_exclu->adjMatrix[1][b]);
    }
} /// lire le fichier a l'envers pour gerer les doublons

void remplir_tableau( t_machines tab1, t_machines tab2, t_machines tab3, t_machines tab4, t_machines tab5, int taches[100], t_graphe_exclu *graphe_exclu ){

    if (tab1.tableau[100]==0 ){

        if (tab2.tableau[100]==0 ){
            if (tab3.tableau[100]==0 ){
                if (tab4.tableau[100]==0 ){
                    if (tab5.tableau[100]==0 ){
                    }
                }
            }
        }
    }
}

int couleurPossible(int sommet, int couleur, int a, t_graphe_exclu *mongraphe_exclu, int *couleurs) {
    for (int i = 0; i < a; i++) {
        if (mongraphe_exclu->adjMatrix[sommet][i] && couleur == couleurs[i]) {
            return 0; // La couleur est déjà utilisée par un sommet voisin
        }
    }
    return 1; // La couleur est possible
}

void coloration(int taches[100], struct Graphe_exclusion *graphe_exclu, int taille, struct tempsop *tabexclu) {
    for (int i = 0; i < taille; i++) {
        tabexclu[i].couleur = 1; // Initialise la couleur à 1 par défaut
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < taille; b++) {
                if (taches[i] == graphe_exclu->adjMatrix[a][b]) {
                    if (a == 0) {
                        for (int c = 0; c < taille; c++) {
                            if (taches[c] == graphe_exclu->adjMatrix[1][b]) {
                                tabexclu[i].couleur = tabexclu[i].couleur + 1;
                            }
                        }
                    }
                }
            }
        }

        // Appliquer les exclusions
        for (int j = 0; j < taille; j++) {
            if (j != i) {
                for (int k = 0; k < taille; k++) {
                    if (taches[j] == graphe_exclu->adjMatrix[0][k] && taches[i] == graphe_exclu->adjMatrix[1][k]) {
                        if (tabexclu[i].couleur == tabexclu[j].couleur) {
                            tabexclu[i].couleur = tabexclu[i].couleur + 1;
                        }
                    }
                    if (taches[j] == graphe_exclu->adjMatrix[1][k] && taches[i] == graphe_exclu->adjMatrix[0][k]) {
                        if (tabexclu[i].couleur == tabexclu[j].couleur) {
                            tabexclu[i].couleur = tabexclu[i].couleur + 1;
                        }
                    }
                }
            }
        }
    }

    // Tri du tableau par couleur (utilisation de l'algorithme de tri à bulles pour la simplicité)
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (tabexclu[j].couleur > tabexclu[j + 1].couleur) {
                // Échanger les éléments
                struct tempsop temp = tabexclu[j];
                tabexclu[j] = tabexclu[j + 1];
                tabexclu[j + 1] = temp;
            }
        }
    }
    FILE *fichier = fopen("operations.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
    }

    int operation;
    float temps;
    int taille1 = 0;

    while (fscanf(fichier, "%d %f", &operation, &temps) == 2) {
        tabexclu[taille1].temps = temps;
        taille1++;

        if (taille1 >= 100) {
            printf("Erreur: Tableau de taille dépassée\n");
        }
    }
    fclose(fichier);


    /*float duree_stations=0;
    for (int i=0; i<taille;i++){
        printf("temps: %.2f",tabexclu[i].temps);
        }


    for (int i=0; i<taille;i++){
        if(tabexclu[0].couleur){
            duree_stations=tabexclu[0].temps;
        }else{
            if (tabexclu[i].couleur==tabexclu[i-1].couleur){
                duree_stations= duree_stations+tabexclu[i].temps;
            }
        }
}
*/
    // Affichage des résultats triés
    for (int i = 0; i < taille; i++) {
        printf("l'operation: %d --> station no.%u ---> duree total: %.2f\n", tabexclu[i].operation, tabexclu[i].couleur, tabexclu[i].temps);
    }
}

void afficherColoration(int taille, int *couleurs, int *taches) {
    for (int i = 0; i < taille; i++) {
        printf("Tache %d : Machine %d\n", taches[i], couleurs[i]);
    }
}

int mainExclu(int *tabfin) {
    t_tache1 exclusion1 ;
    t_machines tab1;
    t_machines tab2;
    t_machines tab3;
    t_machines tab4;
    t_machines tab5;

    for(int i =0 ; i<100 ; i++){
        tab1.tableau[i]=0;
        tab2.tableau[i]=0;
        tab3.tableau[i]=0;
        tab4.tableau[i]=0;
        tab5.tableau[i]=0;
    }
    struct tempsop tableau_exclusion[100];

    int taches[100];
    t_tache2 essai = lire_infos( "exclusion.txt" , taches);

    //printf("taille %d",essai.taille);

    struct Graphe_exclusion graphe_exclu;

    int *bool2= calloc(essai.taille, sizeof(int));
    if (bool2 == NULL) {
        printf("Erreur d'allocation bool\n");
    }
    compter_taches(taches,&tableau_exclusion);
    int a= compter_taches2(taches);

    initGraphExclu(essai, &graphe_exclu);
    remplirGrapheExclu(essai, &graphe_exclu);
    remplir_tableau(tab1,tab2,tab3,tab4,tab5,taches, &graphe_exclu);

    int* couleurs = calloc(essai.taille, sizeof(int));


    printf("%d\n", essai.taille);

    coloration(&tabfin,&graphe_exclu,a,&tableau_exclusion);

    /*if (colorerGraphe( essai.taille, &graphe_exclu, couleurs, a)) {
        printf("Attribution de machines réussie.\n");
        afficherColoration(a, couleurs, taches);
    } else {
        printf("Aucune attribution de machines possible.\n");
    }*/

    free(couleurs);

    return  0;
}

int main() {

    Mespreced test = chargementDonnes("precedent.txt");
    //printf("taille %d",test.tailles);
    struct Graphe mongraphe1;
    int* bool1 = calloc(test.tailles, sizeof(int));
    if (bool1 == NULL) {
        printf("Erreur d'allocation bool\n");
    }
    initGraph(test,&mongraphe1);
    remplirGraphe(test,&mongraphe1);

    int ordre[test.tailles];
    int compteurtab1=0;
    classerinit(&ordre,&mongraphe1,test,compteurtab1,bool1);
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
    int a =mainExclu(ordre);
    return 0;
}