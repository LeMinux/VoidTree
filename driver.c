//tests the tree

#include "voidPtrTree.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void addEmpty();
void addTenSameElements();
void addDiffElements();

void findIntElement();
void findFloatElement();
void findDoubleElement();
void findShortElement();
void findStringElement();
void findStructElement();
void findArrayElement();

void clearTest();

const enum DataType CHARTYPE = CHAR;
const enum DataType SHORTTYPE = SHORT;
const enum DataType INTTYPE = INT;
const enum DataType LONGTYPE = LONG;
const enum DataType FLOATTYPE = FLOAT;
const enum DataType DOUBLETYPE = DOUBLE;
const enum DataType STRINGTYPE = STRING;
const enum DataType ARRAYTYPE = ARRAY;
const enum DataType STRUCTTYPE = STRUCT;
const enum DataType MISCTYPE = MISC;
int intValues [] = {5,3,7,4,6,1,8,9,0,2};

int main(void){
	puts("Testing adding to empty tree");
	addEmpty();
	puts("Testing adding 10 items");
	addTenSameElements();
	puts("Testing clearing a tree (has 10 items)");
	clearTest();
	puts("Testing adding different number types");
	addDiffElements();
}

void addEmpty(){
	treeNode_t* head = NULL;
	int value = 87;
	addElement(&value, &head, sizeof(value), INTTYPE);
	assert(*(int*)head->data == value);
	free(head);
}

void addTenSameElements(){
	treeNode_t* head = NULL;
	treeNode_t* treeNodes [10];
	int a = 0;
	for(; a < 10; ++a){
		addElement(&intValues[a], &head, sizeof(intValues[a]), INTTYPE);
	}

	treeNodes[0] = head;
	treeNodes[1] = head->left;
	treeNodes[2] = head->right;
	treeNodes[3] = head->left->right;
	treeNodes[4] = head->right->left;
	treeNodes[5] = head->left->left;
	treeNodes[6] = head->right->right;
	treeNodes[7] = head->right->right->right;
	treeNodes[8] = head->left->left->left;
	treeNodes[9] = head->left->left->right;
	
	assert(*(int*) treeNodes[0]->data == intValues[0]);
	assert(*(int*) treeNodes[1]->data == intValues[1]);
	assert(*(int*) treeNodes[2]->data == intValues[2]);
	assert(*(int*) treeNodes[3]->data == intValues[3]);
	assert(*(int*) treeNodes[4]->data == intValues[4]);
	assert(*(int*) treeNodes[5]->data == intValues[5]);
	assert(*(int*) treeNodes[6]->data == intValues[6]);
	assert(*(int*) treeNodes[7]->data == intValues[7]);
	assert(*(int*) treeNodes[8]->data == intValues[8]);
	assert(*(int*) treeNodes[9]->data == intValues[9]);

	int f = 9;
	for(;f >= 0; --f)
		free(treeNodes[f]);
}

/*
void clearTest(){
	treeNode_t* head = NULL;
	treeNode_t** tree [10];
	int a = 0;
	for(; a < 10; ++a)
		addElement(&intValues[a], &head, sizeof(intValues[a]));

	tree[0] = &head;
	tree[1] = &head->left;
	tree[2] = &head->right;
	tree[3] = &head->left->right;
	tree[4] = &head->right->left;
	tree[5] = &head->left->left;
	tree[6] = &head->right->right;
	tree[7] = &head->right->right->right;
	tree[8] = &head->left->left->left;
	tree[9] = &head->left->left->right;


	printf("0 %p\n", *tree[0]);
	printf("1 %p\n", *tree[1]);
	printf("2 %p\n", *tree[2]);
	printf("3 %p\n", *tree[3]);
	printf("4 %p\n", *tree[4]);
	printf("5 %p\n", *tree[5]);
	printf("6 %p\n", *tree[6]);
	printf("7 %p\n", *tree[7]);
	printf("8 %p\n", *tree[8]);
	printf("9 %p\n", *tree[9]);
	puts("\nPrinting Tree");
	printTree(head);
	clearTree(&head);

	puts("Did clear?");
	printf("0 %p\n", *tree[0]);
	printf("1 %p\n", *tree[1]);
	printf("2 %p\n", *tree[2]);
	printf("3 %p\n", *tree[3]);
	printf("4 %p\n", *tree[4]);
	printf("5 %p\n", *tree[5]);
	printf("6 %p\n", *tree[6]);
	printf("7 %p\n", *tree[7]);
	printf("8 %p\n", *tree[8]);
	printf("9 %p\n", *tree[9]);

	puts("\nAgain Printing Tree");
	printTree(head);

	assert(*tree[0] == NULL);
	assert(*tree[1] == NULL);
	assert(*tree[2] == NULL);
	assert(*tree[3] == NULL);
	assert(*tree[4] == NULL);
	assert(*tree[5] == NULL);
	assert(*tree[6] == NULL);
	assert(*tree[7] == NULL);
	assert(*tree[8] == NULL);
	assert(*tree[9] == NULL);
}
*/

//not sure if I'm checking this correctly to be honest
void clearTest(){
	treeNode_t* head = NULL;
	treeNode_t** tree [10];
	treeNode_t* previousValues [10];
	treeNode_t* currentValues [10];
	int a = 0;
	for(; a < 10; ++a)
		addElement(&intValues[a], &head, sizeof(intValues[a]), INTTYPE);

	tree[0] = &head;
	tree[1] = &head->left;
	tree[2] = &head->right;
	tree[3] = &head->left->right;
	tree[4] = &head->right->left;
	tree[5] = &head->left->left;
	tree[6] = &head->right->right;
	tree[7] = &head->right->right->right;
	tree[8] = &head->left->left->left;
	tree[9] = &head->left->left->right;

	a = 0;
	for(; a < 10; ++a)
		previousValues[a] = *tree[a];

	puts("\nPrinting Tree");
	printTree(head);
	puts("Clearing");
	clearTree(&head);
	puts("done");

	a = 0;
	for(;a < 10; ++a)
		currentValues[a] = *tree[a];

	puts("\nAgain Printing Tree");
	printTree(head);

	assert(previousValues[0] != currentValues[0]);
	assert(previousValues[1] != currentValues[1]);
	assert(previousValues[2] != currentValues[2]);
	assert(previousValues[3] != currentValues[3]);
	assert(previousValues[4] != currentValues[4]);
	assert(previousValues[5] != currentValues[5]);
	assert(previousValues[6] != currentValues[6]);
	assert(previousValues[7] != currentValues[7]);
	assert(previousValues[8] != currentValues[8]);
	assert(previousValues[9] != currentValues[9]);
}

void addDiffElements(){
	int item1 = 126;
	int item2 = 256;
	int item3 = 64;
	double item4 = 80.45;
	double item5 = 70.77;
	double item6 = 100.05;
	char item7 = 'A';
	char item8 = ' ';
	char item9 = 'a';
	short item10 = 5000;
	short item11 = 2000;
	short item12 = 9000;

	treeNode_t* head = NULL;
	addElement(&item1, &head, sizeof(item1), INTTYPE);
	addElement(&item2, &head, sizeof(item2), INTTYPE);
	addElement(&item3, &head, sizeof(item3), INTTYPE);
	addElement(&item4, &head, sizeof(item4), DOUBLETYPE);
	addElement(&item5, &head, sizeof(item5), DOUBLETYPE);
	addElement(&item6, &head, sizeof(item6), DOUBLETYPE);
	addElement(&item7, &head, sizeof(item7), CHARTYPE);
	addElement(&item8, &head, sizeof(item8), CHARTYPE);
	addElement(&item9, &head, sizeof(item9), CHARTYPE);
	addElement(&item10, &head, sizeof(item10), SHORTTYPE);
	addElement(&item11, &head, sizeof(item11), SHORTTYPE);
	addElement(&item12, &head, sizeof(item12), SHORTTYPE);

	assert(findElement(&item1, head, sizeof(item1)));
	assert(findElement(&item2, head, sizeof(item2)));
	assert(findElement(&item3, head, sizeof(item3)));
	assert(findElement(&item4, head, sizeof(item4)));
	assert(findElement(&item5, head, sizeof(item5)));
	assert(findElement(&item6, head, sizeof(item6)));
	assert(findElement(&item7, head, sizeof(item7)));
	assert(findElement(&item8, head, sizeof(item8)));
	assert(findElement(&item9, head, sizeof(item9)));
	assert(findElement(&item10, head, sizeof(item10)));
	assert(findElement(&item11, head, sizeof(item11)));
	assert(findElement(&item12, head, sizeof(item12)));
	puts("Printing all");
	printTree(head);
	clearTree(&head);
}

void findIntElement();
void findFloatElement();
void findDoubleElement();
void findShortElement();
void findStringElement();
void findStructElement();
void findArrayElement();



