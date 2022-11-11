#include <algorithm>
#include <cstddef>
template<typename T>
class Stack {
	T* data;
	size_t size;
	size_t capacity;

	void resize() {
		capacity = (size + 1) * 2;
		T* tmp=new T[capacity];
		std::copy(data,data+size,tmp);
		delete[] data;
		data = tmp;
	}

public:
	Stack() {
		size = 0;
		capacity = 1;
		data = new T[capacity];
	}

	Stack(const Stack& st) {
		size = st.size;
		capacity = st.capacity;
		data = new T[capacity];
		std::copy(st.data, st.data + st.size, data);


	}
	~Stack() {
		size = 0;
		capacity = 0;
		delete[] data;
	}

	Stack& operator=(const Stack st) {
		if (this == &st) return *this;
		size = st.size;
		capacity = st.capacity;

		delete[] data;
		data = new T[capacity];
		std::copy(st.data, st.data + st.size, data);


		return *this;
	}

	bool empty() { return !size; }
	void push(T elem) {
		if (size  >= capacity) resize();
		data[size] = elem;
		size++;
	}
	
	void pop() {
		if ((size) <= 0) throw "Stack is empty";
		
		size-=1;
		data[size] = 0;
		
	}
	size_t getSize() { return size; }

	T top() {
		if (size <= 0) throw "Stack is empty";
		return data[size-1];
	}
};
