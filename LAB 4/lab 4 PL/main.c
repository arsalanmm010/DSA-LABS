
                /// SYED ARSALAN KHAN
                /// FA19-BCE-010
                /// LAB 4 POST LAB
                /// JOSEPHUS PROBLEM

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node * next;
    struct node * prev;
};
struct node *head = NULL;

void create();
void display();
int survivor(int);

int main()
{
    int survive,skip;
    create();
    display();
    printf("Enter one greater than the number of persons to be skipped (Enter a number greater than 1)\n");
    scanf("%d",&skip);
    survive = survivor(skip);
    printf("The person to survive is : %d \n",survive);
    free(head);
}

void create()
{
    struct node *temp,*ptr;
    int a,ch;
    do
    {
        printf("Enter a number to add to the list: ");
        scanf("%d",&a);
        temp = (struct node *)malloc(sizeof(struct node)); /// Allocating memory for node temp
        temp -> num = a;    /// Adding numbers to linked list

        if(head == NULL)
        {
            head = temp;
            temp -> next = head;
            temp -> prev = temp -> next;
        }
        else        /// if list has 1 or more than 1 node
        {
            ptr = head;
            while(ptr -> next != head)
            {
                ptr = ptr -> next;
            }
            temp -> prev = ptr;
            ptr -> next = temp;
            temp -> next = head;
            head -> prev = temp;
        }

        printf("Do you want to add another number to add to the list? (if yes type any number or press 0 to exit) ");
        scanf("%d",&ch);
    }
    while(ch!=0);
}

void display()
{
    struct node *temp;
    temp = head;
    do
    {
        printf("%d ",temp -> num);   /// print every number one by one in the list
        temp = temp -> next;
    }
    while(temp != head);
    printf("\n");
}


int survivor(int k)
{
    struct node *p,*q;
    int i;
    p = q = head;
    while(p -> next != p)
    {
        for(i=0; i<k-1; i++)    /// loop will execute k - 1 times(k = number of persons to skip)
        {
            q = p;
            p = p -> next;
        }
        q -> next = p -> next;
        printf("%d has been killed \n",p->num);
        free(p);
        p = q -> next;
    }
    head = p;
    return (p -> num);
}
