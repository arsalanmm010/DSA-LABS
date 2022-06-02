#include <stdio.h>
#include <stdlib.h>
void reverse_string(char * string, int left_index, int right_index);
void swap(char *x, char *y);

                /// SYED ARSALAN KHAN
                /// FA19-BCE-010
                /// BCE-3A
                /// LAB 7 POST LAB

int main()
{
    char string[25];
    printf("Enter a string to reverse: \n\n");
    fgets(string, 25, stdin);
    reverse_string(string, 0, strlen(string) - 1);
    printf("\nThe reversed string is:\n %s\n",string);
}

void reverse_string(char * string, int left_index, int right_index)
{
    if (left_index < right_index)   /// base case
    {
        swap((string+left_index), (string + right_index));  /// swapping characters
        reverse_string(string, left_index + 1, right_index - 1);    /// recursion
    }
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
