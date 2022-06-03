#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 16  /// 16, 128, 1024, etc

#define BUBBLE_SORT     1
#define SELECTION_SORT  2
#define INSERTION_SORT  3
#define MERGE_SORT      4

void print_array(int * ptr_array, int size);
void sort_array(int * ptr_array, int size, int sort_type);
void merge_sort_array(int * ptr_array, int size, int index);
void merge(int * ptr_arrA, int sizeA, int * ptr_arrB, int sizeB);
int main()
{
    srand((unsigned int)time(NULL));    /// Random number generator seeded with value of time

    /** Initialize an Integer Array and initialize it with random numbers between 0-999 **/
    int my_array[ARRAY_SIZE];

    for(int i=0; i<ARRAY_SIZE; i++)
    {
        my_array[i] = rand()%1000;
    }
    /*************************************************************************************/

    /// to store execution time of code
	double time_spent = 0.0;

	clock_t begin = clock();

	/// do the sorting part here
	sort_array(my_array,ARRAY_SIZE,BUBBLE_SORT);

	clock_t end = clock();

	print_array(my_array, ARRAY_SIZE);
	/// calculate elapsed time by finding difference (end - begin) and
	/// dividing the difference by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n\nTime elpased is %lf seconds", time_spent);

    return 0;
}

void print_array(int * ptr_array, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%3d\t", *(ptr_array+i));

    }
}

void sort_array(int * ptr_array, int arr_size, int sort_type)
{

    switch(sort_type)
    {
        case BUBBLE_SORT:
        /****************** Implement Bubble Sort Here *************************/
         for(int k = arr_size; k>0; k--)    /// Outer loop moves the partition between the
         {                                  /// sorted and un-sorted sub-arrays.
            for(int i=0; i<k-1; i++)
            {
                if(*(ptr_array+i)>*(ptr_array+i+1)) /// If item on the left is greater than the one on the right
                {
                    int temp = *(ptr_array+i+1);    /// Swap them.
                    *(ptr_array+i+1) = *(ptr_array+i);
                    *(ptr_array+i) = temp;
                }
            }
        }
        /***********************************************************************/
        break;

        case SELECTION_SORT:
        /****************** Implement Selection Sort Here **********************/
        for(int i = 0; i < arr_size; i++)
        {
            for(int j = i+1; j< arr_size; j++)
            {
                if(*(ptr_array + i) > *(ptr_array+j))
                {
                    swap(&ptr_array[i], &ptr_array[j]);
                }
            }
        }
        /***********************************************************************/
        break;

        case INSERTION_SORT:
       /**************** Implement Insertion Sort Here ************************/
       {
        int flag = 0, i, j;
       for (i = 1 ; i <= arr_size - 1; i++) {
            int t = ptr_array[i];

            for (j = i - 1 ; j >= 0; j--) {
                if (ptr_array[j] > t) {
                    ptr_array[j+1] = ptr_array[j];
                    flag = 1;
                }
                else
                    break;
            }
            if (flag)
                ptr_array[j+1] = t;
        }
        /***********************************************************************/
        break;
       }
        case MERGE_SORT:
        /**************** Call Merge Sort Function Here ************************/

        merge_sort(ptr_array, arr_size);

        /***********************************************************************/
        break;
    }


}


/// POST LAB
void merge_sort(int * ptr_array, int array_size)
{
    if(array_size == 1)     /// Base case here
        return;

    int size1 = array_size/2;
    int size2;

    if(array_size % 2 == 1)     /// We are also tackling the case where the array size is not even
        size2 = (array_size/2)+1;
    else
        size2 = (array_size/2);

    merge_sort(ptr_array, size1);
    merge_sort(ptr_array+(array_size/2), size2);


    merge(ptr_array, size1, ptr_array+(array_size/2), size2);
    return;

}

void merge(int * ptr_arrA, int sizeA, int * ptr_arrB, int sizeB)
{

    int * ptr_arrC = (int *) malloc(sizeof(int)*(sizeA+sizeB));  /// Array of integers to temporarily hold the sorted data

    int indexA = 0;     /// to keep track of the elements in A
    int indexB = 0;     /// to keep track of the elements in A
    int indexC = 0;

    while((indexA < sizeA)&&(indexB<sizeB))
    {
        if((*(ptr_arrA+indexA)) > (*(ptr_arrB+indexB)))     /// if elemnt in A is greater than element in B
        {
            *(ptr_arrC + indexC) =  *(ptr_arrB+indexB);     /// Place the smaller element at the start of C
            indexB ++;
            indexC ++;
        }
        else
        {
            *(ptr_arrC + indexC) =  *(ptr_arrA+indexA);     /// Place the smaller element at the start of C
            indexA ++;
            indexC ++;
        }
    }

    /// At this stage either A or B will have no elements left
    while(indexA < sizeA)
    {
        *(ptr_arrC + indexC) =  *(ptr_arrA+indexA);
         indexA ++;
         indexC ++;
    }

    while(indexB < sizeB)
    {
        *(ptr_arrC + indexC) =  *(ptr_arrB+indexB);
         indexB ++;
         indexC ++;
    }

    /// Now the elements are in sorted order in C.
    /// Time to plug them back into the original array

    for(indexA = 0, indexB = 0; indexA < indexC; indexA++, indexB++)
        *(ptr_arrA+indexA) = *(ptr_arrC + indexB);

    free(ptr_arrC);  /// Delete the previously allocated memory
    return;
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

