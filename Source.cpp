// The following code is your starting point for PROG8130 Assignment #1
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure/typedef used for holding data
struct inputData {
	char name[30];
	int index;
};

// definition of linked list data nodes
typedef struct LinkedListNode {
	char				NameData[30];		// the name to be stored (no need to store index)
	LinkedListNode		*ptrNextNode;		// pointer to next node in list (NULL if the end)
} LinkedListNodeDef;

// prototypes
void AddToLinkedList(LinkedListNodeDef **ptrHead, char *NameData, int DataIndex);
void PrintLinkedList(LinkedListNodeDef *ptrHead);


// make the data positions the last 5 digits of student number
// for example if my student number ended in 94330 the data will be as supplied

// data used for test
// paste the data here that was created by Prog8130Assign1DataCreator.exe
// Used the following data in your assignment #1
inputData iData[5] = {
	{ "fish", 4 },
{ "kiwi", 1 },
{ "airplane", 4 },
{ "orange", 4 },
{ "allan", 4 }
};



int main() {
	int i;

	// define linked list head
	struct LinkedListNode		*ptrHead = NULL;

	// Print out the input data
	printf("Data before Linked List is:\n");
	for (i = 0; i < 5; i++)
		printf("%s , %d\n", iData[i].name, iData[i].index);

	// insert the data into Linked List
	for (i = 0; i < 5; i++)
		AddToLinkedList(&ptrHead, iData[i].name, iData[i].index);

	// now print out the list in order it is stored starting at head
	PrintLinkedList(ptrHead);
}

// fill in this function to add linked list nodes to provided index location
void AddToLinkedList(LinkedListNodeDef **ptrHead, char *NameData, int DataIndex) {
	// you need to add the code to put the NameData string into the linked list at the DataIndex location here!
	// Note: DataIndex of 0 or 1 is the beginning of the list, any number greater than th number of nodes in the list will go at end!
	// Hint: You are going to have to use malloc or calloc to allocate memory for new node

	LinkedListNode *newPtr, *tmpryPtr;
	int n = DataIndex;
	
	newPtr = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));

	strcpy(newPtr->NameData, NameData);				//Copies new data to be linked to newPtr.
	newPtr->ptrNextNode = NULL;						//Next pointer will then be linked to the end of new data.

	tmpryPtr = *ptrHead;

 	if ((n <= 1) || (*ptrHead==NULL)){

		newPtr->ptrNextNode = *ptrHead;				//newPtr will reassign head pointer.
		*ptrHead = newPtr;
	}
	else {
		for (int i = 0; i <= n ; i++) {				//Based on Index Number, pointer will traverse to sort into linked list
			if (tmpryPtr->ptrNextNode == NULL)
			{
				break;
			}
			tmpryPtr = tmpryPtr->ptrNextNode;
		}
		newPtr->ptrNextNode = tmpryPtr->ptrNextNode;
		tmpryPtr->ptrNextNode = newPtr;
	}

}

	// print out the linked list starting at the supplied linked list head
void PrintLinkedList(LinkedListNodeDef *ptrHead) {
	// you need to add code to print out each node in list starting at the ptrHead until the ptrNextNode is NULL

	LinkedListNodeDef *tempPtr = ptrHead;

	printf("Linked List \n\n ");

	while (tempPtr!=NULL) {
		printf("%s", tempPtr->NameData);
		tempPtr = tempPtr->ptrNextNode;
		printf("\n");
	}
}