#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 30
#define MAX_TASK_NAME_LENGTH 50

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    char deadline[11];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(){
    if(numTasks < MAX_TASKS){
        printf("Entrez le nom de la tache: ");
        scanf("%s", tasks[numTasks].name);
        printf("Entrez la priorite de la tache (1 - 10): ");
        scanf("%d", &tasks[numTasks].priority);
        printf("Entrez la date d'echeance (YYYY-MM-DD): ");
        scanf("%s", tasks[numTasks].deadline);
        tasks[numTasks].completed = 0;
        numTasks++;
        printf("Tache ajoutee avec succes.\n");
    } else {
        printf("La liste des taches est pleine.\n");
    }
}

void markTaskCompleted(){
    int taskIndex;
    printf("Entrez l'indice de la tache a marquer comme terminee: ");
    scanf("%d", &taskIndex);
    if (taskIndex >= 0 && taskIndex < numTasks) {
        tasks[taskIndex].completed = 1;
        printf("La tache a ete marquee comme terminee.\n");
    } else {
        printf("Indice de tache invalide.\n");
    }
}

void displayTasks(){
    printf("Liste des taches :\n");
    printf("-------------------------------------------------------------\n");
    printf("Nom de la tache   | Priorite | Date d'echeance | Terminee\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%-18s | %-8d | %-15s | %s\n", tasks[i].name, tasks[i].priority, tasks[i].deadline, tasks[i].completed ? "Oui" : "Non");
    }
    printf("-------------------------------------------------------------\n");
}

void deleteTask() {
    int taskIndex;
    printf("Entrez l'indice de la tache a supprimer : ");
    scanf("%d", &taskIndex);
    if (taskIndex >= 0 && taskIndex < numTasks) {
        for (int i = taskIndex; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;
        printf("La tache a ete supprimee avec succes.\n");
    } else {
        printf("Indice de tache invalide.\n");
    }
}

void filterTasksByPriority(int priority) {
    printf("Taches filtrées par priorité %d:\n", priority);
    printf("-------------------------------------------------------------\n");
    printf("Nom de la tache   | Priorite | Date d'echeance | Terminee\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == priority) {
            printf("%-18s | %-8d | %-15s | %s\n", tasks[i].name, tasks[i].priority, tasks[i].deadline, tasks[i].completed ? "Oui" : "Non");
        }
    }
    printf("-------------------------------------------------------------\n");
}

int main()
{
    char name[20];
    int choice, p;
    printf("Welcome to your Todo Manager!\n");
    printf("Please Enter your Name: ");
    scanf("%s", name);
    printf("Hello %s ", name);
    do{
    printf("Please choose an option\n");
    printf("1. Enter a task \n");
    printf("2. Mark Task as Completed \n");
    printf("3. List all tasks\n");
    printf("4. delete Task\n");
    printf("5. filter Tasks By Priority\n");
    printf("6. Exit\n");
    scanf("%d", &choice);
    switch(choice) {
            case 1:
                addTask();
                break;
            case 2:
                markTaskCompleted();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("define Priority (1 - 10): \n ");
                scanf("%d", &p);
                filterTasksByPriority(p) ;
                break;
            case 6:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while(choice != 6);
    return 0;
}
