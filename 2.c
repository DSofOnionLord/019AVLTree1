#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ou * treePointer;
struct ou
{
	int val;
	treePointer leftChild;
	treePointer rightChild;
	int bf;

};

int saved[100][2];

void inorder(treePointer a, int n)
{
	if(a)
	{
		//printf("%d %d\n", n, a->val);
		saved[n][0] = a->val;
		saved[n][1] = a->bf;
		inorder(a->leftChild, n*2);
		inorder(a->rightChild, (n*2)+1);
	}
}

void inorderRIP(treePointer a, int n)
{
	if(a)
	{
		inorderRIP(a->leftChild, n*2);
		inorderRIP(a->rightChild, (n*2)+1);
		free(a);
	}
}

void leftRotation(treePointer *parent, int *unbalanced)
{
	treePointer grandChild, child;
	child = (*parent)->leftChild;
	if(child->bf == 1)
	{
		(*parent)->leftChild = child->rightChild;
		child->rightChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else
	{
		grandChild = child->rightChild;
		child->rightChild = grandChild->leftChild;
		grandChild->leftChild = child;
		(*parent)->leftChild = grandChild->rightChild;
		grandChild->rightChild = *parent;
		switch(grandChild->bf)
		{
		case 1: (*parent)->bf = -1; child->bf = 0; break;
		case 0 : (*parent)->bf = child->bf = 0; break;
		case -1 : (*parent)->bf = 0; child->bf = 1;
		}
		*parent = grandChild;
	}
	(*parent)->bf = 0;
	*unbalanced = 0;
}

void rightRotation(treePointer *parent, int *unbalanced)
{
	
	treePointer grandChild, child;
	child = (*parent)->rightChild;
	if(child->bf == -1)
	{
		(*parent)->rightChild = child->leftChild;
		child->leftChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else
	{
		
		grandChild = child->leftChild;
		child->leftChild = grandChild->rightChild;
		grandChild->rightChild = child;
		(*parent)->rightChild = grandChild->leftChild;
		grandChild->leftChild = *parent;
		
		switch(grandChild->bf)
		{
		case 1: (*parent)->bf = -1; child->bf = 0; break;
		case 0 : (*parent)->bf = child->bf = 0; break;
		case -1 : (*parent)->bf = 0; child->bf = 1;
		}
		*parent = grandChild;
	}
	(*parent)->bf = 0;
	*unbalanced = 0;
}

void avlInsert(treePointer *parent, int x, int *unbalanced)
{
	if(!*parent)
	{
		*unbalanced = 1;
		(*parent) = (treePointer)malloc(sizeof(*parent));
		(*parent)->leftChild = (*parent)->rightChild = NULL;
		(*parent)->bf = 0;
		(*parent)->val = x;
	}
	else if ( x < (*parent)->val )
	{
		avlInsert(&(*parent)->leftChild, x, unbalanced);
		if(*unbalanced)
		{
			switch((*parent)->bf)
			{
			case -1: (*parent)->bf = 0; *unbalanced = 0; break;
			case 0: (*parent)-> bf = 1; break;
			case 1: leftRotation(parent, unbalanced);
			}
		}
	}
	else if(x > (*parent)->val )
	{
		avlInsert(&(*parent)->rightChild, x, unbalanced);
		if(*unbalanced)
		{
			switch((*parent)->bf)
			{
			case 1: (*parent)->bf = 0; *unbalanced = 0; break;
			case 0: (*parent)-> bf = -1; break;
			case -1: rightRotation(parent, unbalanced); break;
			}
		}
	}
	else
	{
		*unbalanced = 0;
		printf("The Key Is Already In The Tree");
	}
}

int main()
{
	
	int n;
	int i;
	int tmp;
	int unbalanced = 0;

	treePointer AVL;

	FILE * in = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");

	fscanf(in, "%d", &n);

	AVL = NULL;

	for ( i = 0 ; i < n ; i ++ )
	{
		fscanf(in, "%d", &tmp);
		avlInsert(&AVL, tmp, &unbalanced);
	}

	memset(saved, 0, sizeof(saved));

	inorder(AVL, 1);
	
	for ( i = 1 ; i < 100 ; i ++ )
	{
		if(saved[i][0] != 0 )
			fprintf(out, "CBT %d번 노드 =  %d \tbf = %d\n", i, saved[i][0], saved[i][1]);
	}

	//inorderRIP(AVL, 1);

	fclose(in);
	fclose(out);

	return 0;
}
