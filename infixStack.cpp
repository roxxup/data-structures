#include<iostream>
#include<cstdlib>
#include <cstring>
using namespace std; 
struct stack{ 
char data[100]; 
int top;
};
void push(struct stack *p,char val){ 
p->data[++p->top] = val; 

cout << "Pushed  " << p->data[p->top] << endl; 
cout << "Top value :" << p->top << endl;
}
void pop(struct stack *po){ 
cout << "Pop  " << po->data[po->top--] << endl; 
cout << "Top value :" << po->top << endl;
}
char peek(struct stack* pe){ 
return pe->data[pe->top];
}
void top(struct stack *t){
cout << "top is " << t->top;
}
int isOperand(char val){ 
if(val == '+' || val == '-' || val == '*' || val == '^' )
return 1;
else 
return 0;
}
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

int main()
{
struct stack *Stack = (struct stack*)malloc(sizeof(struct stack));
Stack->top = -1;
char *string = "(abc+f-g)";
for(int i = 0; i <= strlen(string); i++){ 
if(isOperand(string[i]) && Prec(peek(Stack)) <= Prec(string[i])){ 
push(Stack,string[i]);
}
if(string[i] == '(') push(Stack,string[i]);
if(string[i] == ')'){
	while(Stack->data[Stack->top] != '(') pop(Stack);
	pop(Stack);
}
else{
	cout << string[i] << endl;
}
}

//top(Stack);

return 0; 

}


