# To Do Liste with C


#### Application console de gestion des tâches qui permet à l'utilisateur de: 

* Ajouter, modifier et supprimer des tâches.
* Filtrer les tâches par priorité ou par date d'échéance.
* Afficher de manière organisée toutes les tâches ajoutées.
* Marquer les tâches comme terminées.

## Links

[main code](https://github.com/yas0se/todo/blob/main/main.c)


## Images

![image](https://github.com/yas0se/todo/assets/128167310/9ab0464a-557f-44bd-aad1-1ec370df9fb9 "Menu")

![image](https://github.com/yas0se/todo/assets/128167310/141e689c-f4ab-4373-8714-da2b99139ce2 "liste de taches")


## Blocks of code

```
    do{
    printf("Please choose an option\n");
    printf("1. Enter a task \n");
    printf("2. Mark Task as Completed \n");
    printf("3. List all tasks\n");
    printf("4. delete Task\n");
    printf("5. modify Task\n");
    printf("6. filter Tasks By Priority\n");
    printf("7. Exit\n");
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
                modifyTask();
                break;
            case 6:
                printf("define Priority (1 - 10): \n ");
                scanf("%d", &p);
                filterTasksByPriority(p) ;
                break;
            case 7:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while(choice != 7);
```
