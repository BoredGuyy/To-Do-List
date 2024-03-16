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

    printf("Task added successfuly!\n");
}

void afficherTaches()
{
    printf("Tasks:\n");
    for (int i = 0; i < tache_Num; i++)
    {
        printf("%d - Task Description: %s - Task Priority: %d - Task Due Date: %s - Task Status: %d\n",tache_Num-1 , taches[i].titre, taches[i].priorite, taches[i].date, taches[i].status);
    }
}

void modifierTache()
{
    afficherTaches();

    if (tache_Num == 0)
    {
        printf("No tasks to modify yet!\n");
        return;
    }
    
    int choice;
    printf("Task number to modify: ");
    scanf("%d", &choice);

    if (choice < 0 || choice >= tache_Num)
    {
        printf("Error! Thre is no task with the number you entered\n");
        return;
    }
    
    printf("Enter New Task title: ");
    scanf("%s", taches[choice].titre);

    printf("Enter New priority (1. Low, 2. Medium, 3. High): ");
    scanf("%d", (int*)&taches[choice].priorite);

    printf("Enter New Due date: ");
    scanf("%s", taches[choice].date);

    printf("Task modified successfuly!\n");
}

int main(int argc, char const *argv[])
{
    ajouterTache();

    modifierTache();
    
    afficherTaches();

    return 0;
}
