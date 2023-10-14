template <typename T>
class Node {
public:
	T date;
	int score;
	Node* right;
	Node* left;
	Node(T date) {
		this->date = date;
		right = nullptr;
		left = nullptr;
		score = 1;
	}
};

template <typename T>
class BiTree {
Node<T>* root;
void add_more(T date, Node<T>* Newroot);
void remove_more(T date, Node<T>* deleteNode);
void show_more(Node<T>* right, Node<T>* left);
void show_right(Node<T>* right);
void show_left(Node<T>* left);
void check_more(Node<T>* right, Node<T>* left);
void check_right(Node<T>* right);
void check_left(Node<T>* left);
public:
	void check(Node<T>* root);
	void add(T date);
	void remove(T date);
	void show();
	BiTree();
	~BiTree();
};

template<typename T>
inline void BiTree<T>::check(Node<T>* root)
{
	return check_more(root->right, root->left);
}

template <typename T>
void BiTree<T>::add(T date) {
	if (root == nullptr) {
		root = new Node<T>(date);
	}
	else {
		if (date > root->date) {
			if (root->right != nullptr) {
				add_more(date, root->right);
			}
			else {
				root->right = new Node<T>(date);
			}

		}
		else if (date < root->date) {
			if (root->right != nullptr) {
				add_more(date, root->left);
			}
			else {
				root->left = new Node<T>(date);
			}
		}
		else {
			root->score++;
		}
	}
}

template <typename T>
void BiTree<T>::add_more(T date, Node<T>* newNode) {
	if (date > newNode->date) {
		if (newNode->right != nullptr) {
			add_more(date, newNode->right);
		}
		else {
			newNode->right = new Node<T>(date);
		}
	}
	else if (date < newNode->date) {
		if (newNode->left != nullptr) {
			add_more(date, newNode->left);
		}
		else {
			newNode->left = new Node<T>(date);
		}
	}
	else {
		newNode->score++;
	}
}

template<typename T>
void BiTree<T>::remove_more(T date, Node<T>* deleteNode)
{
	if (date == deleteNode->date) {
		if (deleteNode->date == 1) {
			if (deleteNode->left == nullptr && deleteNode->right != nullptr) {
				Node<T>* current = deleteNode;
				deleteNode = deleteNode->right;
				delete current;
			}
			else if (deleteNode->right == nullptr && deleteNode->left != nullptr) {
				Node<T>* current = deleteNode;
				deleteNode = deleteNode->left;
				delete current;
			}
			else {
				Node<T>* current = deleteNode->left;
				while (current->right != nullptr) {
					current = current->right;
				}
				if (current->left != nullptr) {
					deleteNode->date = current->date;
					deleteNode->score = current->score;
					current = current->left;
				}
				else {
					deleteNode->date = current->date;
					deleteNode->score = current->score;
					delete current;
					current = nullptr;
				}
			}
		}
		else {
			deleteNode->score--;
		}
	}
	else if (date > deleteNode->date) {
		if (deleteNode->right != nullptr) {
			remove_more(date, deleteNode->right);
		}
		else {
			std::cout << "node not found" << std::endl;
		}
	}
	else {
		if (deleteNode->left != nullptr) {
			remove_more(date, deleteNode->left);
		}
		else {
			std::cout << "node not found" << std::endl;
		}
	}
	check(root);
}


template <typename T>
void BiTree<T>::remove(T date) {
	if (root == nullptr) {
		std::cout << "tree is empty" << std::endl;
	}
	else {
		if (date == root->date) {
			if (root->score == 1) {
				if (root->left == nullptr && root->right != nullptr) {
					Node<T>* current = root;
					root = root->right;
					delete current;
				}
				else if (root->right == nullptr && root->left != nullptr) {
					Node<T>* current = root;
					root = root->left;
					delete current;
				}
				else {
					Node<T>* current = root->left;
					Node<T>* temp = current;
					while (current->right != nullptr) {
						if (current->right->right != nullptr) {
							temp = temp->right;
						}
						current = current->right;
					}
					if (current->left != nullptr) {
						root->date = current->date;
						root->score = current->score;
						current = current->left;
					}
					else {
						root->date = current->date;
						root->score = current->score;
						delete current;
						current = NULL;
						temp->right = NULL;
					}

				}
			}
		}
		else {
			if (date > root->date) {
				if (root->right != nullptr) {
					remove_more(date, root->right);
				}
				else {
					std::cout << "node not found";
				}

			}
			else if (date < root->date) {
				if (root->right != nullptr) {
					remove_more(date, root->left);
				}
				else {
					std::cout << "node not found" << std::endl;
				}
			}
		}
	}
	check(root);
}

template<typename T>
void BiTree<T>::show()
{
	std::cout << root->date << std::endl;
	if (root->right == nullptr && root->left == nullptr) {
		return;
	}
	else if (root->right == nullptr) {
		show_left(root->left);
	}
	else if (root->left == nullptr) {
		show_left(root->left);
	}
	else {
		show_more(root->right, root->left);
	}
	
}

template<typename T>
void BiTree<T>::show_more(Node<T>* right, Node<T>* left)
{
	if (right == nullptr && left == nullptr) {
		return;
	}
	else if (right == nullptr) {
		std::cout << left->date << std::endl;
		return show_more(left->right, left->left);
	}
	else if (left == nullptr) {
		std::cout << right->date << std::endl;
		return show_more(right->right, right->left);
	}
	else {
		std::cout << left->date << std::endl;
		std::cout << right->date << std::endl;
		return show_more(right->right, right->left), show_more(left->right, left->left);
	}
}

template<typename T>
inline void BiTree<T>::show_right(Node<T>* right)
{
	return show_more(right->right, right->left);
}

template<typename T>
inline void BiTree<T>::show_left(Node<T>* left)
{
	return show_more(left->right, left->left);
}

template<typename T>
inline void BiTree<T>::check_more(Node<T>* right, Node<T>* left)
{
	if (right->score < 1 && left->score < 1) {
			left = nullptr;
			right = nullptr;
	}
	else if (right->score < 1) {
		right = nullptr;
	}
	else if (left->score < 1) {
		left = nullptr;
	}
	if (right != nullptr) {
		return check_right(right);
	}
	if (left != nullptr) {
		return check_left(left);
	}
}

template<typename T>
inline void BiTree<T>::check_right(Node<T>* right)
{
	if (right->score < 1) {
		right = nullptr;
	}
	else {
		if (right != nullptr) {
			return check_more(right->right, right->left);
		}
		else {
			return;
		}
		
	}
}

template<typename T>
inline void BiTree<T>::check_left(Node<T>* left)
{
	if (left->score < 1) {
		left = nullptr;
	}
	else {
		if (left != nullptr) {
			return check_more(left->right, left->left);
		}else{
				return;
		}
		
	}
}

template<typename T>
BiTree<T>::BiTree()
{

}

template<typename T>
BiTree<T>::~BiTree() {

}
