#include "MetaCercle.h"

void setRayon(int r, Cercle_t * this)
{
    this->rayon = r;
}

int getRayon(Cercle_t * this)
{
    return this->rayon;
}

void ConstructeurCercle(Cercle_t * this)
{
    this->myClass = metaCercle;
    metaObjetGraphique->ConstructeurObjetGraphique(&this->superClasse);
    //this->myClass->superClasse->ConstructeurObjetGraphique(&this->superClasse);
    this->rayon = DEFAULT_RADIUS;
    this->superClasse.type = CERCLE;
}

void afficherCercle(ObjetGraphique_t * this)
{
    Cercle_t * cercle = (Cercle_t *)(this);
    printf("Je suis un cercle de rayon %d.\n", cercle->rayon);
}

void effacerCercle(ObjetGraphique_t * this)
{
    Cercle_t * cercle = (Cercle_t *)(this);
    printf("Effacement du cercle de rayon %d.\n", cercle->rayon);
}

void deplacerCercle(ObjetGraphique_t * this)
{
    Cercle_t * cercle = (Cercle_t *)(this);
    printf("Deplacement du cercle de rayon %d.\n", cercle->rayon);
}

void allouerMetaCercle(void)
{
    if(metaCercle != NULL)
        free(metaCercle);

    metaCercle = (MetaCercle_t *)(malloc(sizeof(MetaCercle_t)));
    //metaCercle->superClasse = metaObjetGraphique;
    metaCercle->setRayon = &setRayon;
    metaCercle->getRayon = &getRayon;
    metaCercle->ConstructeurCercle = &ConstructeurCercle;
}
