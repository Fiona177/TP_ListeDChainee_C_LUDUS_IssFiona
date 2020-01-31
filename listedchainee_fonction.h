//---------------GAMEOBJET---------------
void SetGO(GameObjet *GOdonnee)
{
  int nNewX,nNewY,nNewZ,keyGO;
  char meshGO[100];
  printf("Veuillez indiquer la cle du GameObjet\n");
  scanf("%d",&keyGO);
  printf("Veuillez indiquer le X, Y et Z du GameObjet\n");
  scanf("%d %d %d",&nNewX,&nNewY,&nNewZ);
  printf("Veuillez indiquer la mesh du GameObjet\n");
  scanf("%s", meshGO);
	GOdonnee->pos.posX = nNewX;
	GOdonnee->pos.posY = nNewY;
	GOdonnee->pos.posZ = nNewZ;
	GOdonnee->Key = keyGO;
  strcpy(GOdonnee->mesh, meshGO);
	//GOdonnee->mesh = meshGO;
}
int GetKey(GameObjet GOdonnee)
{
  return GOdonnee.Key;
}
char* GetMesh(GameObjet GOdonnee)
{
  char * mesh;
  mesh = malloc(sizeof(char)*100);
  strcpy(mesh, GOdonnee.mesh);
  return mesh;
}
char* GetPos(GameObjet GOdonnee)
{
  char * positionX;
  char * positionY;
  char * positionZ;
  positionX = malloc(sizeof(char)*100);
  positionY = malloc(sizeof(char)*100);
  positionZ = malloc(sizeof(char)*100);
  sprintf(positionX,"%d ", GOdonnee.pos.posX);
  sprintf(positionY,"%d ", GOdonnee.pos.posY);
  sprintf(positionZ,"%d ", GOdonnee.pos.posZ);

  char * position;
  position = malloc(sizeof(char)*100);
  strcat(position, positionX);
  strcat(position, positionY);
  strcat(position, positionZ);

  return position;
}
void affichageGO(GameObjet GOdonnee)
{
  char * position;
  position = GetPos(GOdonnee);
  char * mesh;
  mesh = GetMesh(GOdonnee);
	printf("Cle du gameObjet : %d\n", GetKey(GOdonnee));
	printf("Position X, Y et Z du gameObjet : %s,\n", position);
	printf("La mesh du gameObjet : %s\n",mesh);
  free(mesh);
}



//---------------LISTE---------------
//Initialisation de la liste
void initListe(Liste *l_liste)
{
	l_liste->taille_liste = 0;
	l_liste->debut = NULL;
	l_liste->fin = NULL;
}

// insertion dans une Liste Vide
int  inserLVide (Liste * l_liste, GameObjet GOdonnee)
{

    Element * nouveau_element;

    if ((nouveau_element = (Element *) malloc ( sizeof (Element))) == NULL ) return - 1 ;

    nouveau_element-> donnee = GOdonnee;

    nouveau_element-> precedent = l_liste-> debut ;
    nouveau_element-> suivant = l_liste-> fin ;

    l_liste-> debut = nouveau_element;
    l_liste-> fin = nouveau_element;

    l_liste-> taille_liste ++;

    return  0 ;
}

// insertion en debut de liste
int  inserLDebut (Liste *l_liste, GameObjet GOdonnee)
{

    Element * nouveau_element;

    if ((nouveau_element = (Element *) malloc ( sizeof (Element))) == NULL )
    return - 1 ;

    nouveau_element-> donnee = GOdonnee;

    nouveau_element-> precedent = NULL ;
    nouveau_element-> suivant = l_liste-> debut ;

    l_liste-> debut -> precedent = nouveau_element;
    l_liste-> debut = nouveau_element;

    l_liste-> taille_liste ++;

    return  0 ;

}

// insertion en Fin de liste
int  inserLFin (Liste * l_liste, GameObjet GOdonnee)
{

    Element * nouveau_element;

     if ((nouveau_element = (Element *) malloc ( sizeof (Element))) == NULL )
        return - 1 ;

    nouveau_element-> donnee = GOdonnee;

    nouveau_element-> suivant = NULL ;
    nouveau_element-> precedent = l_liste-> fin ;
    l_liste-> fin -> suivant = nouveau_element;

    l_liste-> fin = nouveau_element;
    l_liste-> taille_liste ++;


	return  0 ;

}

// Insertion avant une position
int  inserLPAvant (Liste * l_liste, GameObjet GOdonnee, int pos)
{
    int i;
    Element * nouveau_element, * courant;

   if ((nouveau_element = (Element *) malloc ( sizeof (Element))) == NULL )
        return - 1 ;


    nouveau_element-> donnee = GOdonnee;

    courant = l_liste-> debut ;

    for (i = 1 ; i <pos; ++ i)
        courant = courant-> suivant ;

        nouveau_element-> suivant = courant;
        nouveau_element-> precedent = courant-> precedent ;

        if (courant-> precedent == NULL )
            l_liste-> debut = nouveau_element;
        else courant-> precedent -> suivant = nouveau_element;
            courant-> precedent = nouveau_element;

        l_liste-> taille_liste ++;

return  0 ;

}

// Insertion après une position
int  inserLPApres (Liste * l_liste, GameObjet GOdonnee, int pos)
{

    int i;
    Element * nouveau_element, * courant;

      if ((nouveau_element = (Element *) malloc ( sizeof (Element))) == NULL )
        return - 1 ;

    nouveau_element-> donnee = GOdonnee;

    courant = l_liste-> debut ;

    for (i = 1 ; i <pos; ++ i)
        courant = courant-> suivant ;

    nouveau_element-> suivant = courant-> suivant ;
    nouveau_element-> precedent = courant;

    if (courant-> suivant == NULL )
        l_liste-> fin = nouveau_element;
    else
        courant-> suivant -> precedent = nouveau_element;

    courant-> suivant = nouveau_element;
    l_liste-> taille_liste ++;

    return  0 ;
}

int suppEListe(Liste *l_liste, int pos)
{
  int i;
  Element *supp_element,*courant;

  if(l_liste->taille_liste == 0)
    return -1;

  if(pos == 1){ /* suppresion de 1er élément */
    supp_element = l_liste->debut;
    l_liste->debut = l_liste->debut->suivant;
    if(l_liste->debut == NULL)
      l_liste->fin = NULL;
    else
      l_liste->debut->precedent = NULL;
  }else if(pos == l_liste->taille_liste){ /* suppression du dernier élément */
    supp_element = l_liste->fin;
    l_liste->fin->precedent->suivant = NULL;
    l_liste->fin = l_liste->fin->precedent;
  }else { /* suppression ailleurs */
    courant = l_liste->debut;
      for(i=1;i<pos;++i)
        courant = courant->suivant;
    supp_element = courant;
    courant->precedent->suivant = courant->suivant;
    courant->suivant->precedent = courant->precedent;
  }
  free(supp_element);
  l_liste->taille_liste--;
  return 0;
}

void affiche(Liste *l_liste)
{ /* affichage en avançant */
  Element *courant;
  courant = l_liste->debut; /* point du départ le 1er élément */
  printf("[ ");
  while(courant != NULL){
    affichageGO(courant->donnee);
    courant = courant->suivant;
  }
  printf("]\n");
}

void afficheInv(Liste *l_liste)
{ /* affichage en reculant */
  Element *courant;
  courant = l_liste->fin; /* point du départ le dernier élément */
  printf("[ ");
  while(courant != NULL){
    affichageGO(courant->donnee);
    courant = courant->precedent;
  }
  printf("]\n");
}


