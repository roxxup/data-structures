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

//cout << p->data[p->top]; 
//cout << "Top value :" << p->top << endl;
}
void pop(struct stack *po){

cout << po->data[po->top--];

 
}
char peek(struct stack* pe){ 
return pe->data[pe->top];
}
void top(struct stack *t){
cout << "top is " << t->top;
}
int isEmpty(struct stack* em){
	if(em->top != -1){
		return 1;
	}
	else{ 
	return 0;
	}
}

int isOperator(char val){ 
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
char *string = "(a+(b-g)*f)";
for(int i = 0; i <= strlen(string); i++){
if(string[i] == '(')push(Stack,string[i]);
if(string[i] == ')'){ 
while(isEmpty(Stack) && peek(Stack) != '(')
{
	pop(Stack);
}pop(Stack);
} 
if(isOperator(string[i])){
	while(isEmpty(Stack) && Prec(peek(Stack)) >= Prec(string[i]))
	{
		pop(Stack);
	}
	push(Stack,string[i]);
}
	cout << string[i];

}
while(isEmpty(Stack)){ 
pop(Stack);
}
//top(Stack);

return 0; 

}


