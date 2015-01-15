#include "MetaRectangle.h"

void setLargeur(int largeur, Rectangle_t * this)
{
    this->largeur = largeur;
}

void setHauteur(int hauteur, Rectangle_t * this)
{
    this->hauteur = hauteur;
}

int getLargeur(Rectangle_t * this)
{
    return this->largeur;
}

int getHauteur(Rectangle_t * this)
{
    return this->hauteur;
}

void afficherRectangle(ObjetGraphique_t * this)
{
    Rectangle_t * rectangle = (Rectangle_t *)(this);
    printf("Je suis un rectangle de hauteur %d et de largeur %d.\n", rectangle->hauteur, rectangle->largeur);
}

void effacerRectangle(ObjetGraphique_t * this)
{
    Rectangle_t * rectangle = (Rectangle_t *)(this);
    printf("Effacement du rectangle de hauteur %d et de largeur %d.\n", rectangle->hauteur, rectangle->largeur);
}

void deplacerRectangle(ObjetGraphique_t * this)
{
    Rectangle_t * rectangle = (Rectangle_t *)(this);
    printf("Deplacement du rectangle de hauteur %d et de largeur %d.\n", rectangle->hauteur, rectangle->largeur);
}

void ConstructeurRectangle(Rectangle_t * this)
{
    this->myClass = metaRectangle;
    metaObjetGraphique->ConstructeurObjetGraphique(&this->superClasse);
    this->hauteur = DEFAULT_HEIGHT;
    this->largeur = DEFAULT_WIDTH;
    this->superClasse.type = RECTANGLE;
}

int getCentreXRectangle(ObjetGraphique_t * this)
{
    Rectangle_t * rectangle = (Rectangle_t *)(this);
    return (rectangle->superClasse.x + rectangle->largeur) - (rectangle->largeur / 2);
}

int getCentreYRectangle(ObjetGraphique_t * this)
{
    Rectangle_t * rectangle = (Rectangle_t *)(this);
    return (rectangle->superClasse.y + rectangle->hauteur) - (rectangle->hauteur / 2);
}

void allouerMetaRectangle(void)
{
    if(metaRectangle != NULL)
        free(metaRectangle);

    metaRectangle = (MetaRectangle_t *)(malloc(sizeof(MetaRectangle_t)));
    //metaRectangle->superClass = metaObjetGraphique;
    metaRectangle->setLargeur = &setLargeur;
    metaRectangle->setHauteur = &setHauteur;
    metaRectangle->getLargeur = &getLargeur;
    metaRectangle->getHauteur = &getHauteur;
    metaRectangle->ConstructeurRectangle = &ConstructeurRectangle;
}
