#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_NODES 7
#define EMPTY   1000  /// for Max-Heaps change to -1

struct heap_struct
{
    unsigned int max_heap_size;
    unsigned int crnt_heap_size;

    int * elements;
};

/***** Prototypes here *****/
struct heap_struct * create_heap(unsigned int max_elements);
bool is_full(struct heap_struct * H);
void insert_node(int x, struct heap_struct * H);
void print_heap(struct heap_struct * H);
int delete_root(struct heap_struct * H);
void swap_ref(int * x, int * y);

int main(void)
{

    srand((unsigned int)time(NULL));    /// Random number generator seeded with value of time

    int my_array[NUM_NODES];

    int i = 0;
    int j = 0;

    printf("\nArray:\t\t");
    while(i < NUM_NODES)   /// Fill my_array with unique values ranging from 0 to 99
    {
        int temp = rand() % 100;

        for(j=0; j<i; j++)
        {
            if(temp == my_array[j]) /// The number already exists in the array
            break;
        }

        if(j == i)     /// temp was not found in the array
        {
            my_array[i] = temp;
            printf("%d\t", my_array[i]);
            i++;
        }
    }

    /// Build a new heap

    struct heap_struct * Heap = NULL;

    Heap = create_heap(NUM_NODES);

    for(int i = 0; i<NUM_NODES; i++)
    {
        insert_node(my_array[i], Heap);
    }
    printf("\nHeap:\n");
    print_heap(Heap);

    int arr[NUM_NODES] = {0};
    int f = NUM_NODES-1;
    while(Heap->crnt_heap_size != 0)
    {
    arr[f] = delete_root(Heap);
    printf("\nDeleted value: %d", arr[f]);
    print_heap(Heap);

    f--;
    }

    printf("sorted array\n");
    for(int i=0; i<NUM_NODES; i++)
    printf("%d\n",arr[i]);


    return 0;
}

struct heap_struct * create_heap(unsigned int max_elements)
{

    struct heap_struct * H;

    H = (struct heap_struct *) malloc(sizeof(struct heap_struct));

    if(H == NULL)
    {
        printf("\nFatal Error!! Out of memory!!\n");
        exit(-1);
    }

    /// Allocate the space for Array plus 1 for senital
    H->elements = (int *) malloc(sizeof(int) * (max_elements+1));
    if(H->elements == NULL)
    {
        printf("\nFatal Error!! Out of memory!!\n");
        exit(-1);
    }
    H->max_heap_size = max_elements;
    H->crnt_heap_size = 0;

    for(int x=0; x<=NUM_NODES; x++) /// Fill the array with Empty values (1000 or -1)
        H->elements[x] = EMPTY;

    return H;
}

void insert_node(int x, struct heap_struct * H)
{
    unsigned int i;

    if(is_full(H))
    {
        printf("\nError! Heap is full !!\n");
        return;
    }
    else
    {
        i = ++ H->crnt_heap_size;
        H->elements[i] = x;         /// Insert the item in the first available position.

        while(((H->elements[i] > H->elements[i/2])) && (i != 0))    /// Then move it up to its correct position
        {
            swap_ref(&(H->elements[i]), &(H->elements[i/2]));
            i = i/2;
        }


    }
    }

bool is_full(struct heap_struct * H)
{
    return((H->crnt_heap_size) == (H->max_heap_size));
}

void print_heap(struct heap_struct * H)
{
    printf("\nHeap Capacity: %d", H->max_heap_size);
    printf("\nHeap Size: %d", H->crnt_heap_size);
    printf("\nHeap Data:\t");
    for(int i = 1; i <= H->crnt_heap_size; i++)
        printf("%d\t", H->elements[i]);
    printf("\n");
}

int delete_root(struct heap_struct * H)     /// Also returns the value of root to calling function
{
    int index = H->crnt_heap_size;

    /// Now 'index' contains the index of the last node

    int root = H->elements[1];  /// We will return this value at the end of this function
    H->elements[1] = H->elements[index];  /// Replace the root with the last node
    H->elements[index] = NULL;           /// Make the last slot empty

    /// Sink this value down till the heap property is satisfied
    int i = 1;

    /** While this newly promoted 'root' is larger than any of its children
        we will continue to swap it with the smaller of the two siblings
        until the heap property (node being smaller than all its children)
        is satisfied.
    **/

    while(i<=H->crnt_heap_size/2)   /// We just need to check the siblings of the 2nd last level
    {
        if(((H->elements[i])<(H->elements[2*i])) || ((H->elements[i])<(H->elements[(2*i)+1])))
        {
            if((H->elements[2*i]) < (H->elements[(2*i)+1]))  /// If the left child node is larger than the right child
            {
                swap_ref(&(H->elements[i]), &(H->elements[(2*i)+1]));
                i = (2*i)+1;
            }
            else
            {
                swap_ref(&(H->elements[i]), &(H->elements[2*i]));
                i = 2*i;
            }
        }
        else
            break;

    }
    H->crnt_heap_size --;           /// Now there is one less item in the heap.
    return(root);
}

void swap_ref(int * x, int * y)
{
    int temp = * y;
    *y = *x;
    *x = temp;
}
