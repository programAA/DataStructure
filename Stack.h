#ifndef STACK_H
#define STACK_H
#include <iostream>
#define STACK_INIT_SIZE 100

template <typename T>
class Stack {
private:
	T *Base;
	T *Top;
	int Size;//ÈÝÁ¿
public:
	Stack() {
		Base = Top = (T*)malloc(STACK_INIT_SIZE * sizeof(T));
		if (Base == NULL) {
			std::cout << "InsufficientDynamicMemory" << std::endl;
			exit(1);
		}
		Size = STACK_INIT_SIZE;
	}
	Stack(Stack &S) {//Éî¿½±´
		Base = (T*)malloc(S.Size * sizeof(T));
		if (Base == NULL) {
			std::cout << "InsufficientDynamicMemory" << std::endl;
			exit(1);
		}
		Top = Base + S.GetLength();
		Size = S.Size;
		for (int i = 0; i < S.GetLength(); i++) {
			Base[i] = S.Base[i];
		}
	}
	void ReAssign() {
		T *newbase = (T*)realloc(Base, Size * 2 * sizeof(T));
		if (newbase == NULL) {
			std::cout << "InsufficientDynamicMemory" << std::endl;
			exit(1);
		}
		Base = newbase;
		Top = Base + Size - 1;
		Size *= 2;
	}
	void Push(T x) {
		if (GetLength() == Size - 1) {
			ReAssign();
		}
		*Top = x;
		Top++;
	}
	T Pop() {
		if (Base == Top) {
			std::cout << "TheStackIsEmpty" << std::endl;
			exit(1);
		}
		else {
			Top--;
			return *Top;
		}
	}
	bool IsEmpty() {
		return Top == Base ? true : false;
	}
	int GetLength() {
		return Top - Base;
	}
	T GetTop() {
		if (Base == Top) {
			std::cout << "TheStackIsEmpty" << std::endl;
			exit(1);
		}
		return *(Top - 1);
	}
};

#endif