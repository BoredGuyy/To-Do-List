#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef enum
{
    Basse = 1,
    Moyenne,
    Haute
}Priorite;

typedef struct tm DueDate;

typedef struct
{
    char titre[100];
    Priorite priorite;
    DueDate dueDate;
    int status;
}Tache;

Tache taches[50];
int tache_Num = 0;

void ajouterTache()
{
    system("clear");
    if(tache_Num >= 50)
    {
        printf("Can't add any more tasks, List is full!\n");
        return;
    }

    printf("Enter Task title: ");
    scanf(" %[^\n]", taches[tache_Num].titre);


    printf("Enter the priority (1. Low, 2. Medium, 3. High): ");
    scanf("%d", (int*)&taches[tache_Num].priorite);

    printf("Enter Due date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &taches[tache_Num].dueDate.tm_mday, &taches[tache_Num].dueDate.tm_mon, &taches[tache_Num].dueDate.tm_year);

    taches[tache_Num].status = 0;

    tache_Num++;
    printf("Task added successfuly!\n");
}

void afficherTaches()
{
    system("clear");

    if (tache_Num == 0)
    {
        printf("No tasks to Display yet!\n");
        return;
    }

    printf("\n-------------------- Tasks: ----------------------------------\n\n");
    for (int i = 0; i < tache_Num; i++)
    {
        printf("%d - Task Description: %s - Task Priority: %s - Task Due Date: %02d/%02d/%d - Task Status: %s\n\n",i , taches[i].titre, ((int)taches[i].priorite == 1) ? "Low" : ((int)taches[i].priorite == 2) ? "Average" : ((int)taches[i].priorite == 3) ? "High" : "Unknown", taches[i].dueDate.tm_mday, taches[i].dueDate.tm_mon, taches[i].dueDate.tm_year, (taches[i].status == 0) ? "Not Done" : "Done");
    }
    printf("----------------------------------------------------------------\n");
}

void modifierTache()
{
    system("clear");
    if (tache_Num == 0)
    {
        printf("No tasks to modify yet!\n");
        return;
    }

    afficherTaches();
    
    int choice;
    printf("Task number to modify: ");
    scanf("%d", &choice);

    if (choice < 0 || choice >= tache_Num)
    {
        printf("Error! There is no task with the number you entered\n");
        return;
    }
    
    printf("Enter New Task title: ");
    scanf(" %[^\n]", taches[tache_Num].titre);

    printf("Enter New priority (1. Low, 2. Medium, 3. High): ");
    scanf("%d", (int*)&taches[choice].priorite);

    printf("Enter New Due date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &taches[choice].dueDate.tm_mday, &taches[choice].dueDate.tm_mon, &taches[choice].dueDate.tm_year);

    printf("Task modified successfuly!\n");
}

void supprimerTache()
{
    system("clear");
    if(tache_Num <= 0)
    {
        printf("There are no tasks to delete!\n");
        return;
    }

    afficherTaches();

    int choice;
    printf("Enter task number to be deleted: ");
    scanf("%d", &choice);

    if (choice < 0 || choice >= tache_Num)
    {
        printf("Error! there is no task with the number you entered!\n");
        return;
    }

    for (int i = choice; i < tache_Num - 1; i++)
    {
        taches[i] = taches[i + 1];
    }
    tache_Num--;

    printf("Task deleted successfuly!\n");    
}

void filtrage()
{
    system("clear");
    if (tache_Num == 0)
    {
        printf("No tasks to filter yet!\n");
        return;
    }

    printf("\nFiltrage option:\n");
    printf("1- Filter by Priority\n");
    printf("2- Filter by Due Date\n");
    
    int choice;
    scanf("%d", &choice);

    if(choice == 1)
    {
        system("clear");
        int priorite;
        printf("Priorite You want to filter with: (1. Low, 2. Average, 3.High): ");
        scanf("%d", &priorite);

        printf("\n-------------------- Tasks: ----------------------------------\n\n");
        for (int i = 0; i < tache_Num; i++)
        {
            if(priorite == taches[i].priorite)
                printf("%d - Task Description: %s - Task Priority: %s - Task Due Date: %02d/%02d/%d - Task Status: %s\n\n",i , taches[i].titre, ((int)taches[i].priorite == 1) ? "Low" : ((int)taches[i].priorite == 2) ? "Average" : ((int)taches[i].priorite == 3) ? "High" : "Unknown", taches[i].dueDate.tm_mday, taches[i].dueDate.tm_mon, taches[i].dueDate.tm_year, (taches[i].status == 0) ? "Not Done" : "Done");
        }
        printf("\n--------------------------------------------------------------\n\n");
        
    }
    else if(choice == 2)
    {
        system("clear");
        typedef struct tm Date;
        Date date;
        printf("Enter Date to sort with (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &date.tm_mday, &date.tm_mon, &date.tm_year);

        printf("\n-------------------- Tasks: ----------------------------------\n\n");
        for(int i = 0; i < tache_Num; i++)
        {
            if(date.tm_mday == taches[i].dueDate.tm_mday && date.tm_mon == taches[i].dueDate.tm_mon && date.tm_year == taches[i].dueDate.tm_year)
                printf("%d - Task Description: %s - Task Priority: %s - Task Due Date: %02d/%02d/%d - Task Status: %s\n\n",i , taches[i].titre, ((int)taches[i].priorite == 1) ? "Low" : ((int)taches[i].priorite == 2) ? "Average" : ((int)taches[i].priorite == 3) ? "High" : "Unknown", taches[i].dueDate.tm_mday, taches[i].dueDate.tm_mon, taches[i].dueDate.tm_year, (taches[i].status == 0) ? "Not Done" : "Done");
        }
        printf("\n--------------------------------------------------------------\n\n");
    }
}

void marqueTache()
{
    system("clear");
    if(tache_Num <= 0)
    {
        printf("There are no tasks yet!\n");
        return;
    }

    afficherTaches();

    int choice;
    printf("Task number to modify: ");
    scanf("%d", &choice);

    if (choice < 0 || choice > tache_Num) {
        printf("Erreur! Il n'y a pas de tâche avec le numéro que vous avez saisi.\n");
        return;
    }

    taches[choice].status = 1;

    printf("Task successufly marked Done\n");
}

void start()
{
    system("clear");
    int choice;

    do {
        printf("------------------ TO DO LIST ------------------\n\n");
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Modify Task\n");
        printf("3. Delete Task\n");
        printf("4. Filter Task\n");
        printf("5. Display Tasks\n");
        printf("6. Marque a Task as Done\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: ajouterTache(); break;
            case 2: modifierTache(); break;
            case 3: supprimerTache(); break;
            case 4: filtrage(); break;
            case 5: afficherTaches(); break;
            case 6: marqueTache(); break;
            case 7: printf("\nGood Bye!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choice != 7);
}

int main(int argc, char const *argv[])
{
          start();

    return 0;
}
