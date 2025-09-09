#include <stdio.h>

#define LIST_LENGHT 100
#define MAX_CHARACTER_SIZE 64

typedef struct Joueur
{
    int id; 
    char nom[MAX_CHARACTER_SIZE];
    int numeroMaillot;
    char poste[MAX_CHARACTER_SIZE];
    int age;
    int buts;
    char dateInscription[MAX_CHARACTER_SIZE];
    char statut[MAX_CHARACTER_SIZE];
} Joueur;



int ajouterJoueur () 

{

}

void main () {
    Joueur listJoueurs[LIST_LENGHT];
    int actNmbr;
    do
    {
        printf("\n-----------Gestion d'une Equipe de Football-----------\n");
        printf("\n1 - Ajouter un joueur");
        printf("\n2 - Afficher la liste de tous les joueurs");
        printf("\n3 - Modifier un joueur");
        printf("\n4 - Supprimer un joueur");
        printf("\n5 - Rechercher un joueu");
        printf("\n6 - Statistiques");
        printf("\n0 - Exit\n -> ");

        scanf("%d", &actNmbr);

        switch (actNmbr)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 0:
            printf("Adios!");
            break;
        
        default:
            break;
        }

    } while (actNmbr != 0);
    
    
}

