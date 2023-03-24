#ifndef VOID_PTR_TREE
#define VOID_PTR_TREE

enum DataType {CHAR = 0, SHORT, INT, LONG, FLOAT, DOUBLE, STRING, ARRAY, STRUCT, MISC};

typedef struct treeNode{
	struct treeNode* left;
	struct treeNode* right;
	void* data;
	int dataSize;
	enum DataType type;
} treeNode_t;

void addElement(void*, treeNode_t**, int, enum DataType);
void* findElement(void*, treeNode_t*, int);
treeNode_t* joinTrees(treeNode_t*, treeNode_t*, treeNode_t*);
//splitTrees();
void removeElement(void*, treeNode_t*, int);
void printTree(treeNode_t*);
void clearTree(treeNode_t**);

#endif
