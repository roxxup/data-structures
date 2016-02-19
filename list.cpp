//Creating a linked list 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
//Making a linked list structure 

struct list{		
int data; 
struct list *next; 
};
//Global declaration for head object 
struct list *head=NULL; 
//appendat function add elements at ith position
void appendat(int i,int val){ 
struct list *temp;
struct list *lat = (struct list*)malloc(sizeof(struct list));
lat->data =  val; 
temp = head; 
for(int j = 1; j < i-1;j++){ 
temp=temp->next; 
}
lat->next = temp->next; 
temp->next = lat; 
 
}
//Append function to add elements to list
void append(int val){ 
struct list *temp; 

if (head == NULL)
{ 
//cout << "Creating a temp node ..";
temp = (struct list*)malloc(sizeof(struct list));
//cout << "\nTemp variable address " << temp;  
head = temp; 
temp->data = val; 
//cout << "\nTemp variable data " << temp->data; 
temp->next = NULL; 
}
else{ 
struct list *temp1,*temp2;
//Assign temp variable head ojbect address  
temp1 = head; 
temp2 = (struct list*)malloc(sizeof(struct list));
//Traversing through end of the list 
while(temp1->next != NULL )
{ 
temp1 = temp1->next; 
}
temp2->data = val; 
temp1->next = temp2; 
temp2->next = NULL;
}
}
//print function to print out the elements of the list
void print(){ 
struct list *h = head; 
while(h != NULL ){ 
//cout << "This is printf\n";
cout << "\n" << h->data;
h = h->next; 
}
}
//Del function to delete the last element of the list
void del(){ 
struct list *temp; 
temp = head; 
while(temp->next != NULL){
if((temp->next)->next == NULL){ 
free(temp->next->next);
temp->next = NULL;
break;
 }
 temp=temp->next; 
}
}
int main() 
{ 
append(3); //Call to append(3) list becomes 3->NULL
append(34); //Call to append(34) list becomes 3->34->NULL
append(342); //Call to append(342) list becomes 3->34->342->NULL
append(34242); //Call to append(342424) list becomes 3->34->342->342424->NULL
//del(); //Call to del() list becomes 3->34->342->NULL
append(432); //Call to append(432) list becomes 3->34->342->432 
appendat(2,33); //Call to appendat(2,33) appends list at 2nd position with val of 33 
print(); //Call to print() prints out the list 
return 0; 
}
