#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int len = 0;
	while ((head) != NULL) { //increment len until end of LL
		head = (head)->next;
		len++;
	}
	return len; //return len
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int i = 0;
	char* CString = (char*)malloc(sizeof(char) * (length(head) + 1)); //allocate space for char array
	node* tmp = head;
	for (int n = 0; n<length(head);n++) {
		CString[i] = tmp->letter; //assign char to element, increment index then increment LL
		i++;
		tmp = tmp->next;
	}
	CString[length(head)] = '\0';
	return CString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* tmp = (node*)malloc(sizeof(node));
	if (*pHead == NULL) { //if the list is empty, point pHead to the new node
		*pHead = tmp;
		tmp->letter = c;
		tmp->next = NULL;
		
	}
	else { //if the list isn't empty, traverse to the end of the list and append the new node
		node* temp2 = (node*)malloc(sizeof(node));
		temp2 = *pHead;
		while ((temp2)->next != NULL) temp2 = (temp2)->next;
		(temp2)->next = tmp;
		tmp->letter = c;
		tmp->next = NULL;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while ((*pHead) != NULL) {
		node* tmp = *pHead;
		*pHead = (*pHead)->next;
		free(tmp); //traverse and free the previous node using a temp pointer until the LL is empty
	}
	node * tmp2 = *pHead;
	free(tmp2);
	*pHead = NULL; //assign head to null
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile, " %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}