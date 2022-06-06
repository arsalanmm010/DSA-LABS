#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "node.h"
#include "stack_functions.h"

#define NUM_VERTICES 10
/** This function takes a pointer to the
    adjacency matrix of a Graph and the
    size of this matrix as arguments and
    prints the matrix
*/
void print_graph(int * graph, int size);

/** This function takes a pointer to the
    adjacency matrix of a Graph, the size
    of this matrix, the source and dest
    node numbers along with the weight or
    cost of the edge and fills the adjacency
    matrix accordingly.
*/
void add_edge(int * graph, int size, int src, int dst, int cost);


/** This function takes a pointer to the adjacency matrix of
    a graph, the size of this matrix, source and destination
    vertex numbers as inputs and prints out the path from the
    source vertex to the destination vertex. It also prints
    the total cost of this path.
*/
void find_path_dfs(int * graph, int size, int src, int dst);

int main()
{
    int my_graph[NUM_VERTICES][NUM_VERTICES];   /// An adjacency matrix representation of graph
    memset(my_graph,-1,NUM_VERTICES * NUM_VERTICES * sizeof(int));     /// Initiallize with -1 representing infinte cost.

    for(int i=0; i<NUM_VERTICES; i++)
        add_edge(&my_graph[0][0], NUM_VERTICES, i, i, 0);

    add_edge(&my_graph[0][0], NUM_VERTICES, 0, 3, 13);
    add_edge(&my_graph[0][0], NUM_VERTICES, 1, 4, 14);
    add_edge(&my_graph[0][0], NUM_VERTICES, 1, 5, 6);
    add_edge(&my_graph[0][0], NUM_VERTICES, 2, 3, 9);
    add_edge(&my_graph[0][0], NUM_VERTICES, 2, 9, 10);
    add_edge(&my_graph[0][0], NUM_VERTICES, 3, 0, 13);
    add_edge(&my_graph[0][0], NUM_VERTICES, 3, 8, 9);
    add_edge(&my_graph[0][0], NUM_VERTICES, 4, 1, 14);
    add_edge(&my_graph[0][0], NUM_VERTICES, 4, 6, 8);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 1, 6);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 2, 7);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 6, 12);
    add_edge(&my_graph[0][0], NUM_VERTICES, 6, 4, 8);
    add_edge(&my_graph[0][0], NUM_VERTICES, 6, 7, 15);
    add_edge(&my_graph[0][0], NUM_VERTICES, 7, 6, 15);
    add_edge(&my_graph[0][0], NUM_VERTICES, 8, 5, 11);
    add_edge(&my_graph[0][0], NUM_VERTICES, 9, 8, 23);

    print_graph(&my_graph[0][0], NUM_VERTICES);

    find_path_dfs(&my_graph[0][0], NUM_VERTICES, 4, 8);
    //find_path_dfs(&my_graph[0][0], NUM_VERTICES, 9, 2);
    getchar();
    return 0;
}

void add_edge(int * graph, int size, int src, int dst, int cost)
{
    *(graph+(src*size+dst)) = cost;
}

void print_graph(int * graph, int size)
{
    //char vertices[size];
    for(int i=0; i<size; i++)
    {
        //vertices[i] = 'A'+i;
        //printf("\t%c", vertices[i]);
        printf("\t%d", i);
    }
    printf("\n\n");
    for(int x=0; x<size; x++)
    {
        //printf("%c\t", vertices[x]);
        printf("%d\t", x);
        for(int y=0; y<size; y++)
            printf("%d\t", *(graph+(x*size+y)));
        printf("\n");
    }
}


void find_path_dfs(int * graph, int size, int src, int dst)
{
    int visited[NUM_VERTICES] = {0};  /// To keep track of all the visited nodes

    /********** We make a stack for holding the visited vertices *****************/

    struct node * top = NULL;   /// This is the top of the stack

    /** The DFS will work as follows:
        1. Visit src vertex. Set 'current_visiting' to src.
        2. Explore this vertex.
            If it is the destination vertex, stop.
            Otherwise visit its first unvisited neighbour (add to stack the current vertex)
            If no unvisited neighbour vertex remains, go back (pop from stack)
        3. Repeat 2*/

    int crnt_visiting = src;
    int crnt_exploring = src;
    int path_cost = 0;
    bool PATH_FOUND = false;
    while(!PATH_FOUND)
    {
        visited[crnt_visiting] = 1; /// Now we have visited this node
        struct element temp;// = {0,0};

        if(crnt_visiting == dst)
        {
            printf("\nPath found: ");
            printf("\nCost: %d\n", path_cost);
            while(!isStackEmpty(&top))
            {
                printf("Pop\n");
                pop(&top);
            }
            PATH_FOUND = true;
            continue;
        }
        else    /// Explore this vertex
        {
            printf("\nNow Exploring: %d\n", crnt_exploring);
            /// now crnt_visiting will have the vertex numbe
            crnt_visiting = 0;
            while(crnt_visiting < size)
            {
                if((*(graph+(crnt_exploring*size+crnt_visiting)) <= 0) || (visited[crnt_visiting] == 1))
                    crnt_visiting ++;
                else
                    break;
            }

            if(crnt_visiting == size)   /// no unvisted node to visit
            {
                temp = pop(&top);
                crnt_exploring = temp.vertex_num;
                path_cost = temp.cost_to_visit;
            }
            else
            {
                printf("\nNow visiting: %d\n", crnt_visiting);
                /// now crnt_visiting will have the vertex number of an unvisited neighbour.

                printf("Pushing: %d with path cost: %d\n", crnt_exploring, path_cost);
                temp.vertex_num = crnt_exploring;
                temp.cost_to_visit = path_cost;
                push(&top, temp);
                path_cost += *(graph+(crnt_exploring*size+crnt_visiting));
                crnt_exploring = crnt_visiting;
            }
        }
    }


}
