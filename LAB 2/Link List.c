/******************************************************************************************************
*       Demonstration of making a linked list in C
*
*        The following features will be demonstrated:
*
*        1. Add a new node to the list at the end.
*        2. Print the list
*        3. Search the list for a record

*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "employee.h"



int main()

{
    int choice;

    struct employee * head = NULL; /// Pointer to the first element (head) of the list

    printf("Hello! This program lets you manage your Employees' Database:\n");


    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Insert a new node at the end of the list.");
        printf("\n2. Print the list.");
        printf("\n3. Delete the last item from the list.");
        printf("\n4. Insert a new node after index.");
        printf("\n5. Search the list for a name.");
        printf("\n6. Search the list for age.");
        printf("\n7. print the length of the list" );
        printf("\n8. Exit the menu.\n");




        scanf("%d", &choice);
        flush();
        switch (choice)
        {
            case    1:  /// Add a new node to the list at the end. Create one if empty.
            {
                printf("\nAdding a new node: \n\n");
                insertNodeAtEnd(&head);
                break;
            }

            case    2:  /// Print the list.
            {
                printList(head);
                break;
            }

            case    3:  /// Delete the last it
            {printf("Not implement yet");
                break;
            }
            case    4:  /// Insert a new node after index.
            {
                int idx = 0;
                printf("\nEnter the index after which you want to insert a node: ");
                scanf("%d",&idx);
                flush();
                if(insertNodeAfter(head, idx) == 0)
                    printf("\nNode inserted successfully!");
                else
                    printf("\nIndex exceeds the list length!!\n");

                break;
            }

             case    5:  /// Search the list for a name            {
                printf("\nEnter a name to search: ");
                char searchName[50];
                int idx = 0;
                fgets(searchName, 50, stdin);

                idx = searchNodeByName(head, searchName);
                if(idx == -1)
                    printf("\nName searched for is not found!!\n");
                else
                    printf("\nThe name exists at index %d", idx);

                break;
            }
            case    6:
            {
                printf("\nEnter an age to search: ");
                int search_age,lenght;
                int counter = 0;
                scanf("%d",&search_age);
                struct employee * ptr = head;
                lenght = getListLength(ptr);
                for(int i =0;i < lenght;i++)
                {
                    if(ptr->age == search_age)
                    {
                        printf("\nAge searched is found at index %d!!\n",i);
                    counter++;
                    }
                    ptr = ptr->next;
                }
                if(counter == 0)
                    printf("\nThe searched age is not found!");
                break;
            }
            case    7:
            {
                int list_lenght = 0;
                struct node * ptr = head;
                if(ptr == NULL)
                    printf("\nThe List is empty");
                else
                {
                    list_lenght = getListLength(ptr);
                    printf("\nThe list length is: %d",list_lenght);
                    break;
                }
            }

            case    8:  /// Exit the program.
            {
                printf("\nExiting on user request.\n\n");
                return(0);
            }
        }
    }
    return 0;
}

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


