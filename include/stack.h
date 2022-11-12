﻿

template<typename T>
class Stack {
	T data;
	void resize(const int& size);

public:
	Stack();
	Stack(const Stack& st);
	~Stack();

	Stack& operator=(const Stack& q);

	bool empty();
	void push(T elem);
	void pop();
	T top();
};
