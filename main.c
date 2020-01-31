#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "listedchainee.h"
#include "listedchainee_fonction.h"

int main()
{

	int des = 0,pos;
	GameObjet GOdonnee;
	Liste *l_liste;

	l_liste = (Liste *) malloc (sizeof(Liste));


	initListe(l_liste);

	//Insertion du premier GameObjet
	SetGO(&GOdonnee);
	inserLVide (l_liste,GOdonnee);
	printf("%d elements: deb=%d,fin=%d ",
    l_liste->taille_liste,l_liste->debut->donnee.Key,l_liste->fin->donnee.Key);
    affiche(l_liste);


	//Switch case pour choisir quoi faire
	while (des!=6)
	{
		printf ("1. Ajout au debut de la l_liste\n");
	    printf ("2. Ajout a la fin de la l_liste\n");
	    printf ("3. Ajout avant la position specifie\n");
	    printf ("4. Ajout apres la position specifie\n");
	    printf ("5. Suppression à la position specifie\n");
	    printf ("6. Quitter\n");
	    scanf("%d",&des);
	    switch(des)
	    {
	    	case 1 :
	    	SetGO(&GOdonnee);
	    	inserLDebut(l_liste, GOdonnee);
      		printf("%d elements: deb=%d,fin=%d ",
        	l_liste->taille_liste,l_liste->debut->donnee.Key,l_liste->fin->donnee.Key);
      		affiche(l_liste);
      		break;
      		case 2 :
      		SetGO(&GOdonnee);
	    	inserLFin(l_liste, GOdonnee);
      		printf("%d elements: deb=%d,fin=%d ",
        	l_liste->taille_liste,l_liste->debut->donnee.Key,l_liste->fin->donnee.Key);
      		affiche(l_liste);
      		break;
      		case 3 :
      		do
      		{
                printf("Entrez la position : ");
   				scanf("%d",&pos);
      		}while (pos < 1 || pos > l_liste->taille_liste);
      		SetGO(&GOdonnee);
	    	inserLPAvant(l_liste, GOdonnee,pos);
      		printf("%d elements: deb=%d,fin=%d ",
        	l_liste->taille_liste,l_liste->debut->donnee.Key,l_liste->fin->donnee.Key);
      		affiche(l_liste);
      		break;
      		case 4 :
      		do
      		{
                printf("Entrez la position : ");
   				scanf("%d",&pos);
      		}while (pos < 1 || pos > l_liste->taille_liste);
      		SetGO(&GOdonnee);
	    	inserLPApres(l_liste, GOdonnee,pos);
      		printf("%d elements: deb=%d,fin=%d ",
        	l_liste->taille_liste,l_liste->debut->donnee.Key,l_liste->fin->donnee.Key);
      		affiche(l_liste);
      		break;
      		case 5 :
      		do
      		{
                printf("Entrez la position : ");
   				scanf("%d",&pos);
      		}while (pos < 1 || pos > l_liste->taille_liste);
	    	suppEListe(l_liste,pos);
      		printf("%d elements: deb=%d,fin=%d ",
        	l_liste->taille_liste,l_liste->debut->donnee.Key,l_liste->fin->donnee.Key);
      		affiche(l_liste);
      		break;
	    }
	}






	return 0;
}
