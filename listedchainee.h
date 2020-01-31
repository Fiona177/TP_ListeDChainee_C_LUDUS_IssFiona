//---GameObjet---
typedef struct Vect3
{
    int posX;
    int posY;
    int posZ;
} Vect3;
typedef struct GameObjet
{
    int Key;
	char mesh[100];
	Vect3 pos;
} GameObjet;

//---Liste---
typedef struct ElementListe
{
    GameObjet donnee;
    struct ElementListe *precedent;
    struct ElementListe *suivant;
} Element;

typedef struct ListeE
{
	int taille_liste;
    Element *debut;
    Element *fin;
} Liste;


//---------------GAMEOBJET---------------
void SetGO(GameObjet *GOdonnee);
int GetKey(GameObjet GOdonnee);
char* GetMesh(GameObjet GOdonnee);
char* GetPos(GameObjet GOdonnee);
void affichageGO(GameObjet GOdonnee);

//---------------LISTE---------------
//Initialisation de la liste
void initListe(Liste *l_liste);
// insertion dans une Liste Vide
int  inserLVide (Liste * l_liste, GameObjet GOdonnee);
// insertion en debut de liste
int  inserLDebut (Liste * l_liste, GameObjet GOdonnee);
// insertion en Fin de liste
int  inserLFin (Liste * l_liste, GameObjet GOdonnee);
// Insertion avant une position
int  inserLPAvant (Liste * l_liste, GameObjet GOdonnee, int pos);
// Insertion après une position
int  inserLPApres (Liste * l_liste, GameObjet GOdonnee, int pos);
// Suppression Element de la liste
int suppEListe(Liste *l_liste, int pos);
//Affichage liste
void affiche(Liste *l_liste);
//Affichage liste inversée
void afficheInv(Liste *l_liste);

