#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    Node * children[26]; //Children are each letter of the alphabet
    char id;
    int data;
    int subData;
};

Node * insert(Node *, char *, char, int);
void printTrie(Node *, char *, char, int);
Node * createNode(char);
int find(Node *, char *);
Node * deleteName(Node *, char *, int);
Node * renameNode(Node *, char *, char *);

int main()
{
    Node *root = NULL;
    char *string;
    char *string2;

    string = "POP";
    root = insert(root, string, '\0', 12);

    string = "POPOLA";
    root = insert(root, string, '\0', 20);

    string = "DEVOLA";
    root = insert(root, string, '\0', 1);

    string = "POPOLA";
    printTrie(root, string, '\0', 12);

    printf("\n\n");

    string = "DEVOLA";
    printTrie(root, string, '\0', 12);

    printf("\n\n");
    string = "POP";
    string2 = "DEVOLAAA";

    root = renameNode(root, string, string2);

    string = "POPOLA";
    printTrie(root, string, '\0', 12);

    printf("\n\n");

    string = "DEVOLAAA";
    printTrie(root, string, '\0', 12);


    return 0;
}

//_________________________________________________________________

Node * createNode(char chara)
{
    Node * result = (Node *)malloc(sizeof(Node));
    result->data = 0;
    result->subData = 0;
    result->id = chara;

    for(int i = 0; i < 26; i++) {
        result->children[i] = NULL;
    }

    return result;
}

//_________________________________________________________________

Node * insert(Node *root, char *name, char chara, int data)
{
    //If the node does not exist, create it and continue with the insert
    if(root == NULL) root = createNode(chara);

    //If the current letter is the null terminator
    if(name[0] == '\0') {
        root->data = data;
        root->subData += data;
        //append(root->data, data);

    //If the current letter is a character
    } else {
        //Finds the appropriate index for the current character (0-25)
        int index = name[0] - 'A';
        //Update the current node's subtree sum
        root->subData += data;
        //name+1 removes the first character of the string, and the recursive call that executes with the truncated string as the provided name
        root->children[index] = insert(root->children[index], name+1, name[0], data);
    }

    return root;
}

//_________________________________________________________________

Node * deleteName(Node *root, char *name, int dataToRemove)
{
    //If the node does not exist... uh,
    if(root == NULL) return root;

    //If the current letter is the null terminator
    if(name[0] == '\0') {
        root->data = 0;
        root->subData -= dataToRemove;

    //If the current letter is a character
    } else {
        //Finds the appropriate index for the current character (0-25)
        int index = name[0] - 'A';
        //Update the current node's subtree sum
        root->subData -= dataToRemove;
        //name+1 removes the first character of the string, and the recursive call that executes with the truncated string as the provided name
        root->children[index] = deleteName(root->children[index], name+1, dataToRemove);
    }

    return root;
}

//_________________________________________________________________

int find(Node *root, char *name)
{
    int result;

    //If the node does not exist, return 0
    if(root == NULL) return 0;

    //If the current letter is the null terminator, return the data
    if(name[0] == '\0') {
        return root->data;

    //If the current letter is a character
    } else {
        //Finds the appropriate index for the current character (0-25)
        int index = name[0] - 'A';
        //name+1 removes the first character of the string, and the recursive call that executes with the truncated string as the provided name
        result = find(root->children[index], name+1);
    }

    return result;
}

//_________________________________________________________________

Node * renameNode(Node *root, char *oldName, char *newName)
{
    int transferData;
    transferData = find(root, oldName);
    root = deleteName(root, oldName, transferData);
    root = insert(root, newName, '\0', transferData);

    return root;
}

//_________________________________________________________________

void printTrie(Node *root, char *name, char chara, int data)
{
    //If the node does not exist, create it and continue with the insert
    if(root == NULL) {
        printf("\nNULL\n");
        return;
    }

    //If the current letter is the null terminator
    if(name[0] == '\0') {
        printf("%c\t\t%d\t%d\n", root->id, root->data, root->subData);
        //append(root->data, data);

    //If the current letter is a character
    } else {
        //Finds the appropriate index for the current character (0-25)
        int index = name[0] - 'A';
        printf("%c\t\t%d\t%d\n", root->id, root->data, root->subData);
        //name+1 removes the first character of the string, and the recursive call that executes with the truncated string as the provided name
        printTrie(root->children[index], name+1, name[0], data);
    }

    return;
}
