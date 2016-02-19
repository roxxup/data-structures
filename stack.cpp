#include<iostream>
#include <stdlib.h>
using namespace std;
struct stack{ 
int data; 
int top; 
int *arr; 
}; 
void peek(struct stack *Stack)
{
	cout << "Top element is " << Stack->arr[Stack->top];
}
void pushMe(struct stack *Stack,int val){ 
Stack->arr[++(Stack->top)] = val; 
//cout << Stack->top << endl;
cout << Stack->arr[Stack->top] << endl;
}
void popMe(struct stack* Stack)
{ 
cout << Stack->arr[--Stack->top];
}
int main()
{ 
struct stack *start = (struct stack *)malloc(sizeof(struct stack)); 
int size = 10; 
start->top = -1;
start->arr = (int*)malloc(sizeof(int)*size);
pushMe(start,23);
pushMe(start,54);
pushMe(start,234);
pushMe(start,21);
popMe(start);
peek(start);
return 0; 
}
