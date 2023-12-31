template <typename T>
class Stack {
private:
	template <typename T>
	class Node {
	public:
		T date;
		Node* ptr;
	};	
	int size = 0;
	Node<T>* head = new Node<T>;
public:
	
	//Добавление элемента в начало стека
	void add(T date);

	//Показ элемента вершины стека
	T show();

	//Удаление элемента вершины стека
	void remove();

	//Отчистка стека
	void clear();

	Stack(T* arr, int score);
	
	Stack();

	~Stack();
};

template <typename T>
Stack<T>::Stack(T* arr, int score) {
	for (int i = 0; i < score; ++i) {
		if (size == 0) {
			head->date = arr[i];
			size++;
		}
		else {
			Node<T>* NewNode = new Node<T>;
			NewNode->ptr = head->ptr;
			NewNode->date = head->date;
			head->ptr = NewNode;
			head->date = arr[i];
			size++;
		}
	}
}

template <typename T>
Stack<T>::Stack() {

}


template <typename T>
void Stack<T>::add(T date) {
	if (head->ptr == nullptr && size == 0) {
		head = new Node<T>;
		head->date = date;
		size++;
	}
	else {
		Node<T>* NewNode = new Node<T>;
		NewNode->ptr = head->ptr;
		NewNode->date = head->date;
		head->ptr = NewNode;
		head->date = date;
		size++;
	}
}

template <typename T>
void Stack<T>::remove() {
	if (head->ptr == nullptr) {
		size--;
	}
	else {
		Node<T>* CurrentNode = new Node<T>;
		CurrentNode = head;
		head = head->ptr;
		delete CurrentNode;
		size--;
	}
}

template <typename T>
void Stack<T>::clear() {
	while (size > 0) {
		remove();
	}
}

template <typename T>
T Stack<T>::show() {
	if (size == 0) {
		throw;
	}
	else {
		return head->date;
	}

}

template <typename T>
Stack<T>::~Stack() {
	clear();
}
