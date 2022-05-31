#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

                /// SYED ARSALAN KHAN
                /// FA19-BCE-010
                /// LAB 5 IN LAB


struct node {
     int data;
     struct node *next;
};


int stk[MAX];
int TOP = -1;
struct node *new_node, *top, *temp;

void push( int a);
int pop(void);
void print_stack(struct node *top);
void peek(struct node *top);
int isBalanced(char  *ptr_array);
void reverse_num_array();



int main()
{
    int choice,val,dat;
    while(1)
    {
        printf("\n\nPlease enter your choice: \n");
        printf("1. Add a new value (PUSH) \n");
        printf("2. Delete a value (POP) .\n");
        printf("3. print stack. \n");
        printf("4. peek stack. \n");
        printf("5. Reverse array. (IN LAB TASK 1) \n");
        printf("6. Check if mathematical expression is balanced or not. (IN LAB TASK 2) \n");
        printf("7. exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter value: \n");
                scanf("%d", &val);
                push(val);
                printf("Value pushed successfully. \n");
                break;
            }
            case 2:
            {
                dat = pop();
                printf("the popped value is %d \n", dat);
                break;
            }
            case 3:
            {
                print_stack(top);
                break;
            }
            case 4:
            {
                peek(top);
                break;
            }
            case 5:
            {
                reverse_num_array();
                break;
            }
            case 6:
            {
                int s;
                char *ptr_array;
                s = isBalanced(ptr_array);
                printf("%d",s);
                break;
            }
            case 7:
            {
                exit(1);
            }
        }
    }
return(0);
}


void push(int a)
{
    if(top == NULL)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = a;
        new_node->next = NULL;
        top = new_node;
    }
    else
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = a;
        new_node->next = top;
        top = new_node;
    }
}


void push_2(char c)
{
    if(TOP == MAX-1)
        printf("Stack Overflow\n");
    else
    {
        TOP=TOP+1;
        stk[TOP] = c;
    }
}



char pop_2()
{
    if(TOP == -1)
        printf("\n Stack Underflow");
    else
        return(stk[TOP--]);
}

int pop(void)
{
    struct node *temp;
    temp = top;
    int dat = top->data;
    top = top->next;
    free(temp);
    return dat;
}

void print_stack(struct node *top)
{
    struct node *temp;
    if (top == NULL)
    {
        printf("\n\n the stack is empty. \n\n");
    }
    else
    {
        temp = top;
        printf("Stack: ");
        while(temp!=NULL)
        {
            printf("\n%d\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek(struct node *top)
{
    if(top == NULL)
        printf("Stack is empty\n");
    else
        printf("The top is %d\n", top->data);
}


void reverse_num_array()
{
    int val, n, i,
    arr[10];
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array : ");
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    for(i=0;i<n;i++)
        push(arr[i]);
    for(i=0;i<n;i++)
    {
        val = pop();
        a[i] = val;
    }
    printf("\n The reversed array is : \n");
    for(i=0;i<n;i++)
    printf("\n %d", a[i]);
}


int isBalanced(char * ptr_array)
{
    char exp[MAX],temp;
    int i, flag=1;
    printf("Enter an expression : ");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push_2(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            if(TOP == -1)
                flag=0;
            else
            {
                temp=pop_2();
                if(exp[i]==')' && (temp=='{' || temp=='['))
                    flag=0;
                if(exp[i]=='}' && (temp=='(' || temp=='['))
                    flag=0;
                if(exp[i]==']' && (temp=='(' || temp=='{'))
                    flag=0;
            }
    }
    if(TOP>=0)
        flag=0;
    if(flag==1)
        return 0;
    else
        return 1;
}
