template <typename T>
class Queue {
	template <typename T>
	class Node {
	public:
		T date;
		Node* pref;
		Node* next;
		Node() {
			pref = nullptr;
			next = nullptr;
		}
	};
	int size = 0;
	Node<T>* head = new Node<T>;
	Node<T>* end = new Node<T>;
public:
	void push_back(T date);
	void remove();
	T show();
	void clear();
	~Queue();
};

template <typename T>
void Queue<T>::push_back(T date) {
	if (size == 0) {
		head->next = end;
		end->pref = head;
		end->date = date;
		size++;
	}
	else if (size == 1) {
		head->date = end->date;
		end->date = date;
		size++;
	}
	else {
		Node<T>* NewNode = new Node<T>;
		head->next = NewNode;
		NewNode->pref = end->pref;
		end->pref = NewNode;
		NewNode->next = end;
		NewNode->date = end->date;
		end->date = date;
		size++;
	}

}

template <typename T>
void Queue<T>::remove() {
	if (size > 2) {
		Node<T>* CurrentNode = new Node<T>;
		CurrentNode = head;
		head = head->next;
		size--;
		delete CurrentNode;
	}
	else if (size <= 2) {
		size--;
		head->date = end->date;
	}

}

template <typename T>
T Queue<T>::show() {
	if (size > 0) {
		return head->date;
	}
	else {
		throw;
	}

}

template <typename T>
void Queue<T>::clear() {
	while (size > 2) {
		remove();
	}
}

template <typename T>
Queue<T>::~Queue() {
	clear();
}
