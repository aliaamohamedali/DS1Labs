#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TYPE char

typedef struct Stack{
   TYPE* arr;
   int size;
   int top;
}Stack;

int parseInt(char input){
  return input-48;
}

void initialize(Stack *s, int size){
    s->arr=(TYPE*)malloc(size*sizeof(TYPE));
    s->size=size;
    s->top=-1;
}

void push(Stack *s, TYPE value){
    s->arr[++(s->top)]=value;
}

TYPE pop(Stack *s){
  return s->arr[s->top--];
}

TYPE peek(Stack *s){
  if(isEmpty(s)){
    return '\0';
  }
  return s->arr[s->top];
}

int isEmpty(Stack *s){
  if(s->top==-1){
    return 1;
  }
  return 0;
}

int evaluate(Stack *expression){
    if(peek(expression)>='0' && peek(expression)<='9'){
        return parseInt(pop(expression));
    }
    else {
      switch(pop(expression)){
       case '+': return evaluate(expression)+evaluate(expression); break;
       case '-': return evaluate(expression)-evaluate(expression); break;
       case '*': return evaluate(expression)*evaluate(expression); break;
       case '/': return evaluate(expression)/evaluate(expression); break;
      }
    }
}

int getPrecedence(char input){
   if (input =='+' || input == '-') return 1;
   if (input=='*' || input=='/') return 2;
   return 0;
}

void infixToPostfix(char* infix, char* postfix){
  Stack operators;
  initialize(&operators, 10);
  while(*infix!='\0' && *infix!='\n'){

    if(*infix>='0' && *infix <='9'){   // An Operand is Found- put it in
        *postfix=*infix;
        postfix++;
    }

    else if(*infix=='('){            // A Left Parenthesis is Found
      push(&operators, *infix);
    }

    else if(*infix==')'){            // A Right Parenthesis is Found
        while(peek(&operators)!='('){
            *postfix=pop(&operators);
            postfix++;
        }
        pop(&operators);
    }
    else{                            // An Operator is Found
      while(getPrecedence(peek(&operators))>=getPrecedence(*infix)){
         *postfix=pop(&operators);
         postfix++;
      }
      push(&operators, *infix);
    }
    infix++;
  }
  while(!isEmpty(&operators)){
    *postfix=pop(&operators);
    postfix++;
  }
  *postfix='\0';
}


int main()
{
    // Stack part one:
/*
    int i;
    Stack myStack;
    initialize(&myStack, 10);
    for (i=0; i<10; i++){
    push(&myStack, i+1);
    }
    while(!isEmpty(&myStack)){
        printf("Value at %d= %d\n",i+1, pop(&myStack));
    }
     return 1;
*/
    // Stack part Two:
/*
    int i;
    Stack expression;
    initialize(&expression, 30);
    char postfixEquation[20];
    scanf("%s", postfixEquation);
    for(i=0; i< 7; i++){
        push(&expression, postfixEquation[i]);
    }
    printf("%d", evaluate(&expression));
    return 0;
*/
    // Stack Assignment:
//    printf("%d", parseInt('8')+2);
    int i;
    Stack expression;
    initialize(&expression, 14);
//    char *infix = (char)malloc(14*sizeof(char));
//    char *postfix = (char)malloc(14*sizeof(char));
    char infix[20];
    char postfix[20];
    scanf("%s", infix);
    infixToPostfix(&infix , &postfix);
    printf("%s", postfix);

    for(i=0; postfix[i]!='\0'; i++){
        push(&expression, *(postfix+i));
    }
    printf("\n%d" , evaluate(&expression));

}
