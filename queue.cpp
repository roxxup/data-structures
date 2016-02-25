#include<iostream>
#include<cstring>
using namespace std;
char arr[234]; 
int front = -1; 
int rear = -1; 
void enqueue(char ch){ 
arr[++rear] = ch; 
}
void peek(){ 
cout << "current element " << arr[rear] << endl;
}
void dequeue(){ 
++front; 
}
int main()
{ 
front = 0; 
rear = 0;
enqueue('h');
dequeue();  
peek();
enqueue('k');
peek();
return 0; 
}
