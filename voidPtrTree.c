#include "voidPtrTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addElement(void* element, treeNode_t** node, int byteSize, enum DataType type){
	if(*node == NULL){
		*node = malloc(sizeof(treeNode_t));
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->data = element;
		(*node)->dataSize = byteSize;
		(*node)->type = type;
	}else if(byteSize < (*node)->dataSize)
		addElement(element, &(*node)->left, byteSize, type);
	else if(byteSize > (*node)->dataSize)
		addElement(element, &(*node)->right, byteSize, type);
	else{
		int comparision = memcmp((*node)->data, element, byteSize);
		if(comparision == 0)
			return;
		else if(comparision > 0)
			addElement(element, &(*node)->left, byteSize, type);
		else
			addElement(element, &(*node)->right, byteSize, type);
	}
}

void* findElement(void* element, treeNode_t* node, int byteSize){
	if(node == NULL)
		return NULL;
	else if(byteSize < node->dataSize)
		return findElement(element, node->left, byteSize);
	else if(byteSize > node->dataSize)
		return findElement(element, node->right, byteSize);
	else{
		int comparision = memcmp(node->data, element, byteSize);
		if(comparision == 0)
			return node->data;
		else if(comparision > 0)
			return findElement(element, node->left, byteSize);
		else
			return findElement(element, node->right, byteSize);
	}
}

treeNode_t* joinTrees(treeNode_t* original, treeNode_t* left, treeNode_t* right){
	return original;
}

//splitTrees(){
//
//}

void removeElement(void* element, treeNode_t* node, int byteSize){
	if(node->dataSize > byteSize || node == NULL)
		return;
	else if(node->dataSize < byteSize)
		findElement(element, node->left, byteSize);
	else if(node->dataSize > byteSize)
		findElement(element, node->right, byteSize);
	else{
		int comparision = memcmp(node->data, element, byteSize);
		if(comparision == 0){
			treeNode_t* joined = joinTrees(node, node->left, node->right);
			free(node);
			node = joined;
		}else if(comparision > 0)
			findElement(element, node->left, byteSize);
		else
			findElement(element, node->right, byteSize);
	}
}

void printTree(treeNode_t* node){
	if(node == NULL)
		return;

	switch(node->type){
		case CHAR: printf("%p char: %d\n", node, *(unsigned char*)node->data); break;
		case SHORT: printf("%p short: %d\n", node, *(short*)node->data); break;
		case INT: printf("%p int: %d\n", node, *(int*)node->data); break;
		case LONG: printf("%p long: %ld\n", node, *(long*)node->data); break;
		case FLOAT: printf("%p float: %f\n", node, *(float*)node->data); break;
		case DOUBLE: printf("%p double: %f\n", node, *(double*)node->data); break;
		case STRING: printf("%p string: %s\n", node, (char*)node->data); break;
		case STRUCT: printf("%p struct\n", node->data); break;
		case ARRAY:{
			puts("Elements in the array");
			int p = 0;
			int length = 0;
			int increment = 0;
			switch(node->type){
				case CHAR:
					puts("Char Array");
					length = node->dataSize / sizeof(char);
					for(;p < length; ++p){
						printf("Element %d is %d\n", p, *(char*)(node->data + increment));
						increment += sizeof(char);
					}
				break;
				case SHORT:
					puts("Short Array");
					length = node->dataSize / sizeof(short);
					for(;p < length; ++p){
						printf("Element %d is %d\n", p, *(short*)(node->data + increment));
						increment += sizeof(short);
					}
				break;
				case INT:
					puts("Int Array");
					length = node->dataSize / sizeof(int);
					for(;p < length; ++p){
						printf("Element %d is %d\n", p, *(int*)(node->data + increment) );
						increment += sizeof(int);
					}
				break;
				case LONG:
					puts("Long Array");
					length = node->dataSize / sizeof(long);
					for(;p < length; ++p){
						printf("Element %d is %ld\n", p, *(long*)(node->data + increment) );
						increment += sizeof(long);
					}
				break;
				case FLOAT:
					puts("Float Array");
					length = node->dataSize / sizeof(float);
					for(;p < length; ++p){
						printf("Element %d is %f\n", p, *(float*)(node->data + increment) );
						increment += sizeof(float);
					}
				break;
				case DOUBLE:
					puts("Double Array");
					length = node->dataSize / sizeof(double);
					for(;p < length; ++p){
						printf("Element %d is %f\n", p, *(double*)(node->data + increment) );
						increment += sizeof(double);
					}
				break;
				case STRING:
					puts("String Array");
					length = node->dataSize / sizeof(char*);
					for(;p < length; ++p){
						printf("Element %d is %s\n", p, (char*)(node->data + increment) );
						increment += sizeof(char*);
					}
				break;
				default:
					printf("Total array size is %d and the array starts at %p\n", node->dataSize, node->data);
					break;
			}
		 }break; //end of array case

		default:
			printf("%p\n", node->data);
		break;
	}
	printTree(node->left);
	printTree(node->right);
}

void clearTree(treeNode_t** node){
		if(*node == NULL)
			return;

		clearTree(&(*node)->left);
		clearTree(&(*node)->right);

		free(*node);
		*node = NULL;
}

