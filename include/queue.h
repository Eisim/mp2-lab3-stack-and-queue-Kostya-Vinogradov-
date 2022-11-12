#include <cstddef>
#include <algorithm>

template<typename T>
class Queue {
	T* data;
	size_t size;
	size_t capacity;
	size_t lptr, rptr;

	void resize() {
		capacity = (size + 1) * 2;
		T* tmp = new T[capacity];
		std::copy(data+rptr,data+size,tmp);
		std::copy(data,data+lptr,tmp+size-rptr);
		rptr = size;
		lptr = 0;
		delete[] data;
		data = tmp;

	}
public:
	Queue() {
		size = 0;
		capacity = 1;
		data = new T[capacity];
		lptr = 0;
		rptr = 0;
	}
	Queue(const Queue& q) {
		lptr = q.lptr;
		rptr = q.rptr;
		size = q.size;
		capacity = q.capacity;
		data = new T[capacity];
		std::copy(q.data, q.data + q.size, data);
	}
	~Queue() {
		lptr = 0;
		rptr = 0;
		size = 0;
		capacity = 0;
		delete[] data;
	}
	
	Queue& operator=(const Queue& q) {
		if (this == &q) return *this;
		size = q.size;
		capacity = q.capacity;
		lptr = q.lptr;
		rptr = q.rptr;
		delete[] data;
		data = new T[capacity];
		std::copy(q.data, q.data + q.size, data);

		return *this;
	}

	bool empty() { return !size; }

	void push(T elem) {
		data[rptr] = elem;
		rptr++;
		size++;
		if (rptr >= capacity)rptr = 0;
		if (rptr == lptr && size != 0) resize();

	}
	void pop() {
		if (size == 0 || lptr > rptr) throw "Queue is empty";
		data[lptr] = 0;
		lptr++;
		size--;
		if (lptr >=capacity)lptr = 0;
		
		

	}

	size_t getSize() { return size; }

	T top() {

		if(size<=0)throw "Queue is empty";
		return data[lptr];
	}
};
