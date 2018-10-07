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
	PtrToQnode front;//��ͷָ��
	PtrToQnode rear;//��βָ��
}*Queue;
Queue InitQueue()
{
	Queue Q = (Queue)malloc(sizeof(struct ptr));
	if (Q == NULL)
	{
		printf("��ʼ��ʧ��");
		return NULL;
	}
	Q->front = Q->rear = (struct queue *)malloc(sizeof(struct queue));
	if (Q->front == NULL)
	{
		printf("��ʼ��ʧ��");
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
		printf("����ʧ��");
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
		printf("�ն���");
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
	}//�ͷ�һ���ڴ�Ҫ������:1���ͷ�ָ������ָ�� 2������ָ��ָ���
}
#endif