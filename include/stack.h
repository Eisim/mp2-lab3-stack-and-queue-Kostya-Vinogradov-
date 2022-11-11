

template<typename T>
class Stack {
	T* data;
	size_t size;
	size_t capacity;
	void resize(const int& size);

public:
	Stack();
	Stack(const Stack& st);
	~Stack();

	Stack& operator=(const Stack& q);

	bool empty();
	T push(T elem);
	void pop();
	T top();
};
