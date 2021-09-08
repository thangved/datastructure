#include <stdlib.h>

typedef struct _treeNode
{
    int inf;
    struct _treeNode *left;
    struct _treeNode *right;
} treeNode;

int c(treeNode *r)
{
    if (r->left == NULL && r->right == NULL)
        return 0;
    else if (r->right == NULL)
        return 1 + c(r->left);
    else
        return c(r->left) + c(r->right);
}

int main()
{
    treeNode *tree = (treeNode *)malloc(sizeof(treeNode));
    tree->inf = 1;
    tree->right = NULL;
    tree->left = (treeNode *)malloc(sizeof(treeNode));
    tree->left->right = NULL;
    tree->left->left = NULL;
    int count = c(tree);
    return 0;
}