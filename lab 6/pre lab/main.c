#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "queue_functions.h"

struct node **qfront, **qrear;
struct element q;
int main()
{
    int option;
    struct element new_data;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("enter data to add to queue: \n");
                scanf("%d", &new_data);
                q_insert(&qrear, &qfront, new_data);
                break;
            case 2:
                q_delete(&qfront);
                break;
            case 3:
                new_data = q_peek(&qfront);
                if(q_isEmpty(&qfront) == false)
                    printf("\n The value at front of queue is : %d", new_data);
                break;
            case  4:
                q = display(&qfront);
                break;
        }
    }
    while(option != 5);
    return 0;
}
