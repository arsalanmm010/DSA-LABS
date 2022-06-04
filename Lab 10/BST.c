#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "node.h"
#include "BST.h"
#define MAXCHAR 1000

bool bst_search(struct node * root, int key)
{
    /** Complete this function */
    if(root == NULL)
        return false;
    if(root -> data == key)
        return true;
    if(root -> data < key)
        return bst_search(root -> right, key);
    else
        return bst_search(root -> left, key);
}

bool insert_node(struct node ** ptr, int insert_data)
{
    if(*ptr == NULL) /// We have to insert a new node in the tree now
    {
        struct node * temp = (struct node *) malloc(sizeof(struct node));
        temp->data = insert_data;
        temp->left = NULL;
        temp->right = NULL;
        *ptr = temp;
        printf("\n%d as Root node inserted!", insert_data);
        return(true);
    }

    if(((*ptr)->data > insert_data)) /// data to be inserted to left sub tree
    {
        if((*ptr)->left != NULL)
            insert_node(&(*ptr)->left, insert_data);
        else
        {
            struct node * temp = (struct node *) malloc(sizeof(struct node));
            temp->data = insert_data;
            temp->left = NULL;
            temp->right = NULL;
            (*ptr)->left = temp;
            printf("\n%d inserted to the left of %d!", insert_data, (*ptr)->data);
            return(true);
        }
    }
    else
    {
        if((*ptr)->right != NULL)
            insert_node(&(*ptr)->right, insert_data);
        else
        {
            struct node * temp = (struct node *) malloc(sizeof(struct node));
            temp->data = insert_data;
            temp->left = NULL;
            temp->right = NULL;
            (*ptr)->right = temp;
            printf("\n%d inserted to the right of %d!", insert_data, (*ptr)->data);
            return(true);
        }
    }


    return(true);
}

int delete_node(struct node * root, int data)
{
    /** Complete this function */
     if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (data < root->data)
        root->left = delete_node(root->left, data);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (data > root->data)
        root->right = delete_node(root->right, data);

    // if key is same as root's key,
    // then This is the node
    // to be deleted

    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = find_smallest_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}

bool save_in_order(struct node * root, FILE * fptr)
{
    /** Complete this function */
    if(root == NULL)
        return false;
    if(root != NULL)
    {
        save_in_order(root->left,fptr);
        //fread(root->data,sizeof(struct node *),1 , fptr);
        fprintf(fptr, "%d\t",root->data);
        save_in_order(root->right,fptr);
    }
    return(true);
}
bool save_pre_order(struct node * root, FILE * fptr)
{
    return(false);
}

bool save_post_order(struct node * root, FILE * fptr)
{
    return(false);
}

void load_tree(struct node * root, FILE * fptr)
{
    /** Complete this function */
    char str[MAXCHAR];
    char delim[] = "\t";
    while (fgets(str, MAXCHAR, fptr) != NULL)
    {
        char *ptr = strtok(str, delim);

        while(ptr != NULL)
        {
            int value = atoi(ptr);
            ptr = strtok(NULL, delim);
             if(insert_node(root, value) == true)
             {

             }
             else
             {
                printf("\nData insertion failed!");
             }
        }
    }
fclose(fptr);
}

int find_smallest_node(struct node * root)
{
    /** Complete this function */
    if(root->left == NULL)
        printf("\n Tree empty");
    else
    {
        while(root -> left != NULL)
            root = root -> left;
    }
    return(root);

}


void print_in_order(struct node * ptr)
{
    if(ptr == NULL)
        return;
    if(ptr->left == NULL)   /// Now data of this node will be printed
        printf("%d\t", ptr->data);

    if(ptr->left != NULL)
    {
        print_in_order(ptr->left);
        printf("%d\t", ptr->data);
    }

    if(ptr->right != NULL)
    {
        print_in_order(ptr->right);
    }

    return;
}

void print_pre_order(struct node * root)
{
    /** Complete this function */
    if(root != NULL)
    {
        printf("%d\t", root->data);
        print_pre_order(root -> left);
        print_pre_order(root -> right);
    }
}

void print_post_order(struct node * root)
{
    /** Complete this function */
    if(root != NULL)
    {
        print_post_order(root -> left);
        print_post_order(root -> right);
        printf("%d\t", root -> data);
    }
}
