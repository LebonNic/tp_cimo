#ifndef METACERCLE_H
#define METACERCLE_H

#include "MetaObjetGraphique.h"
#include "Cercle.h"

#define DEFAULT_RADIUS 10

/* Nécessaire pour résoudre des problèmes de références croisées */
typedef struct MetaObjetGraphique MetaObjetGraphique_t;

typedef struct MetaCercle{

    //MetaObjetGraphique_t * superClasse;

    void (*setRayon)(int, Cercle_t *);
    int (*getRayon)(Cercle_t *);

    void(*ConstructeurCercle)(Cercle_t *);

}MetaCercle_t;

extern MetaCercle_t * metaCercle;

void setRayon(int r, Cercle_t * this);
int getRayon(Cercle_t * this);
void ConstructeurCercle(Cercle_t * this);

void afficherCercle(ObjetGraphique_t * this);
void effacerCercle(ObjetGraphique_t * this);
void deplacerCercle(ObjetGraphique_t * this);

void allouerMetaCercle(void);

#endif // METACERCLE_H
