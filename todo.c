#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum
{
    Basse = 1,
    Moyenne,
    Haute
}Priorite;

typedef enum
{
    Non_terminee = 0,
    Terminee
}Status;

typedef struct
{
    char titre[100];
    Priorite priorite;
    char date[11];
    Status status;
}Tache;

Tache taches[50];


int main(int argc, char const *argv[])
{
    Tache t1 = {"finish the mini project", 3, "21/03/2023"};
    printf("Description: %s Priority: %d, Date: %s Statue: %d", t1.titre, t1.priorite, t1.date, t1.status);
    
    return 0;
}
