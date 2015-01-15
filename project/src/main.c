#include <stdio.h>

#include "MetaObjetGraphique.h"
#include "ObjetGraphique.h"
#include "MetaCercle.h"
#include "Cercle.h"
#include "MetaRectangle.h"
#include "Rectangle.h"

MetaObjetGraphique_t * metaObjetGraphique = NULL;
MetaCercle_t * metaCercle = NULL;
MetaRectangle_t * metaRectangle = NULL;

int main(void)
{
    allouerMetaObjetGraphique();
    allouerMetaCercle();
    allouerMetaRectangle();

    ObjetGraphique_t * obj = (ObjetGraphique_t *)(malloc(sizeof(ObjetGraphique_t)));
    metaObjetGraphique->ConstructeurObjetGraphique(obj);
    printf("Objet graphique\n");
    printf("X : %d\n", obj->x);
    printf("Y : %d\n", obj->x);
    printf("Nombre de classes : %d\n\n", metaObjetGraphique->NbObjetsGraphiques);

    Cercle_t * cercle = (Cercle_t *)(malloc(sizeof(Cercle_t)));
    metaCercle->ConstructeurCercle(cercle);
    printf("Cercle\n");
    printf("X : %d\n", cercle->superClasse.x);
    printf("Y : %d\n", cercle->superClasse.y);
    printf("R : %d\n", cercle->rayon);
    printf("Nombre de classes : %d\n\n", metaObjetGraphique->NbObjetsGraphiques);

    Rectangle_t rectangle;
    metaRectangle->ConstructeurRectangle(&rectangle);
    printf("Rectangle\n");
    printf("X : %d\n", rectangle.superClasse.x);
    printf("Y : %d\n", rectangle.superClasse.y);
    printf("Largeur : %d\n", rectangle.largeur);
    printf("Hauteur : %d\n", rectangle.hauteur);
    printf("Nombre de classes : %d\n\n", metaObjetGraphique->NbObjetsGraphiques);

    ObjetGraphique_t * pObj = (ObjetGraphique_t *)&rectangle;
    metaObjetGraphique->afficher(pObj);

    return 0;
}
