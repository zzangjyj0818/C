#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef int element;
typedef  struct QueueType{
    element data[MAX_SIZE];
    int front, rear;
}QueueType;

void init_queue(QueueType *q){
    q->rear = q->front = 0;
}

int is_empty(QueueType *q){
    return (q->rear == q->front);
}

int is_full(QueueType *q){
    return ((q->rear +1)%MAX_SIZE == q->front);
}

void print_queue(QueueType *q){
    printf("QUEUE(front = %d rear = %d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1) % (MAX_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q->rear)
                break;
        }while(i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element data){
    if(is_full(q)){
        return;
    }
    q->rear = (q->rear +1) % MAX_SIZE;
    q->data[q->rear] = data;
}

element dequeue(QueueType *q){
    if(is_empty(q))
        return -1;
    q->front = (q->front +1) % MAX_SIZE;
    return q->data[q->front];
}

int main(){
    QueueType queue;
    int element;
    
    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
    while(!is_full(&queue)){
        printf("input the data : ");
        scanf("%d", &element);
        enqueue(&queue, element);
        print_queue(&queue);
    }
    printf("Queue is Full! \n");
    printf("Delete the data of queue\n");
    while(!is_empty(&queue)){
        element = dequeue(&queue);
        printf("Data(Pop) : %d \n", element);
        print_queue(&queue);
    }
    printf("Queue is empty!\n");
}
