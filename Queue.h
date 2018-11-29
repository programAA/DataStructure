#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Tree.h"
using namespace std;
typedef struct TNode* QElemType;


typedef struct queue {
	QElemType *data;
	int front, rear;
	int MaxSize;
}*Queue;

void ReAssign(Queue Q) {
	QElemType *newbase = (QElemType *)realloc(Q->data, 2 * Q->MaxSize * sizeof(QElemType));
	if (newbase == NULL) {
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	Q->data = newbase;
	if (Q->rear != Q->MaxSize - 1) {
		for (int i = 0; i < Q->rear; i++) 
			Q->data[i + Q->MaxSize] = Q->data[i];
		Q->rear += Q->MaxSize;
	}
	Q->MaxSize *= 2;
}
Queue InitQueue() {
	Queue Q = (Queue)malloc(sizeof(struct queue));
	if (Q == NULL) {
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	Q->MaxSize = 32;//��ʼ�������ܴ��32��Ԫ��
	Q->data = (QElemType *)malloc(Q->MaxSize * sizeof(QElemType));
	if (Q->data == NULL) {
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	Q->front = Q->rear = 0;
	return Q;
}
void EnQueue(Queue Q, QElemType x) {
	if ((Q->rear + 1) % Q->MaxSize == Q->front)
		ReAssign(Q);
	Q->data[Q->rear] = x;
	Q->front = (Q->rear + 1) % Q->MaxSize;
}
QElemType DeQueue(Queue Q) {
	QElemType temp;
	if (Q->rear == Q->front) {
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	temp = Q->data[Q->front];
	Q->front = (Q->front + 1) % Q->MaxSize;
	return temp;
}
int Length(Queue Q) {
	return (Q->rear - Q->front + Q->MaxSize) % Q->MaxSize;
}
bool IsEmpty(Queue Q) {
	return Q->front == Q->rear ? true : false;
}


typedef struct qNode
{
	QElemType data;
	struct qNode *next;
}*QNode;
typedef struct Lqueue {
	QNode front;//��ͷָ��
	QNode rear;//��βָ��
}*LQueue;

LQueue InitLQueue()
{
	LQueue Q = (LQueue)malloc(sizeof(struct Lqueue));
	if (Q == NULL)
	{
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	Q->front = Q->rear = NULL;
	return Q;
}
void EnQueue(LQueue Q, QElemType x) {
	QNode newP = (QNode)malloc(sizeof(struct qNode));
	if (newP == NULL) {
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	newP->data = x;
	newP->next = NULL;
	if (Q->rear == NULL)
		Q->front = Q->rear = newP;
	else {
		Q->rear->next = newP;
		Q->rear = newP;
	}
}
QElemType DeQueue(LQueue Q)
{
	QElemType temp;
	QNode P;
	if (Q->front == NULL) {
		cout << "����Ϊ��" << endl;
		exit(1);
	}
	P = Q->front;
	Q->front = P->next;
	if (Q->front == NULL)//ɾ��һ���ڵ�󣬶��б�Ϊ��
		Q->rear = NULL;//��Ҫ��βָ��Ҳָ���
	temp = P->data;
	free(P);
	return temp;
}
bool IsEmpty(LQueue Q){
	return Q->front == NULL ? true : false;
}
int Length(LQueue Q){
	int n = 0;
	QNode P = Q->front;
	while (P != NULL) {
		n++;
		P = P->next;
	}
	return n;
}
void DestroyQueue(LQueue Q) {
	//�ͷ�һ���ڴ�Ҫ������:1���ͷ�ָ������ָ�� 2������ָ��ָ���
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}
#endif