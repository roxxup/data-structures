#include<iostream>
#include<cstring>
using namespace std;
char arr[234]; 
int front = -1; 
int rear = -1; 
void enqueue(char ch){ 
arr[++front] = ch; 
}
void peek(){ 
cout << "current element " << arr[front] << endl;
}
void dequeue(){ 
--front; 
}
int main()
{ 
enqueue('h');
dequeue();  
peek();
enqueue('k');
peek();
return 0; 
}
