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
void search(Tree *tree,int val){
if(tree){ 
if(tree->data < val){
	search(tree->right,val);
}
else{
	search(tree->left,val);
}
if(tree->data == val){
	cout << "val  found ";
	return;
}
}
}

void findleast(Tree *tree){ 
while(tree->right != NULL){ 
tree = tree->left; 
}
cout << "least is " << tree->data;
}
void findmax(Tree *tree){ 
while(tree->right != NULL){ 
tree = tree->right;
}
cout << "max is " << tree->data;
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
void print_postorder(Tree * tree)
{
    if (tree)
    {
        print_postorder(tree->right);
        print_postorder(tree->left);
        printf("%d\n",tree->data);
    }
}
void print_preorder(Tree *tree){ 
if(tree){ 
print_preorder(tree->left); 
print_preorder(tree->right); 
cout << tree->data << "\n";
}
} 
int main() 
{ 
insert(&root,3);
insert(&root,4);
insert(&root,1);
insert(&root,9);
printf("In Order Display\n");
print_inorder(root);
cout << "post order" << endl; 
print_postorder(root);
cout << "pre order" << endl; 
print_preorder(root);
search(root,433);
//findmax(root);
//findleast(root);
return 0; 
}
