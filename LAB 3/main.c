#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Node.h"
#include "SinglyLinkedList.h"

void flush();


                        /// SYED ARSALAN KHAN
                        /// FA19-BCE-010

int main()
{
    int choice;
    char load_choice;
    struct node * head = NULL; /// Pointer to the first node (head) of the list
    //struct node * last = NULL; /// Pointer to the last element of the list

    printf("Hello! This program lets you manage your Employees' Database:\n");

    printf("\nDo you want to load employee database from the file? (y/n): ");
    load_choice = getchar();

    if(load_choice == 'y')
    {
        FILE * fptr = NULL;
        if((fptr=fopen("EmployeeData.txt", "w+")) == NULL)
        {
            printf("\nCannot open file for loading Data!!\n\n");
            exit(1);
        }
        loadListFromFile(&head, fptr);
        fclose(fptr);
    }
    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Insert a new node at the end of the list.");
        printf("\n2. Print the list.");
        printf("\n3. Delete the last item from the list.");
        printf("\n4. Insert a new node after index.");
        printf("\n5. Search the list by Data Field.");
        printf("\n6. Save the list to a file. (Post lab)");  /// post lab task
        printf("\n7. Insert a node at the beginning.  (In lab Task 1(1))");  /// in lab task 1
        printf("\n8. Insert a node before the index.  (In lab Task 1(2))");    /// in lab task 1
        printf("\n9. Delete the first item from the list.  (In lab Task 2(1))");   /// in lab task 2
        printf("\n10. Delete an item after the given index.  (In lab Task 2(2))"); /// in lab task 2
        printf("\n11. Exit the menu.\n");



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

            }

            case    3:  /// Delete the last item from the list
            {
                deleteNodeFromEnd(head);
                printf("\nLast node deleted!!\n");
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

             case    5:  /// Search the list for a Data Field
            {
                int field_choice, idx=0;
                printf("\nEnter a Data Field to search by: (1 - 3)\n");
                printf("\n\t1. Name \n");
                printf("\n\t2. Age \n");
                printf("\n\t3. Basic Salary \n");
                scanf("%d", &field_choice);
                flush();

                idx = searchNodeByData(head, field_choice);

                break;
            }


            case    6:  /// Save list to file
            {
                FILE * fptr = NULL;
                if((fptr=fopen("EmployeeData.txt", "r+")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }

                saveListToFile(head, fptr);
                break;
            }

            case 7:
            {
                printf("\nAdding a new node at start: \n\n");
                insertNodeAtStart(&head);                       /// calling the function
                break;
            }

            case 8:
            {
                int idx = 0;
                printf("\nEnter the index before which you want to insert a node: ");
                scanf("%d",&idx);
                flush();
                if(insertNodeBefore(head, idx) == 0)            /// if function return 0
                    printf("\nNode inserted successfully!");    /// node will be inserted successfully
                else
                    printf("\nIndex exceeds the list length!!\n");  /// if index from user is greater then length of list
                break;
            }

            case 9:
            {
                deleteNodeFromStart(&head);
                printf("First item deleted.\n");
                break;
            }

            case 10:
            {
                int idx;
                printf("Enter the node index after which the node will be deleted: \n");
                scanf("%d",&idx);
                if(deleteNodeAfter(head, idx) == 0)         /// if function return 0
                    printf("Node deleted successfully.\n");
                else if(deleteNodeAfter(head , idx) == 1)       /// if list is empty function returns 1
                    printf("List is empty.\n");
                else
                    printf("index exceeds node limit.\n");
                 break;
            }

            case    11:  /// Exit the program.
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
