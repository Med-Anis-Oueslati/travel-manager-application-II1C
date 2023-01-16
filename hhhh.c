#include <stdlib.h>
#include <stdio.h>
typedef struct Noeud Noeud;
struct Noeud
{
    int val;
    struct Noeud *suivant;
};
typedef Noeud* Liste;


Liste ajout_tete(int e, Liste L){

    Liste p;
    p = malloc(sizeof(Liste));
    p->suivant=L;
    p->val=e;
    L=p;
    return L;
}

Liste ajout_queue(int e, Liste L){
    Liste p,Q;
    p = malloc(sizeof(Liste));
    p->suivant=NULL;
    p->val=e;
    Q=L;
    while(Q->suivant){
        Q=Q->suivant;
    }
    Q->suivant = p;
    return L;
}


Liste creer_Liste( Liste L){

    int e;
    int choix;
    L=NULL;
    do{
        printf("\nDonner un element : ");
        scanf("%d",&e);
        L=ajout_queue(e,L);
        printf("\nVoulez vous ajouter un nouveau element (tapez \'1\' pour ajouter)");
        scanf("%d",&choix);
    }while(choix==1);
    return L;
}


Liste creer_Liste_choix( Liste L){

    int e;
    int choix;
    L=NULL;

    printf("\nDonner un element a ajouter a la tete de la liste: ");
    scanf("%d",&e);
    L=ajout_tete(e,L);
    printf("\nVoulez vous ajouter un nouveau element \n\t\'1\' pour ajouter au debut de la liste\n\t\'2\' pour ajouter a la fin de la liste\n votre choix : ");
    scanf("%d",&choix);
    while(choix==1 || choix ==2){
    printf("\nDonner un element : ");
    scanf("%d",&e);
        if(choix==1)
            L=ajout_tete(e,L);
        else
            L=ajout_queue(e,L);
    printf("\nVoulez vous ajouter un nouveau element \n\t\'1\' pour ajouter au debut de la liste\n\t\'2\' pour ajouter a la fin de la liste\n votre choix : ");
    scanf("%d",&choix);
    }
    return L;
}

void afficher_Liste( Liste L){
  int i=0;
  Liste Q=L;
  if(!Q) printf("\nListe vide ");
  else{
      while(Q){
        i++;
        printf("\nL'element %d est %d",i,Q->val);
        Q=Q->suivant;
      }
    }
}

int longeur_liste(Liste L){
    Liste Q=L;
    int n=0;
    while(Q){
        Q=Q->suivant;
        n++;
    }
    return n;
}

int occurrence(Liste L, int e){
    Liste Q=L;
    int n=0;
    while(Q){
        if(Q->val==e) n++;
        Q=Q->suivant;
    }
    return n;
}


Liste recherhe_liste(Liste L, int x){
    Liste Q=L;
    int n=0;
    while(Q && Q->val!=x){
        Q=Q->suivant;
    }
    return Q;
}


Liste supprimer_tete(Liste L){
    Liste Q;
    if(L){
        Q=L;
        L=L->suivant;
        free(Q);
    }
    return L;
}

Liste supprimer_queue(Liste L){
    Liste Q, Pred;
    Q=L;
    Pred=NULL;

    while(Q->suivant){
        Pred=Q;
        Q=Q->suivant;
    }
    if(Pred==NULL) L=NULL;
    else Pred->suivant = NULL;
    free(Q);
    return L;
}

int est_vide(Liste L){
    //1 : Liste non vide   0: Liste vide
    if(L)return 1;
    else return 0;
}

int main (){
    Liste L;
    int e;
    L=creer_Liste_choix(L);

    printf("\nLa liste contient %d cellules",longeur_liste(L));

    printf("\n\t*******\tAffichage de la liste \********");
    afficher_Liste(L);

    printf("\nDonner un element a compter l'occurence : ");scanf("%d",&e);
    printf("\nL'element %d existe %d fois dans la liste",e,occurrence(L,e));

    printf("\nDonner un element indiquant le d�but de la nouvelle liste : ");scanf("%d",&e);
    afficher_Liste(recherhe_liste(L,e));

    printf("\n\t*******\tSupprimer tete de la liste \********");
    L=supprimer_tete(L);
    afficher_Liste(L);

    printf("\n\t*******\tSupprimer la Queue de la liste \********");
    L=supprimer_queue(L);
    afficher_Liste(L);

}
