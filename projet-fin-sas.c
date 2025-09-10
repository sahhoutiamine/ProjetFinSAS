#include <stdio.h>
#include <string.h>

#define LIST_LENGHT 100
#define MAX_CHARACTER_SIZE 64

typedef struct
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

int genererIdAuto()
{
    static int idCmp = 1;
    return idCmp++;
}

int ajouterJoueur(Joueur equipe[LIST_LENGHT])
{
    static int joueurCmp = 0;
    equipe[joueurCmp].idJoueur = genererIdAuto();
    getchar();
    printf("\nEntrer le nom de joueur : ");
    fgets(equipe[joueurCmp].nomJoueur, sizeof(equipe->nomJoueur), stdin);
    printf("\nEntrer le numero Maillot de joueur : ");
    scanf("%d", &(equipe[joueurCmp].numeroMaillot));
    getchar();
    printf("\nEntrer le poste de joueur (gardien, defenseur, milieu, attaquant) : ");
    fgets(equipe[joueurCmp].posteJoueur, sizeof(equipe->posteJoueur), stdin);
    printf("\nEntrer l'age de joueur : ");
    scanf("%d", &(equipe[joueurCmp].ageJoueur));
    printf("\nEntrer le nombre de buts marques par ce joueur : ");
    scanf("%d", &(equipe[joueurCmp].buts));
    getchar();
    printf("\nEntrer la date d'inscription de joueur (jj/mm/aaaa) : ");
    fgets(equipe[joueurCmp].dateInscription, sizeof(equipe->dateInscription), stdin);
    printf("\nEntrer le statut de joueur (titulaire ou remplacant) : ");
    fgets(equipe[joueurCmp].statutJoueur, sizeof(equipe->statutJoueur), stdin);
    return joueurCmp++;
}
///////////////////////////////

// int ajouterJoueurEnPostTab(Joueur equipeTrierParPost [LIST_LENGHT], Joueur j)
// {
//     static int joueurCmp = 0;
//     equipeTrierParPost[joueurCmp].idJoueur = genererIdAuto();
//     strcpy(equipeTrierParPost[joueurCmp].nomJoueur, j.nomJoueur);
//     equipeTrierParPost[joueurCmp].numeroMaillot = j.numeroMaillot;
//     strcpy(equipeTrierParPost[joueurCmp].posteJoueur, j.posteJoueur);
//     equipeTrierParPost[joueurCmp].ageJoueur = j.ageJoueur;
//     equipeTrierParPost[joueurCmp].buts = j.buts;
//     strcpy(equipeTrierParPost[joueurCmp].dateInscription, j.dateInscription);
//     strcpy(equipeTrierParPost[joueurCmp].statutJoueur, j.statutJoueur);
//     return joueurCmp++;
//}

///////////////////////////////

void swap(Joueur *a, Joueur *b)
{
    Joueur s = *a;
    *a = *b;
    *b = s;
}

void trierAlphabique(Joueur equipe[LIST_LENGHT], int listJoueurLen)
{

    for (int i = 0; i <= listJoueurLen; i++)
    {
        for (int j = 0; j <= listJoueurLen; j++)
        {
            if (strcmp(equipe[i].nomJoueur, equipe[j].nomJoueur) < 0)
            {
                swap(&equipe[i], &equipe[j]);
            }
        }
    }
}

void trierAge(Joueur equipe[LIST_LENGHT], int listJoueurLen)
{

    for (int i = 0; i <= listJoueurLen; i++)
    {
        for (int j = 0; j <= listJoueurLen; j++)
        {
            if (equipe[i].ageJoueur < equipe[j].ageJoueur)
            {
                swap(&equipe[i], &equipe[j]);
            }
        }
    }
}
void trierId(Joueur equipe[LIST_LENGHT], int listJoueurLen)
{

    for (int i = 0; i <= listJoueurLen; i++)
    {
        for (int j = 0; j <= listJoueurLen; j++)
        {
            if (equipe[i].idJoueur < equipe[j].idJoueur)
            {
                swap(&equipe[i], &equipe[j]);
            }
        }
    }
}

int afficheJoueurParPoste(Joueur equipe[LIST_LENGHT], int listJoueurLen)
{
    for (int i = 0; i <= listJoueurLen; i++)
    {
        for (int j = 0; j <= listJoueurLen; j++)
        {
            if (strcmp(equipe[i].posteJoueur, equipe[j].posteJoueur) < 0)
            {
                swap(&equipe[i], &equipe[j]);
            }
        }
    }
}


int rechercheParId (Joueur equipe[LIST_LENGHT], int joueurId, int listJoueurLen) {
    for (int i=0 ; i<=listJoueurLen ; i++)
    {
        if (equipe[i].idJoueur == joueurId)
        {
            return i;
        }
    }
    return 0;
}

int rechercheParNom (Joueur equipe[LIST_LENGHT], int joueurNom, int listJoueurLen) {
    for (int i=0 ; i<=listJoueurLen ; i++)
    {
        if (strcmp(equipe[i].nomJoueur, joueurNom))
        {
            return i;
        }
    }
    return 0;
}

void main()
{
    Joueur equipe[LIST_LENGHT];
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
                listJoueurLen = ajouterJoueur(equipe);
                break;
            case 2:
                int nmbrJoueurAjouter;
                printf("\nEntrer le nombre de joueurs que veux ajouter :");
                scanf("%d", &nmbrJoueurAjouter);
                for (int i = 0; i < nmbrJoueurAjouter; i++)
                {
                    listJoueurLen = ajouterJoueur(equipe);
                }
                break;

            default:
                printf("\nInvalid!");
                break;
            }
            break;
        case 2:
            for (int i = 0; i <= listJoueurLen; i++)
            {
                printf("\nJoueur %d :\nL'id : %d\nLe nom : %sLe numero maillot : %d\nLe poste : %sL'age : %d\nNombre de buts : %d\nLa date inscription : %sStatut : %s", i + 1, equipe[i].idJoueur, equipe[i].nomJoueur, equipe[i].numeroMaillot, equipe[i].posteJoueur, equipe[i].ageJoueur, equipe[i].buts, equipe[i].dateInscription, equipe[i].statutJoueur);
            }

            int affActNmbr;
            do
            {
                printf("\n-----------Trier du joueurs-----------\n");
                printf("\n1 - Trier les joueurs par ordre alphabetique");
                printf("\n2 - Trier les joueurs par age");
                printf("\n3 - Afficher les joueurs par poste");
                printf("\n0 - Exit\n -> ");
                scanf("%d", &affActNmbr);

                switch (affActNmbr)
                {
                case 1:
                    trierAlphabique(equipe, listJoueurLen);
                    for (int i = 0; i <= listJoueurLen; i++)
                    {
                        printf("\nJoueur %d :\nL'id : %d\nLe nom : %sLe numero maillot : %d\nLe poste : %sL'age : %d\nNombre de buts : %d\nLa date inscription : %sStatut : %s", i + 1, equipe[i].idJoueur, equipe[i].nomJoueur, equipe[i].numeroMaillot, equipe[i].posteJoueur, equipe[i].ageJoueur, equipe[i].buts, equipe[i].dateInscription, equipe[i].statutJoueur);
                    }

                    break;
                case 2:
                    trierAge(equipe, listJoueurLen);
                    for (int i = 0; i <= listJoueurLen; i++)
                    {
                        printf("\nJoueur %d :\nL'id : %d\nLe nom : %sLe numero maillot : %d\nLe poste : %sL'age : %d\nNombre de buts : %d\nLa date inscription : %sStatut : %s", i + 1, equipe[i].idJoueur, equipe[i].nomJoueur, equipe[i].numeroMaillot, equipe[i].posteJoueur, equipe[i].ageJoueur, equipe[i].buts, equipe[i].dateInscription, equipe[i].statutJoueur);
                    }
                    break;
                case 3:
                    afficheJoueurParPoste(equipe, listJoueurLen);
                    for (int i = 0; i <= listJoueurLen; i++)
                    {
                        printf("\nJoueur %d :\nL'id : %d\nLe nom : %sLe numero maillot : %d\nLe poste : %sL'age : %d\nNombre de buts : %d\nLa date inscription : %sStatut : %s", i + 1, equipe[i].idJoueur, equipe[i].nomJoueur, equipe[i].numeroMaillot, equipe[i].posteJoueur, equipe[i].ageJoueur, equipe[i].buts, equipe[i].dateInscription, equipe[i].statutJoueur);
                    }
                    break;
                case 0:
                    trierId(equipe, listJoueurLen);
                    break;

                default:
                    printf("\nInvalid!");
                    break;
                }
            } while (affActNmbr != 0);

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
            printf("\n1 - Afficher le nombre total de joueurs dans l'equipe");
            printf("\n2 - Afficher l'age moyen des joueurs");
            printf("\n3 - Afficher les joueurs ayant marque plus de X buts");
            printf("\n4 - Afficher le meilleur buteur");
            printf("\n5 - Afficher le joueur le plus jeune et le plus age.");
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
