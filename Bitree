template <typename T>
class Node {
public:
	T date;
	int score;
	Node* right;
	Node* left;
	Node() {
		right = nullptr;
		left = nullptr;
	}
};

template <typename T>
class BiTree {
private:
	Node<T>* root;
	void addMore(Node<T>* newRoot, T date);
	Node* findDelete(Node<T>* nodeDel, T date);
	void removeMore(Node<T>* newNode, Node<T>* toDel, T date);
public:
	void add(T date);
	void remove(T date);

};

template <typename T>
void BiTree<T>::add(T date) {
	if (root == nullptr) {
		root = new Node<T>;
		root->date = date;
	}
	else {
		if (date >= root->date) {
			addMore(root->right, date);
		}
		else {
			addMore(root->left, date);
		}
	}
}

template <typename T>
void BiTree<T>::addMore(Node<T>* newRoot, T date) {
	if (newRoot == nullptr) {
		newRoot = new Node<T>;
		newRoot->date = date;
		return;
	}
	else {
		if (date >= newRoot->date) {
			addMore(newRoot->right, date);
		}
		else {
			addMore(newRoot->left, date);
		}
	}
}

template <typename T>
void BiTree<T>::remove(T date) {
	Node<T>* delNode;
	if (root->date = date) {
		delNode = root;
	}
	else {
		if (date > root->date && root->right!= nullptr) {
			delNode = findDelete(root->right);
		}
		else {
			delNode = findDelete(root->left);
		}

	}
}

template <typename T>
Node<T>* BiTree<T>::findDelete(Node<T>* nodeDel, T date) {
	if (date == nodeDel->date) {
		return nodeDel;
	}
	else{
		if (date > nodeDel->date && nodeDel->right!=nullptr) {
			findDelete(nodeDel->right, date);
		}
		else if (date < nodeDel->date && nodeDel->left != nullptr) {
			findDelete(nodeDel->left, date);
		}
		else {
			throw;
		}
	}
}
