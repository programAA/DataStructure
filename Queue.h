#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <iomanip>
#define QUEUE_INIT_SIZE 32

 template <typename T>
 class Queue {
 private:
	 T * Data;
	 int Front, Rear;
	 int Size;
 public:
	 Queue() {
		 Data = (T*)malloc(QUEUE_INIT_SIZE * sizeof(T));
		 Front = Rear = 0;
		 Size = QUEUE_INIT_SIZE;
	 }
	 Queue(int size) {
		 Data = (T*)malloc(size * sizeof(T));
		 Front = Rear = 0;
		 Size = size;
	 }
	 Queue(Queue &Q) {
		 Data = (T*)malloc(Q.Size * sizeof(T));
		 Front = Q.Front;
		 Rear = Q.Rear;
		 Size = Q.Size;
		 if (Size > 0) {
			 if (Rear > Front) {
				 for (int i = Front; i < Rear; i++)
					 Data[i] = Q.Data[i];
			 }
			 else {//Rear<Front
				 for (int i = Front; i < Size; i++)
					 Data[i] = Q.Data[i];
				 for (int i = 0; i < Rear; i++)
					 Data[i] = Q.Data[i];
			 }
		 }
	 }
	 ~Queue() {
		 free(Data);
	 }
	 void ReAssign() {
		 T *newbase = (T*)realloc(Data, 2 * Size * sizeof(T));
		 if (newbase == NULL) {
			 std::cout << "InsufficientDynamicMemory" << std::endl;
			 exit(1);
		 }
		 Data = newbase;
		 if (Rear != Size - 1) {
			 for (int i = 0; i < Rear; i++)
				 Data[i + Size] = Data[i];
			 Rear += Size;
		 }
		 Size *= 2;
	 }
	 void EnQueue(T x) {
		 if ((Rear + 1) % Size == Front)
			 ReAssign();
		 Data[Rear] = x;
		 Rear = (Rear + 1) % Size;
	 }
	 T DeQueue() {
		 if (Rear == Front) {
			 std::cout << "QUEUE NULL" << std::endl;
			 exit(1);
		 }
		 else {
			 T temp;
			 temp = Data[Front];
			 Front = (Front + 1) % Size;
			 return temp;
		 }
	 }
	 int GetLength() {
		 return (Rear - Front + Size) % Size;
	 }
	 bool IsEmpty() {
		 return Rear == Front ? true : false;
	 }
	 void Traverse() {
		 T temp;
		 int count = 0;
		 if (Front < Rear) {
			 for (int i = Front; i < Rear; i++) {
				 temp = Data[i];
				 std::cout << std::setw(5) << std::left << temp;
				 count++;
				 if (count % 10 == 0)
					 std::cout << std::endl;
			 }
		 }
		 else {//Front>Rear
			 for (int i = Front; i < Size; i++) {
				 temp = Data[i];
				 std::cout << std::setw(5) << std::left<<temp;
				 count++;
				 if (count % 10 == 0)
					 std::cout << std::endl;
			 }
			 for (int i = 0; i < Rear; i++) {
				 temp = Data[i];
				 std::cout << std::setw(5) << std::left<<temp;
				 count++;
				 if (count % 10 == 0)
					 std::cout << std::endl;
			 }
		 }
	 }
 };
#endif