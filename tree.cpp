#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct tree{ 
int data; 
struct tree *left; 
struct tree *right; 
}Tree; 
Tree *root = NULL;
Tree* newNode(int val){ 
Tree *node = (Tree*)malloc(sizeof(Tree)); 
node->data = val;
node->left = NULL; 
node->right = NULL; 
return node;
}
void insert(Tree** tree,int val){ 
if(!(*tree)){  
Tree *temp = newNode(val);
*tree = temp;
return; 
}
else if ((*tree)->data < val){ 
insert(&(*tree)->right,val);
} 
else if((*tree)->data > val){ 
insert(&(*tree)->left,val);
}
}
void print_inorder(Tree * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}
int main() 
{ 
insert(&root,3);
insert(&root,4);
insert(&root,1);
printf("In Order Display\n");
print_inorder(root);
return 0; 
}
