#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void readNode(struct Node *node, int n)
{
	if (n == 0)
	{
		/* code */
	}
	else
	{
		scanf("%d", &node->data);
		node->next = (struct Node *)malloc(sizeof(struct Node));
		readNode(node, n - 1);
	}
}

int main()
{
	struct Node *list = NULL;

	list = (struct Node *)malloc(sizeof(struct Node));

	int n;
	scanf("%d", &n);

	readNode(list, n);

	return 0;
}
