#ifndef OBJETGRAPHIQUE_H
#define OBJETGRAPHIQUE_H

#include "MetaObjetGraphique.h"

#define NB_CLASSES_FILLES 2
typedef enum OG_t {CERCLE=0, RECTANGLE=1, OG=2} OG_t;

typedef struct ObjetGraphique{
    struct MetaObjetGraphique * myClass;
    int x;
    int y;
    OG_t type;
} ObjetGraphique_t;

typedef ObjetGraphique_t * this;

#endif // OBJETGRAPHIQUE_H
