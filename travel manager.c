#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct date
{
    int jour;
    int mois;
    int annee;
}date;

typedef struct temps
{
    int heure;
    int minute;
}temps;

typedef struct voyage
{
    int id;
    char destination[100];
    char depart[100];
    char airport[100];
    char class[100];
    float prix;
    date dated; //date de depart
    temps tempsd;//temps de depart
    temps tempsa;//temps d'arrivee
    temps duree;//duree de voyage
}voyage;

void add_trip(voyage A[], int *CPT) {

    printf("\nADDING A NEW TRIP\n\n");
    A[*CPT].id = *CPT + 1;
    printf("ID : %d\n", A[*CPT].id);
    printf("DESTINATION : ");
    fflush(stdin);
    gets(A[*CPT].destination);
    printf("DEPART : ");
    fflush(stdin);
    gets(A[*CPT].depart);
    printf("AIRPORT : ");
    fflush(stdin);
    gets(A[*CPT].airport);
    printf("CLASS : ");
    gets(A[*CPT].class);
    printf("PRIX : ");
    fflush(stdin);
    scanf("%f", &A[*CPT].prix);
    printf("DATE DE DEPART : ");
    fflush(stdin);
    scanf("%d/%d/%d",&A[*CPT].dated.jour,&A[*CPT].dated.mois,&A[*CPT].dated.annee);
    printf("TEMPS DE DEPART : ");
    fflush(stdin);
    scanf("%d:%d",&A[*CPT].tempsd.heure,&A[*CPT].tempsd.minute);
    printf("TEMPS D'ARRIVEE : ");
    fflush(stdin);
    scanf("%d:%d",&A[*CPT].tempsa.heure,&A[*CPT].tempsa.minute);
    printf("DUREE : ");
    fflush(stdin);
    scanf("%d:%d",&A[*CPT].duree.heure,&A[*CPT].duree.minute);

    printf("\nADDITION SUCCESSFUL!");
    (*CPT)++; // Increment the count of trips
    getch();
}

void delete_trip(voyage A[], int *CPT) {
    int id;
    int i;
    int found = 0;

    printf("Enter the ID of the trip you want to delete: ");
    scanf("%d", &id);

    // Search for the trip with the specified ID
    for (i = 0; i < *CPT; i++) {
        if (A[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        // Shift the remaining trips in the array to the left to overwrite the deleted trip
        for (; i < *CPT - 1; i++) {
            A[i] = A[i + 1];
        }
        (*CPT)--; // Decrement the count of trips
        printf("\nTRIP DELETED SUCCESSFULLY!");
    } else {
        printf("\nTRIP NOT FOUND!");
    }

    getch();
}

void search_by_price(voyage A[], int CPT, float min_price, float max_price) {
    int i;
    int found = 0;

    printf("SEARCHING FOR TRIPS BETWEEN %.2f AND %.2f\n\n", min_price, max_price);

    // Search for trips with prices within the specified range
    for (i = 0; i < CPT; i++) {
        if (A[i].prix >= min_price && A[i].prix <= max_price) {
            printf("ID: %d\n", A[i].id);
            printf("DESTINATION: %s\n", A[i].destination);
            printf("DEPART: %s\n", A[i].depart);
            printf("AIRPORT: %s\n", A[i].airport);
            printf("CLASS: %s\n", A[i].class);
            printf("PRIX: %.2f\n", A[i].prix);
            printf("DATE DE DEPART: %d/%d/%d\n", A[i].dated.jour, A[i].dated.mois, A[i].dated.annee);
            printf("TEMPS DE DEPART: %d:%d\n", A[i].tempsd.heure, A[i].tempsd.minute);
            printf("TEMPS D'ARRIVEE: %d:%d\n", A[i].tempsa.heure, A[i].tempsa.minute);
            printf("DUREE: %d:%d\n", A[i].duree.heure, A[i].duree.minute);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("NO TRIPS FOUND WITHIN THE SPECIFIED PRICE RANGE!");
    }
}

void modify_trip(voyage A[], int CPT, int trip_id) {
    int i;
    int found = 0;
    char ch[10];
    int new_value;


    printf("MODIFYING TRIP WITH ID %d\n\n", trip_id);

    // Search for the trip with the specified ID
    for (i = 0; i < CPT; i++) {
        if (A[i].id == trip_id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("TRIP WITH ID %d NOT FOUND!", trip_id);
        return;
    }

    // Modify the details of the trip
    printf("\nWHAT DO YOU WANT TO MODIFY?\n");
    printf("1. DESTINATION\n");
    printf("2. DEPART\n");
    printf("3. AIRPORT\n");
    printf("4. CLASS\n");
    printf("5. PRIX\n");
    printf("6. DATE DE DEPART\n");
    printf("7. TEMPS DE DEPART\n");
    printf("8. TEMPS D'ARRIVEE\n");
    printf("9. DUREE\n");
    printf("10. EXIT\n");
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Modify destination
            printf("DESTINATION : ");
            fflush(stdin);
            gets(A[i].destination);
            break;
        case 2: // Modify depart
            printf("DEPART : ");
            fflush(stdin);
            gets(A[i].depart);
            break;
        case 3: // Modify airport
            printf("AIRPORT : ");
            fflush(stdin);
            gets(A[i].airport);
            break;
        case 4: // Modify class
            printf("CLASS : ");
            gets(A[i].class);
            break;
        case 5: // Modify prix
            printf("PRIX : ");
            fflush(stdin);
            scanf("%f", &A[i].prix);
            break;
        case 6: // Modify date de depart
            printf("DATE DE DEPART : ");
            fflush(stdin);
            scanf("%d/%d/%d",&A[i].dated.jour,&A[i].dated.mois,&A[i].dated.annee);
            break;
        case 7: // Modify temps de depart
            printf("TEMPS DE DEPART : ");
            fflush(stdin);
            scanf("%d:%d",&A[i].tempsd.heure,&A[i].tempsd.minute);
            break;
        case 8: // Modify temps d'arrivee
            printf("TEMPS D'ARRIVEE : ");
            fflush(stdin);
            scanf("%d:%d",&A[i].tempsa.heure,&A[i].tempsa.minute);
            break;
        case 9: // Modify duree
            printf("DUREE : ");
            fflush(stdin);
            scanf("%d:%d",&A[i].duree.heure,&A[i].duree.minute);
            break;
        case 10: // Exit
            printf("EXITING MODIFICATION MODE\n");
            return;
        default:
            printf("INVALID CHOICE!\n");
    }

    printf("\nTRIP MODIFIED SUCCESSFULLY!");
}

void search_trips(voyage A[], int CPT, char depart[], char destination[]) {
    int i;
    int found = 0;

    printf("SEARCHING FOR TRIPS FROM %s TO %s\n\n", depart, destination);

    // Search for trips with the specified departure and destination cities
    for (i = 0; i < CPT; i++) {
        if (strcmp(A[i].depart, depart) == 0 && strcmp(A[i].destination, destination) == 0) {
            found = 1;
            printf("ID: %d\n", A[i].id);
            printf("DESTINATION: %s\n", A[i].destination);
            printf("DEPART: %s\n", A[i].depart);
            printf("AIRPORT: %s\n", A[i].airport);
            printf("CLASS: %s\n", A[i].class);
            printf("PRIX: %.2f\n", A[i].prix);
            printf("DATE DE DEPART: %d/%d/%d\n", A[i].dated.jour, A[i].dated.mois, A[i].dated.annee);
            printf("TEMPS DE DEPART: %d:%d\n", A[i].tempsd.heure, A[i].tempsd.minute);
            printf("TEMPS D'ARRIVEE: %d:%d\n", A[i].tempsa.heure, A[i].tempsa.minute);
            printf("DUREE: %d:%d\n", A[i].duree.heure, A[i].duree.minute);
            printf("\n");
        }
    }

    if (!found) {
        printf("NO TRIPS FOUND FROM %s TO %s!", depart, destination);
    }
}

void search_trips_by_date(voyage A[], int CPT, char destination[], int jour, int mois, int annee) {
    int i;
    int found = 0;

    printf("SEARCHING FOR TRIPS FROM %s ON %d/%d/%d\n\n", destination, jour, mois, annee);

    // Search for trips from the specified destination on the specified date
    for (i = 0; i < CPT; i++) {
        if (strcmp(A[i].depart, destination) == 0 && A[i].dated.jour == jour && A[i].dated.mois == mois && A[i].dated.annee == annee) {
            found = 1;
            printf("ID: %d\n", A[i].id);
            printf("DESTINATION: %s\n", A[i].destination);
            printf("DEPART: %s\n", A[i].depart);
            printf("AIRPORT: %s\n", A[i].airport);
            printf("CLASS: %s\n", A[i].class);
            printf("PRIX: %.2f\n", A[i].prix);
            printf("DATE DE DEPART: %d/%d/%d\n", A[i].dated.jour, A[i].dated.mois, A[i].dated.annee);
            printf("TEMPS DE DEPART: %d:%d\n", A[i].tempsd.heure, A[i].tempsd.minute);
            printf("TEMPS D'ARRIVEE: %d:%d\n", A[i].tempsa.heure, A[i].tempsa.minute);
            printf("DUREE: %d:%d\n", A[i].duree.heure, A[i].duree.minute);
            printf("\n");
        }
    }

    if (!found) {
        printf("NO TRIPS FOUND FROM %s ON %d/%d/%d!", destination, jour, mois, annee);
    }
}

void print_all_trips(voyage A[], int CPT) {
    int i;
    for (i = 0; i < CPT; i++) {
        printf("ID: %d\n", A[i].id);
        printf("Destination: %s\n", A[i].destination);
        printf("Depart: %s\n", A[i].depart);
        printf("Airport: %s\n", A[i].airport);
        printf("Class: %s\n", A[i].class);
        printf("Price: %.2f\n", A[i].prix);
        printf("Departure date: %d/%d/%d\n", A[i].dated.jour, A[i].dated.mois, A[i].dated.annee);
        printf("Departure time: %d:%d\n", A[i].tempsd.heure, A[i].tempsd.minute);
        printf("Arrival time: %d:%d\n", A[i].tempsa.heure, A[i].tempsa.minute);
        printf("Duration: %d:%d\n", A[i].duree.heure, A[i].duree.minute);
        printf("\n");
    }
    getch();
}

int main(){
    voyage A[100];
    int choix=0,trip_id;
    char ch[10];
    char depart[100];
    char destination[100];
    int CPT =0;
    float prixinf;
    float prixsup;

    while(choix != 8)
    {
/********** Affichage du menu **********/
        do
        {
            system("cls");
            printf("\nTRAVEL MANAGER APP\n");
            printf("\n* 1 *\tAjouter un voyage");
            printf("\n* 2 *\tModifier un voyage");
            printf("\n* 3 *\tSupprimer une voyage");
            printf("\n* 4 *\tRechercher des voyages disponibles selon des dates precises");
            printf("\n* 5 *\tRechercher des voyages disponibles selon un intervale de prix");
            printf("\n* 6 *\tRechercher des voyages disponibles selon la ville de depart et ville d'arrivee");
            printf("\n* 7 *\tAfficher tous les voyages");
            printf("\n* 8 *\tQuitter le programme");
            printf("\n\nSaisissez votre choix : ");
            fflush(stdin);
            choix=atoi(gets(ch));
        } while( (choix<1)||(choix>8) );
        switch(choix) {
            case 1 ://ajout d'un voyage
            {
                system("cls");
                add_trip(A, &CPT);
                break;
            }
            case 2 ://modification d'un voyage
            {
                system("cls");
                printf("\nENTER TRIP ID TO MODIFY: ");
                scanf("%d", &trip_id);
                modify_trip(A, CPT, trip_id);
                getch();
                break;
            }
            case 3 ://suppression d'un voyage
            {
                system("cls");
                delete_trip(A, &CPT);
                break;
            }
            case 4 ://recherche des voyages disponibles selon des dates précises
            {
                system("cls");
                char destination[100];
                int jour, mois, annee;
                char ch[10];
                printf("SEARCH FOR TRIPS BY DATE\n\n");
                printf("Enter destination: ");
                fflush(stdin);
                gets(destination);
                printf("Enter date (dd/mm/yyyy): ");
                fflush(stdin);
                gets(ch);
                sscanf(ch, "%d/%d/%d", &jour, &mois, &annee);
                search_trips_by_date(A, CPT, destination, jour, mois, annee);
                getch();
                break;
            }
            case 5 ://recherche des voyages disponibles selon un intérvale de prix
            {
                system("cls");
                printf("\nMINIMUM PRICE: ");
                scanf("%f", &prixinf);
                printf("MAXIMUM PRICE: ");
                scanf("%f", &prixsup);
                search_by_price(A, CPT, prixinf, prixsup);
                getch();
                break;
            }
            case 6 ://recherche des voyages disponibles selon la ville de départ et ville d'arrivée
            {
                system("cls");
                printf("\nENTER DEPARTURE CITY: ");
                fflush(stdin);
                gets(depart);
                printf("\nENTER DESTINATION CITY: ");
                fflush(stdin);
                gets(destination);
                search_trips(A, CPT, depart, destination);
                getch();
                break;
            }
            case 7://Afficher tous les voyages
            {
                system("cls");
                printf("VIEW ALL TRIPS\n\n");
                print_all_trips(A, CPT);
                getch();
                break;
            }
            case 8 ://quitter le programme
            {
                system("cls");
                printf("\nA BIENTOT !");
                break;
            }
                default :
                    printf("\nErreur de saisie !");
                break;

        }
    }
    return 0;
}