#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// Fonction pour récupérer un mot depuis un fichier
void motARecuperer(char mot[])
{
    srand(time(NULL));

    // Génère un nombre aléatoire entre 1 et 10 inclus
    int nombreAleatoire = rand() % 835 + 1;

    // Utilisation de fopen pour ouvrir le fichier "world.txt" en mode lecture
    FILE *fichier = fopen("world.txt", "r");

    // Vérification si le fichier s'est correctement ouvert
    if (fichier == NULL)
    {
        perror("Le fichier ne s'est pas correctement ouvert");
        exit(1);
    }

    // Lecture du mot correspondant au nombre aléatoire
    for (int i = 0; i < nombreAleatoire; i++)
    {
        fgets(mot, 100, fichier);
    }

    // Suppression du saut de ligne à la fin du mot, s'il y en a un
    if (mot[strlen(mot) - 1] == '\n')
    {
        mot[strlen(mot) - 1] = '\0';
    }

    // Fermeture du fichier
    fclose(fichier);
}

// Fonction pour afficher une chaîne de caractères
void AfficherChaine(char chaine[])
{
    int i = 0;
    while (chaine[i] != '\0')
    {
        printf("%c ", chaine[i]);
        i++;
    }
    printf("\n");
}

// Fonction pour préparer le mot caché avec des underscores
void PreparerMotCache(char motADeviner[], char motCache[])
{
    int i = 0;
    while(motADeviner[i] != '\0')
    {
        motCache[i] = '_';
        i++;
    }
    motCache[i] = '\0'; // Ajout du caractère de fin de chaîne
}

// Fonction pour mettre à jour le mot caché avec une lettre devinée
bool MettreAJourMotCache(char motADeviner[], char motCache[], char lettre)
{
    int i = 0;
    bool estMaj = false;
    while(motADeviner[i] != '\0')
    {
        if (lettre == motADeviner[i])
        {
            motCache[i] = lettre;
            estMaj = true;
        }
        i++;
    }
    return estMaj;
}

// Fonction pour vérifier si le mot est entièrement deviné
bool MotEstDevine(char mot[])
{
    int i = 0;
    while (mot[i] != '\0')
    {
        if (mot[i] == '_')
        {
            return false;
        }
        i++;
    }
    return true;
}

// Fonction pour afficher le dessin du pendu en fonction du nombre d'erreurs
void AfficherDessinPendu(int erreurs)
{
    // Le dessin du pendu est affiché en fonction du nombre d'erreurs
    switch(erreurs)
    {
    case 0 :
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        break;
        
    case 1 :
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("                \n");
        printf("==========      \n");
        break;

    case 2 :
        printf("                \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;

    case 3 :
        printf("=============== \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;

    case 4 :
        printf("=============== \n");
        printf("  ||      |     \n");
        printf("  ||      |     \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;

    case 5 :
        printf("=============== \n");
        printf("  ||      |     \n");
        printf("  ||     _|_    \n");
        printf("  ||    /   \\   \n");
        printf("  ||    \\___/   \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;

    case 6 :
        printf("=============== \n");
        printf("  ||      |     \n");
        printf("  ||     _|_    \n");
        printf("  ||    /   \\   \n");
        printf("  ||    \\___/   \n");
        printf("  ||      |     \n");
        printf("  ||      |     \n");
        printf("  ||      |     \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;

    case 7 :
        printf("=============== \n");
        printf("  ||      |     \n");
        printf("  ||     _|_    \n");
        printf("  ||    /   \\   \n");
        printf("  ||    \\___/   \n");
        printf("  ||    \\ |     \n");
        printf("  ||     \\|     \n");
        printf("  ||      |     \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;

    case 8 :
        printf("=============== \n");
        printf("  ||      |     \n");
        printf("  ||     _|_    \n");
        printf("  ||    /   \\   \n");
        printf("  ||    \\___/   \n");
        printf("  ||    \\ | /   \n");
        printf("  ||     \\|/    \n");
        printf("  ||      |     \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;

    case 9 :
        printf("=============== \n");
        printf("  ||      |     \n");
        printf("  ||     _|_    \n");
        printf("  ||    /   \\   \n");
        printf("  ||    \\___/   \n");
        printf("  ||    \\ | /   \n");
        printf("  ||     \\|/    \n");
        printf("  ||      |     \n");
        printf("  ||     /      \n");
        printf("  ||    /       \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;
        
    case 10 :
        printf("=============== \n");
        printf("  ||      |     \n");
        printf("  ||     _|_    \n");
        printf("  ||    /   \\   \n");
        printf("  ||    \\___/   \n");
        printf("  ||    \\ | /   \n");
        printf("  ||     \\|/    \n");
        printf("  ||      |     \n");
        printf("  ||     / \\     \n");
        printf("  ||    /   \\    \n");
        printf("  ||            \n");
        printf("  ||            \n");
        printf("==========      \n");
        break;
    }
}

int main()
{
    // Demande le nom du joueur
    char nomJoueur[100];
    printf("Quel est votre nom ?\n");
    scanf("%s", nomJoueur);

    // Demande un mot au joueur
    char motADeviner[100];
    motARecuperer(motADeviner);

    // Nettoyage de la console pour le deuxième joueur
    system("clear");

    // Préparation du mot caché avec caractère de fin de chaîne
    char motCache[100];
    PreparerMotCache(motADeviner, motCache);

    int nombreErreurs = 0;
    int maxErreurs = 8;
    bool continuer = true;

    do {
        // Nettoyage de la console
        system("clear");

        // Affiche le dessin du pendu en fonction du nombre d'erreurs
        AfficherDessinPendu(nombreErreurs);

        // Affichage du mot caché
        AfficherChaine(motCache);

        // Gestion de la défaite ou de la victoire
        if (nombreErreurs >= maxErreurs)
        {
            printf("Désolé %s, vous n'avez pas trouvé le mot %s.\n", nomJoueur, motADeviner);
            continuer = false;
        }
        else if (MotEstDevine(motCache))
        {
            printf("Bravo %s, vous avez trouvé le mot %s\n", nomJoueur, motADeviner);
            continuer = false;
        }
        else
        {
            // Demande une lettre
            char lettre;
            printf("Lettre proposée : ");

            // Ajouter une boucle pour s'assurer que l'entrée est une lettre
            do {
                scanf(" %c", &lettre);
                if (!isalpha(lettre))
                {
                    printf("Veuillez entrer une lettre valide.\n");
                    printf("Lettre proposée : ");
                }
            } while (!isalpha(lettre));

            lettre = toupper(lettre);  // Convertir la lettre en majuscule

            // Mise à jour du mot caché et gestion de l'erreur possible
            if (!MettreAJourMotCache(motADeviner, motCache, lettre))
            {
                // Si le mot n'a pas été mis à jour, c'est une erreur
                nombreErreurs++;
            }
        }
    } while (continuer);

    // Affiche le mot et le nombre d'erreurs
    printf("Mot à deviner : %s\n", motADeviner);
    printf("Nombre d'erreurs : %d/%d", nombreErreurs, maxErreurs);

    return 0;
}