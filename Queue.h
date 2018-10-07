#ifndef QUEUE_H
#define QUEUE_H
#include <cstdio>
#include <cstdlib>
typedef int ElemType;
typedef struct queue *PtrToQnode;
struct queue
{
	ElemType data;
	struct queue *next;
};
typedef struct ptr {
	PtrToQnode front;//队头指针
	PtrToQnode rear;//队尾指针
}*Queue;
Queue InitQueue()
{
	Queue Q = (Queue)malloc(sizeof(struct ptr));
	if (Q == NULL)
	{
		printf("初始化失败");
		return NULL;
	}
	Q->front = Q->rear = (struct queue *)malloc(sizeof(struct queue));
	if (Q->front == NULL)
	{
		printf("初始化失败");
		return NULL;
	}
	Q->front->next = NULL;
	return Q;
}
void EnQueue(Queue Q, ElemType x)
{
	PtrToQnode q = (PtrToQnode)malloc(sizeof(struct queue));
	if (q == NULL)
	{
		printf("分配失败");
		return;
	}
	Q->rear->next = q;
	q->data = x;
	q->next = NULL;
	Q->rear = q;
}
ElemType DeQueue(Queue Q)
{
	ElemType x;
	PtrToQnode p;
	if (Q->front == Q->rear)
	{
		printf("空队列");
		return NULL;
	}
	p = Q->front->next;
	x = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return x;
}
bool IsEmpty(Queue Q)
{
	if (Q->front == Q->rear)
		return true;
	else 
		return false;
}
int QueueLength(Queue Q)
{
	int n = 0;
	PtrToQnode p = Q->front->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
void DestroyQueue(Queue Q) {
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}//释放一块内存要做两点:1、释放指向他的指针 2、将该指针指向空
}
#endif