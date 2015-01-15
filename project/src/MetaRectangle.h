#ifndef METARECTANGLE_H
#define METARECTANGLE_H

#include "MetaObjetGraphique.h"
#include "Rectangle.h"

#define DEFAULT_HEIGHT 20
#define DEFAULT_WIDTH 20

/* Nécessaire pour résoudre des problèmes de références croisées */
typedef struct MetaObjetGraphique MetaObjetGraphique_t;

typedef struct MetaRectangle{

    //struct MetaObjetGraphique * superClass;
    void(*setLargeur)(int, Rectangle_t * this);
    void(*setHauteur)(int, Rectangle_t * this);
    int(*getLargeur)(Rectangle_t * this);
    int(*getHauteur)(Rectangle_t * this);

    void(*ConstructeurRectangle)(Rectangle_t * this);

}MetaRectangle_t;

extern MetaRectangle_t * metaRectangle;

void setLargeur(int largeur, Rectangle_t * this);
void setHauteur(int hauteur, Rectangle_t * this);
int getLargeur(Rectangle_t * this);
int getHauteur(Rectangle_t * this);

void afficherRectangle(ObjetGraphique_t * this);
void effacerRectangle(ObjetGraphique_t * this);
void deplacerRectangle(ObjetGraphique_t * this);

int getCentreXRectangle(ObjetGraphique_t * this);
int getCentreYRectangle(ObjetGraphique_t * this);

void ConstructeurRectangle(Rectangle_t * this);

void allouerMetaRectangle(void);

#endif // METARECTANGLE_H
