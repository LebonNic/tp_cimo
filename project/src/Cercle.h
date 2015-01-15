#ifndef CERCLE_H
#define CERCLE_H
#include "ObjetGraphique.h"
#include "MetaCercle.h"

typedef struct Cercle{

    ObjetGraphique_t superClasse;
    struct MetaCercle * myClass;
    int rayon;

}Cercle_t;

#endif // CERCLE_H
