// ť : ���� ���� �����Ͱ� ���� ������ �ڷᱸ��(FIFO)

//����ť

/* #include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("  | ");
		else printf("%d | ", q->data[i]);

	}
	printf("\n");
}

int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("ť�� ��ȭ����\n");
		return;
	}
	q->data[++(q->rear)] = item;
}

void dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� �������\n");
		return -1;
	}
	int item = q->data[++(q->front)];
}

int main(void) {
	int item = 0;
	QueueType q;

	init_queue(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	dequeue(&q); queue_print(&q);
	return 0;
}
*/


//����ť

/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d)= ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item){
	if (is_full(q)) {
		error("ť ��ȭ����");

	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť �������");

	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main(void)
{
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("-- ������ �߰� �ܰ�--\n");
	while (!is_full(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf_s("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);

	}
	printf("ť�� ��ȭ�����Դϴ�.\n");

	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("������ ���� : %d\n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");




}
*/

// ��  - �յ� �߰����� �� ����
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

int is_empty(DequeType* q) {
	return (q->front == q->rear);
}
int is_full(DequeType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void deque_print(DequeType* q) {
	printf("DEQUE(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType* q, element item) {
	if (is_full(q)) {
		printf("��ȭ����");

	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

}

element delete_front(DequeType* q) {
	if (is_empty(q))
		printf("�������");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("ť�� ��ȭ����");

	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� �������");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

int main(void) {
	DequeType queue;
	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
} */