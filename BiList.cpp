#include <iostream>

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	int getSize() { return Size; };
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	void DeleAllOccurrences(T date);
	void DelTheFollowing(T date);
	void showlist(bool startfrom = 1);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size;//кол-во эл-ов в списке
	Node<T>* head;//голова списка
	Node<T>* tail;//хвост списка
};

template<typename T>
List<T>::List()//+
{
	Size = 0;
	head = tail = nullptr;
}

template<typename T>
List<T>::~List()//+
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)//+
{
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		Node<T>* current = new Node<T>(data);
		tail->pNext = current;
		current->pPrev = tail;
		tail = current;
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)//+
{
	if ((Size / 2 - index) > 0)//1st half
	{
		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size;
		Node<T>* current = this->tail;
		while (true)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pPrev;
			counter--;
		}
	}
}

template<typename T>
void List<T>::pop_front()//+
{
	if (Size == 1)
	{
		delete head;
	}
	else
	{
		Node<T>* temp = head;
		head = head->pNext;
		head->pPrev = nullptr;
		delete temp;
	}
	Size--;
}

template<typename T>
inline void List<T>::clear()//+
{
	while (Size)
		pop_front();
}

template<typename T>
void List<T>::push_front(T data)//+
{
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		Node<T>* current = new Node<T>(data);
		head->pPrev = current;
		current->pNext = head;
		head = current;
	}
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)//+
{
	if (!index)
		push_front(data);
	else if (index == Size)
		push_back(data);
	else if (Size / 2 - index > 0)//1st half
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		previous->pNext = new Node<T>(data, previous->pNext, previous);
		Size++;

	}
	else//2nd half
	{
		Node<T>* next = this->tail;

		for (int i = Size - 1; i >= index; i--)
		{
			next = next->pPrev;
		}
		next->pNext = new Node<T>(data, next->pNext, next);
		next->pNext->pNext->pPrev = next->pNext;
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)//+
{
	if (!index)
		pop_front();
	else if (index == Size - 1)
		pop_back();
	else if (Size / 2 - index > 0)
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;
		toDelete->pNext->pPrev = previous;
		delete toDelete;
		Size--;
	}
	else
	{
		Node<T>* next = this->tail;

		for (int i = Size - 1; i > index + 1; i--)
		{
			next = next->pPrev;
		}

		Node<T>* toDelete = next->pPrev;

		next->pPrev = toDelete->pPrev;
		toDelete->pPrev->pNext = next;

		delete toDelete;
		Size--;
	}
}

template <typename T>
void List<T>::DeleAllOccurrences(T date) {
	Node<T> *current = head;
	while (current->pNext!= nullptr) {
		if (current->data == date) {
			Node<T> *delNode = current;
			if (current->pPrev == nullptr) {
				current = current->pNext;
				head = head->pNext;
				delete delNode;
				head->pPrev = nullptr;
				Size--;
			}
			else {
				current->pPrev->pNext = current->pNext;
				current->pNext->pPrev = current->pPrev;
				current = current->pNext;
				delete delNode;
				Size--;
			}
			
		}
		else {
			current = current->pNext;
		}
	}
	if (current->data == date) {
		tail = tail->pPrev;
		delete current;
		tail->pNext = nullptr;
		Size--;
	}
}

template <typename T>
void List<T>::DelTheFollowing(T date) {
	Node<T>* current = head;
	while (current->pNext != nullptr) {
		if (current->data == date) {
			if (current->pNext->pNext != nullptr) {
				Node<T> *delNode = current->pNext;
				current->pNext->pNext->pPrev = current;
				current->pNext = current->pNext->pNext;
				current = current->pNext;
				delete delNode;
				Size--;
			}
			else {
				Node<T>* delNode = current->pNext;
				tail = tail->pPrev;
				delete delNode;
				tail->pNext = nullptr;
				Size--;
			}
		}
		else {
			current = current->pNext;
		}
	}

}

template<typename T>
inline void List<T>::pop_back()//+
{
	Node<T>* current = tail;
	tail->pPrev->pNext = nullptr;
	delete current;
	Size--;
}



template<typename T>
void List<T>::showlist(bool startfrom)//1-head,0-tail//+
{
	if (startfrom)
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << '\n';
			current = current->pNext;
		}
	}
	else
	{
		Node<T>* current = tail;
		while (current != nullptr)
		{
			std::cout << current->data << '\n';
			current = current->pPrev;
		}
	}
}
main.cpp
	int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	int elem;
	List<int> lst;
	do {
		std::cout << "Для того, что бы выполнить действие введите: " << '\n';
		std::cout << "Добавление в начало: " << '1' << '\n';
		std::cout << "Добавление в конец: " << '2' << '\n';
		std::cout << "Добавление по индексу: " << '3' << '\n';
		std::cout << "Удаление начала: " << '4' << '\n';
		std::cout << "Удаление конца: " << '5' << '\n';
		std::cout << "Удаление по индексу: " << '6' << '\n';
		std::cout << "Удаление всех вхождений: " << '7' << '\n';
		std::cout << "Удаление по элементу после элемента вхождения: " << '8' << '\n';
		std::cout << "Поиск по индексы с возвратом значения: " << '9' << '\n';
		std::cout << "Полная отчистка: " << "10" << '\n';
		std::cout << "Показать лист: " << "11" << '\n';
		std::cout << "Завершить программу: " << "12" << '\n';
		std::cout << '\n';
		std::cout << "Введите число: ";
		std::cin >> choice;
		switch (choice) {
			case 1:
				std::cout << "Введите элемент для ввода: ";
				std::cin >> elem;
				lst.push_front(elem);
				std::cout << '\n';
				break;
			case 2:
				std::cout << "Введите элемент для ввода: ";
				std::cin >> elem;
				lst.push_back(elem);
				std::cout << '\n';
				break;

			case 3:
				std::cout << "Введите индкса для добавления: ";
				std::cin >> elem;
				int elem_2;
				std::cout << "Введите элемент для ввода: ";
				std::cin >> elem_2;
				lst.insert(elem_2, elem);
				std::cout << '\n';
				break;
			case 4:
				lst.pop_front();
				std::cout << '\n';
				break;
			case 5:
				lst.pop_back();
				std::cout << '\n';
				break;
			case 6:
				std::cout << "Введите индкс для удаления: ";
				std::cin >> elem;
				lst.removeAt(elem);
				std::cout << '\n';
				break;
			case 7:
				std::cout << "Введите элемент для удаления по вхождению: ";
				std::cin >> elem;
				lst.DeleAllOccurrences(elem);
				std::cout << '\n';
				break;
			case 8:
				std::cout << "Введите элемент для удаления после него: ";
				std::cin >> elem;
				lst.DelTheFollowing(elem);
				std::cout << '\n';
				break;
			case 9:
				std::cout << "Введите индекс элемента для возврата по индексу: ";
				std::cin >> elem;
				std::cout << lst[elem] << '\n';
				break;
			case 10:
				lst.clear();
				std::cout << '\n';
				break;
			case 11:
				lst.showlist();
				std::cout << '\n';

		}
			
	} while (choice != 12);
}
