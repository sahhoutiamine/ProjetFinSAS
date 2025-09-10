#include <stdio.h>

#define LIST_LENGHT 100
#define MAX_CHARACTER_SIZE 64

typedef struct Joueur
{
    int idJoueur; 
    char nomJoueur[MAX_CHARACTER_SIZE];
    int numeroMaillot;
    char posteJoueur[MAX_CHARACTER_SIZE];
    int ageJoueur;
    int buts;
    char dateInscription[MAX_CHARACTER_SIZE];
    char statutJoueur[MAX_CHARACTER_SIZE];
} Joueur;


int genererIdAuto () 
{
    static int idCmp = 1;
    return idCmp++;
}

int ajouterJoueur (Joueur listJoueurs[LIST_LENGHT]) 
{
    static int joueurCmp = 0;
    listJoueurs[joueurCmp].idJoueur = genererIdAuto();
    getchar();
    printf("\nEntrer le nom de joueur : ");
    fgets(listJoueurs[joueurCmp].nomJoueur, sizeof(listJoueurs->nomJoueur), stdin);
    printf("\nEntrer le numero Maillot de joueur : ");
    scanf("%d", &(listJoueurs[joueurCmp].numeroMaillot));
    getchar();
    printf("\nEntrer le poste de joueur (gardien, defenseur, milieu, attaquant) : ");
    fgets(listJoueurs[joueurCmp].posteJoueur, sizeof(listJoueurs->posteJoueur), stdin);
    printf("\nEntrer l'age de joueur : ");
    scanf("%d", &(listJoueurs[joueurCmp].ageJoueur));    
    printf("\nEntrer le nombre de buts marques par ce joueur : ");
    scanf("%d", &(listJoueurs[joueurCmp].buts));
    getchar();
    printf("\nEntrer la date d'inscription de joueur (jj/mm/aaaa) : ");
    fgets(listJoueurs[joueurCmp].dateInscription, sizeof(listJoueurs->dateInscription), stdin);
    printf("\nEntrer le statut de joueur (titulaire ou remplacant) : ");
    fgets(listJoueurs[joueurCmp].statutJoueur, sizeof(listJoueurs->statutJoueur), stdin);
    return joueurCmp++;    
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
            int ajtActNmbr;
            int listJoueurLen;
            printf("\n-----------Insertion du joueur-----------\n");
            printf("\n1 - Ajouter un seul joueur");
            printf("\n2 - Ajouter plusieur joueurs\n -> ");
            scanf("%d", &ajtActNmbr);
            switch (ajtActNmbr)
            {
            case 1:
                listJoueurLen = ajouterJoueur(listJoueurs);
                break;
            case 2:
                int nmbrJoueurAjouter;
                printf("\nEntrer le nombre de joueurs que veux ajouter :");
                scanf("%d", &nmbrJoueurAjouter);
                for (int i=0 ; i<nmbrJoueurAjouter ; i++)
                {
                    listJoueurLen = ajouterJoueur(listJoueurs);
                }
                break;
            
            default:
                printf("\nInvalid!");
                break;
            }
            break;
        case 2:
            for (int i=0 ; i<=listJoueurLen ; i++)
            {
                printf("\nJoueur %d :\nL'id : %d\nLe nom : %sLe numero maillot : %d\nLe poste : %sL'age : %d\nNombre de buts : %d\nLa date inscription : %sStatut : %s", i+1, listJoueurs[i].idJoueur, listJoueurs[i].nomJoueur, listJoueurs[i].numeroMaillot, listJoueurs[i].posteJoueur, listJoueurs[i].ageJoueur, listJoueurs[i].buts, listJoueurs[i].dateInscription, listJoueurs[i].statutJoueur);
            }

            int affActNmbr;
            printf("\n-----------Trier du joueur-----------\n");
            printf("\n1 - Trier les joueurs par ordre alphabetique");
            printf("\n2 - Trier les joueurs par age");
            printf("\n3 - Afficher les joueurs par poste\n -> ");
            scanf("%d", &affActNmbr);

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
             int statActNmbr;
            printf("\n1 - Afficher le nombre total de joueurs dans l’équipe");
            printf("\n2 - Afficher l’âge moyen des joueurs");
            printf("\n3 - Afficher les joueurs ayant marqué plus de X buts");
            printf("\n4 - Afficher le meilleur buteur");
            printf("\n5 - Afficher le joueur le plus jeune et le plus âgé.");
            scanf("%d", &statActNmbr);
            switch (statActNmbr)
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
            
            default:
                printf("\nInvalid!");
                break;
            }
            break;
        case 0:
            printf("\nAdios!");
            break;
        
        default:
            break;
        }

    } while (actNmbr != 0);
    
    
}

