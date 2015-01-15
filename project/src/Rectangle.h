#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ObjetGraphique.h"
#include "MetaRectangle.h"

typedef struct Rectangle{

    ObjetGraphique_t superClasse;
    struct MetaRectangle * myClass;
    int largeur;
    int hauteur;

}Rectangle_t;

#endif // RECTANGLE_H
