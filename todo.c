#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum
{
    Basse = 1,
    Moyenne,
    Haute
}Priorite;

typedef struct
{
    char titre[100];
    Priorite priorite;
    char date[11];
    int status;
}Tache;

Tache taches[50];
int tache_Num = 0;

void ajouterTache()
{
    if(tache_Num >= 50)
    {
        printf("Can't add any more tasks, List is full!\n");
        return;
    }

    printf("Enter Task title: ");
    scanf("%s", taches[tache_Num].titre);

    printf("Enter the priority (1. Low, 2. Medium, 3. High): ");
    scanf("%d", (int*)&taches[tache_Num].priorite);

    printf("Enter Due date: ");
    scanf("%s", taches[tache_Num].date);

    taches[tache_Num].status = 0;

    tache_Num++;

    printf("Task added successfuly");
}

int main(int argc, char const *argv[])
{
    ajouterTache();

    printf("%s | %d | %s | %d", taches[0].titre, taches[0].priorite, taches[0].date, taches[0].status);
    
    
    return 0;
}
