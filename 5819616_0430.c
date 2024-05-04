#define _CRT_S
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void initQueue(QueueType* q) {
    q->front = q->rear = 0;
}

int isEmpty(QueueType* q) {
    return q->front == q->rear;
}

int isFull(QueueType* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType* q, element item) {
    if (isFull(q)) {
        printf("큐가 포화상태입니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void print_queue(QueueType* q) {
    int i;
    printf("-------------------------\n");
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
    }
    else {
        printf("현재 큐의 상태 : ");
        for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != (q->rear + 1) % MAX_QUEUE_SIZE; i = (i + 1) % MAX_QUEUE_SIZE) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
}


int main() {
    QueueType q;
    initQueue(&q);
    int choice, item;

    while (1) {
        printf("1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 원소를 입력하세요: ");
            scanf_s("%d", &item);
            enqueue(&q, item);
            break;
        case 2:
            if (!isEmpty(&q))
                printf("삭제된 원소: %d\n", dequeue(&q));
            break;
        case 3:
            print_queue(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
