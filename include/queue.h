

template<typename T>
class Queue {
	T* data;
	size_t size;
	size_t capacity;
	void resize(const int& size);

public:
	Queue();
	Queue(const Queue& q);
	~Queue();
	
	Queue& operator=(const Queue& q);

	bool empty();
	T push(T elem);
	void pop();
	T top();
};
