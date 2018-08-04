#include <stdio.h>
#include <stdlib.h>
#define TYPE int
#define SIZE 50

typedef struct{
    TYPE data[SIZE];
    int head,tail,counter;

} Queue;

void initialize(Queue* q){
    q->head=0;
    q->counter=0;
    q->tail=0;
}

void enqueue(Queue* q, TYPE input){
    q->data[q->tail++]=input;
    q->counter++;
}

int dequeue(Queue* q){
    q->counter--;
    return q->data[q->head++];
}

int isFull(Queue* q){
    return q->counter>=SIZE;

}

int isEmpty(Queue* q){
    return q->counter==0;
}




int main()
{

    Queue* q =(Queue*) malloc(sizeof(Queue));
    initialize (q);
    int i,j;
    for(i=1; i<=10; i++){

        enqueue(q,i);
    }
    for(i=0; i<10; i++){
        printf("%d\n",dequeue(q));
    }
    return 0;
}
