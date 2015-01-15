#ifndef METAOBJETGRAPHIQUE_H
#define METAOBJETGRAPHIQUE_H

#include <stdlib.h>
#include <stdio.h>
#include "ObjetGraphique.h"
#include "MetaCercle.h"
#include "MetaRectangle.h"

#define X_DEFAULT_VALUE 0
#define Y_DEFAULT_VALUE 0

typedef struct MetaObjetGraphique{

    /* Méthodes d'instances */
    void (*setX)(int, this);
    void (*setY)(int, this);
    int (*getX)(this);
    int (*getY)(this);

    /* V-TABLES */
    void (*vTableEffacer[NB_CLASSES_FILLES])(ObjetGraphique_t * this);
    void (*vTableAfficher[NB_CLASSES_FILLES])(ObjetGraphique_t * this);
    void (*vTableDeplacer[NB_CLASSES_FILLES])(ObjetGraphique_t * this);

    int (*vTableGetCentreX[NB_CLASSES_FILLES + 1])(ObjetGraphique_t * this);
    int (*vTableGetCentreY[NB_CLASSES_FILLES + 1])(ObjetGraphique_t * this);

    /* Pointeurs sur les méthodes virtuelles */
    void (*afficher)(ObjetGraphique_t * this);
    void (*effacer)(ObjetGraphique_t * this);
    void (*deplacer)(ObjetGraphique_t * this);
    int (*getCentreX)(ObjetGraphique_t * this);
    int (*getCentreY)(ObjetGraphique_t * this);

    /* attributs de classe */
    int NbObjetsGraphiques;

    /* Méthodes de classe */
    int (*GetNbObjetsGraphiques)(void);

    /* Constructeur de classe */
    void (*ConstructeurObjetGraphique)(this);

}MetaObjetGraphique_t;

extern MetaObjetGraphique_t * metaObjetGraphique;

int getX(ObjetGraphique_t * this);
void setX(int inX, ObjetGraphique_t * this);
int getY(ObjetGraphique_t * this);
void setY(int inY, ObjetGraphique_t * this);
int GetNbObjetsGraphique(void);
void ConstructeurObjetGraphique(ObjetGraphique_t * this);

void afficher(ObjetGraphique_t * this);
void effacer(ObjetGraphique_t * this);
void deplacer(ObjetGraphique_t * this);
int getCentreX(ObjetGraphique_t * this);
int getCentreY(ObjetGraphique_t * this);

int getCentreXObjetGraphique(ObjetGraphique_t * this);
int getCentreYObjetGraphique(ObjetGraphique_t * this);

void allouerMetaObjetGraphique(void);

#endif // METAOBJETGRAPHIQUE_H
