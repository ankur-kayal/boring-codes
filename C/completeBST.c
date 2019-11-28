#include <stdio.h>
#include <stdlib.h>

//A structure to store the information of each node of BST
typedef struct node {
    int data;
    struct node *left,*right;
}Node;

// Global variables that keep track of levels of each leaf node in the BST
int legend[1000];
int level=0;
int ind=0;

//Creates and initializes values to the nodes of the BST
Node *create(int val) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

//Inserts newnodes to the BST in a recursive manner
Node *insert(Node *tree, int val) {
    //When we reach a leaf node of the BST we create and insert a newnode in the BST
    if(tree == NULL) {
        return create(val);
    }
    //If the value to be inserted is less than the value in the current tree node,
    //we traverse the left half of the BST with respect to that node
    else if(val < tree->data) {
        tree->left = insert(tree->left , val);
    }
    //If the value to be inserted is greater than the value in the current tree node,
    //we traverse the right half of the BST with respect to that node
    else if(val > tree -> data) {
        tree->right = insert(tree->right , val);
    }
    //If the value already exists in the BST we print an error message
    else {
        printf("\n%d already exists in the BST!!\n" , val);
    }
    return tree;
}

//Displays the inorder traversal of the BST in a recursive manner
void display(Node *tree) { 
    // If tree is not NULL then we continue traversing BST in recursive manner
    if(tree != NULL) {
        display(tree->left);
        printf("%d " , tree->data);
        display(tree->right);
    }
}

//This function processes the BST and stores the level of the leaf nodes in a globally defined array
//This is the same as the recursive way to find the inorder traversal that has been modified to keep 
//track of levels of each node and identifying the leaf nodes
void process(Node *tree) {
    level++;
    if(tree->left == NULL && tree->right == NULL) {
        legend[ind]=level;
        ind++;
    }
    if(tree->left != NULL) {
        process(tree->left);
        level--;
    }
    if(tree->right != NULL) {
        process(tree->right);
        level--;
    }   
}

//After processing the BST this function then uses the data obtained to check whether the BST is complete or not
//In the process function we store all the levels of the leaf nodes
//In the complete function we check whether all the values in the array have same values or not
//If they have the same value, then all the leaf nodes have the same level in BST and it is complete
//Otherwise the BST is incomplete
int complete() {
    int check = legend[0];
    int flag = 0;
    int i;
    for(i=0;i<ind;i++) {
        if(legend[i] != check) {
            flag = 1;
            break;
        }
    }
    printf("\n\n");
    if(flag == 0)
        return 1;
    else
        return 0;
}

//This is the driver function of the program.
int main() {
    int ch, val, created, cont;
    created = 0;
    cont = 1;
    Node *tree;
    
    while(cont) {
        printf("\n1. Creates a BST");
        printf("\n2. Inserts elements into the BST");
        printf("\n3. Displays the elements of the BST");
        printf("\n4. Check if BST is complete or not!");
        printf("\n5. Exit\n");
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
                if(created == 0) {
                    printf("\nBST not yet created! Try again.\n");
                }
                else {
                    if(tree == NULL) {
                        printf("\nBST is empty!!\n");
                    }
                    else {
                        level=0;
                        ind=0;
                        process(tree);
                        if(complete())
                            printf("\nThe BST is complete!!\n");
                        else
                            printf("\nThe BST is not complete!!\n");
                    }
                }
                break;
            case 5:
                cont = 0;
                break;
            default:
                printf("\nWrong choice entered! Try again!\n");
        }
    }
}