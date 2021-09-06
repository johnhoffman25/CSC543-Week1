//John Hoffman - F00555643
//CSC 543
//Assignment 3 - Linked List Implementation
//09/05/2021

#include<iostream>
using namespace std;

//Node class to represent our linked list
class Node {
    public:
    int row;
    int column;
    int data;
    Node *next;
};

//Function to create a new node
void createNewNode(Node **previousNode, int rowIndex, int columnIndex, int inputData) {
    Node *tempNode = *previousNode;
    Node *newNode;

    //If the linked list is empty then create the first node and assign the data value
    if (tempNode == NULL) {
        tempNode = new Node();
        tempNode->row = rowIndex;
        tempNode->column = columnIndex;
        tempNode->data = inputData;
        tempNode->next = NULL;
        *previousNode = tempNode;
    }

    //If the linked list is already created then simply append the new node
    else {
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
        }

        newNode = new Node();
        newNode->row = rowIndex;
        newNode->column = columnIndex;
        newNode->data = inputData;
        newNode->next = NULL;
        tempNode->next = newNode;
    }
}

//Function to print the contents of the linked list
void printList(Node *start) {
    Node *pointer = start;

    while (pointer != NULL) {
        cout << pointer->row << " ";
        pointer = pointer->next;
    }

    cout << "\n";
    pointer = start;

    while (pointer != NULL) {
        cout << pointer->column << " ";
        pointer = pointer->next;
    }

    cout << "\n";
    pointer = start;

    while (pointer != NULL) {
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
}

int main(){
    //Initializing the example matrix from the assignment
    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4},
        {0 , 0 , 5 , 7 , 0},
        {0 , 0 , 0 , 0 , 0},
        {0 , 2 , 6 , 0 , 0}
    };

    //Create the first node of the linkedlist as NULL to begin the list
    Node *first = NULL;

    //Create the linked list using only non-zero values from the matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                createNewNode(&first, i, j, sparseMatrix[i][j]); //Need to assign pointer for the node
            }
        }
    }

    printList(first);

    return 0;
}