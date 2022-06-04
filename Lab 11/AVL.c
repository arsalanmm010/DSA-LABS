#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "node.h"
#include "AVL.h"
#define MAXCHAR 1000

bool bst_search(struct node * root, int key)
{
    /** Complete this function */
    if(root == NULL)
        return false;
    else if(key < root->data)
        return bst_search(root->left, key);
    else if(key > root->data)
        return bst_search(root->right, key);
    else
        return true;

}

struct node * insert(struct node *T,int x)
{
	if(T==NULL)
	{
		T=(struct node*)malloc(sizeof(struct node*));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)		// insert in right subtree
		{
			T->right=insert(T->right,x);
			if(BF(T)==-2)
				if(x>T->right->data)
					T=RR(T);
				else
					T=RL(T);
		}
		else
			if(x<T->data)
			{
				T->left=insert(T->left,x);
				if(BF(T)==2)
					if(x < T->left->data)
						T=LL(T);
					else
						T=LR(T);
			}

		T->ht=height(T);

		return(T);
}

bool delete_node(struct node * root, int data)
{

    /** Complete this function */
    return(false);
}

bool save_in_order(struct node * root, FILE * fptr)
{
    /** Complete this function */
     if(root == NULL)
        return;
	save_in_order(root->left,fptr);
	fprintf(fptr,"%d\t", root->data);
	save_in_order(root->right,fptr);
}

bool save_pre_order(struct node * root, FILE * fptr)
{
    if(root == NULL)
        return;
    fprintf(fptr,"%d\t", root->data);
	save_pre_order(root->left,fptr);
	save_pre_order(root->right,fptr);
}

bool save_post_order(struct node * root, FILE * fptr)
{
    if(root == NULL)
        return;
	save_post_order(root->left,fptr);
	save_post_order(root->right,fptr);
	fprintf(fptr,"%d\t", root->data);
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
            root = insert(root, value);

        }
    }
fclose(fptr);
}

int find_smallest_node(struct node * root)
{
    /** Complete this function */
    struct node * curr= root;
    while(curr != NULL && curr->left != NULL)
        curr = curr -> left;
    return(curr);

}

void print_in_order(struct node * root)
{
    if(root == NULL)
        return;

	print_in_order(root->left);       //Visit left subtree
	printf("%d\t",root->data);  //Print data
	print_in_order(root->right);
}

void print_pre_order(struct node * root)
{
if(root == NULL)
    return;

	printf("%d\t",root->data); // Print data
	print_pre_order(root->left);     // Visit left subtree
	print_pre_order(root->right);    // Visit right subtree

}

void print_post_order(struct node * root)
{
   if(root == NULL)
    return;

	print_post_order(root->left);    // Visit left subtree
	print_post_order(root->right);   // Visit right subtree
	printf("%d\t",root->data); // Print data

}


int height(struct node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);

	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;

	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;

	if(lh>rh)
		return(lh);

	return(rh);
}

struct node * rotateright(struct node *x)
{
	struct node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}

struct node * rotateleft(struct node *x)
{
	struct node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);

	return(y);
}

struct node * RR(struct node *T)
{
	T=rotateleft(T);
	return(T);
}

struct node * LL(struct node *T)
{
	T=rotateright(T);
	return(T);
}

struct node * LR(struct node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);

	return(T);
}

struct node * RL(struct node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}

int BF(struct node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);

	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;

	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;

	return(lh-rh);
}
