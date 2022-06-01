#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "pr_queue_functions.h"

                            /// SYED ARSALAN KHAN
                            /// FA19-BCE-010


struct element pr_dequeue(struct node ** qfront)
{
    if(*qfront == NULL) /// if a dequeue operation is sought when the queue is already empty
    {
        printf("The queue was empty. Returning garbage data! \n\n");
        struct element temp;
        return(temp);
    }
    struct element temp = (*qfront)->data;   /// I copy the data at the front node into a temporary variable

    struct node * ptr_temp = (*qfront)->next;

    free(*qfront);
    *qfront = ptr_temp;

    return(temp);

}

void pr_enqueue(struct node ** qrear, struct node ** qfront, struct element new_data, int priority)
{
    /* Complete this function*/
    int d;
    struct node *p;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node -> data = new_data;
    new_node -> node_priority = priority;
    //new_node -> next = NULL;

    if(*qfront == NULL)
    {
        new_node ->next = *qfront;
        *qfront = new_node;
        *qrear = *qfront;
    }
    else
    {
        p = *qfront;
        while(p->next != NULL && p->next->node_priority <= priority)
            p = p->next;
        new_node -> next = p -> next;
        p->next = new_node;
    }
}

/* Function returns true if the queue is empty false otherwise*/
int pr_isEmpty(struct node ** qfront)
{
    return(*qfront == NULL);
}
