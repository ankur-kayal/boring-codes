#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left,*right;
}Node;

Node *create(int val) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node *insert(Node *tree, int val) {
    if(tree == NULL) {
        return create(val);
    }
    else if(val < tree->data) {
        tree->left = insert(tree->left , val);
    }
    else if(val > tree -> data) {
        tree->right = insert(tree->right , val);
    }
    else {
        printf("\n%d already exists in the BST!!\n" , val);
    }
    return tree;
}

void display(Node *tree) { 
    if(tree != NULL) {
        display(tree->left);
        printf("%d " , tree->data);
        display(tree->right);
    }
}

int main() {
    int ch, val, created, cont;
    created = 0;
    cont = 1;
    Node *tree;
    
    while(cont) {
        printf("\n1. Creates a BST");
        printf("\n2. Inserts elements into the BST");
        printf("\n3. Displays the elements of the BST");
        printf("\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: 
                if(created == 0) {
                    created = 1;
                    tree = NULL;
                    printf("\nBST created\n");
                }
                else {
                    printf("\nBST already exists!!\n");
                }
                break;
            case 2:
                if(created == 0) {
                    printf("\nBST not yet created! Try again.\n");
                }
                else {
                    printf("\nEnter the element to be inserted: ");
                    scanf("%d", &val);
                    tree = insert(tree, val);
                }
                break;
            case 3:
                if(created == 0) {
                    printf("\nBST not yet created! Try again.\n");
                }
                else {
                    if(tree == NULL) {
                        printf("\nBST is empty!!\n");
                    }
                    else {
                        printf("\nThe elements of the BST are :\n");
                        display(tree);
                        printf("\n\n");
                    }
                }
                break;
            case 4:
                cont = 0;
                break;
            default:
                printf("\nWrong choice entered! Try again!\n");
        }
    }
}