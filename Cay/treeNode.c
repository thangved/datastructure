#include <stdlib.h>
typedef struct _treeNode
{
    int inf;
    struct _treeNode *leftmost_child;
    struct _treeNode *right_sibling;
} treeNode;

int innode_count(treeNode *r)
{
    if (r->leftmost_child != NULL || r->right_sibling != NULL)
        return 1 + innode_count(r->leftmost_child) + innode_count(r->right_sibling);
    return 0;
}
