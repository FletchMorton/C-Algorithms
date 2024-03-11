#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct Node Node;
struct Node {
    Node * left;
    Node * right;
    int value;
};

//Prototypes
Node * createNode(int);
Node * buildTree(int *, int);
Node * addNode(Node *, int);
int deepest(Node *);
void cleanTree(Node *);

//Main
int main()
{

    Node * root = NULL;

    root = addNode(root, 1);



    /*int size;
    int value;

    printf("Enter the number of Nodes in the tree: ");
    scanf("%d", &size);

    int * order = (int *) calloc(size, sizeof(int));

    printf("Enter your %d values: ", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &value);
        order[i] = value;
    }

    printf("The array is:\n");
    for(int i = 0; i < size; i++) {
        printf("%d\n", order[i]);
    }

    Node *root = buildTree(order, size);
    printf("Deepest node is %d\n", deepest(root));
    cleanTree(root);*/

    return 0;
}

//____________________________________________________

//Functions
//Method to create a binary search tree
//Creates a Node and initializes its data members. Returns the created Node
Node * createNode(int value) {
    Node * result = (Node *) malloc(sizeof(Node));
    result->value = value;
    result->left = NULL;
    result->right = NULL;

    return result;
}

//Function to add a node into a tree and return the root
Node * addNode(Node *root, int value)
{
    //If the tree is empty
    if(root == NULL) return createNode(value);

    //Check which side the value belongs on
    if(value < root->value) {
        //value is smaller than the root. Go into the smaller subtree
        root->left = addNode(root->left, value);

    } else if(value > root->value) {
        //value is larger than the root. Go into the larger subtree
        root->right = addNode(root->right, value);

    } else {
        //Value is equal to the root. The value should not exist
        printf("\n\n\nERROR\n\n\n");
        exit(0);
    }

    return root;
}

//Clean tree method
void cleanTree(Node *root)
{
    //If you are at the bottom
    if (root == NULL) return;

    cleanTree(root->right);
    cleanTree(root->left);

    free(root);
}

//Build the tree
Node * buildTree(int *order, int size)
{
    Node *root = NULL;

    for(int i = size - 1; i >= 0; i--) {
        root = addNode(root, order[i]);
    }

    return root;
}

//Function to find the deepest node in a tree
int deepest(Node * root)
{
    //If you are at the bottom
    if (root == NULL) return 0;

    int leftAns = deepest(root->left);
    int rightAns = deepest(root->right);

    if (leftAns < rightAns) return rightAns + 1;
    if (rightAns < leftAns) return leftAns + 1;

    return 0;
}

//__________________________________________________


/*          TRanscripting what dood said
Start at root. then we get 2 we're building a bi tree in area 3, everything over to left are working up to be a left child of 3, to right works to be right node so2 is left,
4 goes right, 1 goes left of 3 but 2 is there so left of 2
then look at max depth. 1 + maxdepth of subtrees. 2 is max of subtrees, 4 is 1. so 2 is max. so 2, 1+ 2 = 3

two recursive algs, one to build tree, one to find deoth

to build, root = NULL. insert a 3
if root is null, create node with 3 adn return as new root. insert 2. less than so insert on the elft. recurse down, three is either elft or right, recurse down left.
    Null so create new node, recurse up and assign as left child of three
*/
