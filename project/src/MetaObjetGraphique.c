#include "MetaObjetGraphique.h"

int getX(ObjetGraphique_t * this)
{
    return this->x;
}

void setX(int inX, ObjetGraphique_t * this)
{
    this->x = inX;
}

int getY(ObjetGraphique_t * this)
{
    return this->y;
}

void setY(int inY, ObjetGraphique_t * this)
{
    this->y = inY;
}

int GetNbObjetsGraphique(void)
{
    return metaObjetGraphique->NbObjetsGraphiques;
}

void ConstructeurObjetGraphique(ObjetGraphique_t * this)
{
    this->x = X_DEFAULT_VALUE;
    this->y = Y_DEFAULT_VALUE;
    this->type = OG;
    this->myClass = metaObjetGraphique;
    metaObjetGraphique->NbObjetsGraphiques++;
}

void afficher(ObjetGraphique_t * this)
{
    metaObjetGraphique->vTableAfficher[this->type](this);
}

void effacer(ObjetGraphique_t * this)
{
    metaObjetGraphique->vTableEffacer[this->type](this);
}

void deplacer(ObjetGraphique_t * this)
{
    metaObjetGraphique->vTableDeplacer[this->type](this);
}

int getCentreX(ObjetGraphique_t * this)
{
    return metaObjetGraphique->vTableGetCentreX[this->type](this);
}

int getCentreY(ObjetGraphique_t * this)
{
   return metaObjetGraphique->vTableGetCentreY[this->type](this);
}

void allouerMetaObjetGraphique(void)
{
    if(metaObjetGraphique != NULL)
        free(metaObjetGraphique);

    metaObjetGraphique = (MetaObjetGraphique_t *)(malloc(sizeof(MetaObjetGraphique_t)));
    metaObjetGraphique->getX = &getX;
    metaObjetGraphique->getY = &getY;
    metaObjetGraphique->setX = &setX;
    metaObjetGraphique->setY = &setY;

    metaObjetGraphique->vTableAfficher[CERCLE] = &afficherCercle;
    metaObjetGraphique->vTableAfficher[RECTANGLE] = &afficherRectangle;

    metaObjetGraphique->vTableEffacer[CERCLE] = &effacerCercle;
    metaObjetGraphique->vTableEffacer[RECTANGLE] = & effacerRectangle;

    metaObjetGraphique->vTableDeplacer[CERCLE] = &deplacerCercle;
    metaObjetGraphique->vTableDeplacer[RECTANGLE] = &deplacerRectangle;

    metaObjetGraphique->vTableGetCentreX[CERCLE] = &getCentreXObjetGraphique;
    metaObjetGraphique->vTableGetCentreX[RECTANGLE] = &getCentreXRectangle;
    metaObjetGraphique->vTableGetCentreX[OG] = &getCentreXObjetGraphique;

    metaObjetGraphique->vTableGetCentreY[CERCLE] = &getCentreYObjetGraphique;
    metaObjetGraphique->vTableGetCentreY[RECTANGLE] = &getCentreYRectangle;
    metaObjetGraphique->vTableGetCentreY[OG] = &getCentreYObjetGraphique;

    metaObjetGraphique->afficher = &afficher;
    metaObjetGraphique->effacer = &effacer;
    metaObjetGraphique->deplacer = &deplacer;
    metaObjetGraphique->getCentreX = &getCentreX;
    metaObjetGraphique->getCentreY = &getCentreY;

    metaObjetGraphique->NbObjetsGraphiques = 0;
    metaObjetGraphique->GetNbObjetsGraphiques = &GetNbObjetsGraphique;
    metaObjetGraphique->ConstructeurObjetGraphique = &ConstructeurObjetGraphique;
}

int getCentreXObjetGraphique(ObjetGraphique_t * this)
{
    return this->x;
}

int getCentreYObjetGraphique(ObjetGraphique_t * this)
{
    return this->y;
}
