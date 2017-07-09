#include "AVLTree.h"

template <typename T>
struct AVLTree<T>::AVLNode {
	T data{};                                 // https://stackoverflow.com/questions/2143022/how-to-correctly-initialize-variable-of-template-type
	std::shared_ptr<AVLNode> left = nullptr;  // default member initializer
	std::shared_ptr<AVLNode> right = nullptr;
	unsigned height = 0;
	AVLNode(T val) : data(val) {}
};

template <typename T>
inline bool AVLTree<T>::insert(const T& val) {
	if (insert(val, root)) return true;
	return false;
}

template <typename T>
std::shared_ptr<typename AVLTree<T>::template AVLNode> AVLTree<T>::insert(
	const T& val, std::shared_ptr<AVLNode>& p) {
	if (p == nullptr) {
		p = std::make_shared<AVLNode>(val);
	}

	else if (val < p->data) {
		p->left = insert(val, p->left);
	}

	else if (val > p->data) {
		p->right = insert(val, p->right);
	}

	else {
		return p;
	}


	p->height = getHeight(p->left, p->right) + 1;

	adjustBalanceFactor(p, val);

	return p;
}

template <typename T>
void AVLTree<T>::adjustBalanceFactor(std::shared_ptr<AVLNode>& p,
	const T& val) {
	int balance = getHeight(p->right) - getHeight(p->left);

	if (abs(balance) <= 1) return;

	// Left Left Case
	else if (balance < -1 && val < p->left->data) {
		p = rotateRight(p);
	}

	// Right Right Case
	else if (balance > 1 && val > p->right->data) {
		p = rotateLeft(p);
	}

	// Left Right Case
	else if (balance < -1 && val > p->left->data) {
		p->left = rotateLeft(p->left);
		p = rotateRight(p);
	}

	// Right Left Case
	else if (balance > 1 && val < p->right->data) {
		p->right = rotateRight(p->right);
		p = rotateLeft(p);
	}
}

template <typename T>
std::shared_ptr<typename AVLTree<T>::template AVLNode> AVLTree<T>::rotateLeft(
	std::shared_ptr<AVLNode>& p) {
	auto temp = p->right;

	p->right = temp->left;
	temp->left = p;

	p->height = getHeight(p->left, p->right);
	temp->height = getHeight(temp->left, temp->right);

	return temp;
}

template <typename T>
std::shared_ptr<typename AVLTree<T>::template AVLNode> AVLTree<T>::rotateRight(
	std::shared_ptr<AVLNode>& p) {
	auto temp = p->left;

	p->left = temp->right;
	temp->right = p;

	p->height = getHeight(p->left, p->right);
	temp->height = getHeight(temp->left, temp->right);

	return temp;
}

template <typename T>
inline bool AVLTree<T>::search(const T& val) {
	if (search(val, root)) return true;
	return false;
}

template <typename T>
std::shared_ptr<typename AVLTree<T>::template AVLNode> AVLTree<T>::search(
	const T& val, std::shared_ptr<AVLNode>& p) {
	if (p == nullptr || p->data == val) {
		return p;
	}

	else if (val < p->data) {
		return search(val, p->left);
	}

	return search(val, p->right);
}

template<typename T>
inline T & AVLTree<T>::getMin(std::shared_ptr<AVLNode>&)
{
	if (p->left) {
		// make sure p!=nullptr
		return getMin(p->left);
	}

	return p->data;
}

template <typename T>
inline bool AVLTree<T>::remove(const T& val) {
	// auto temp = search(val, root);
	return remove(root, val);
}

template <typename T>
bool AVLTree<T>::remove(std::shared_ptr<AVLNode>& p, const T& val) {
	bool flag = false;
	if (p && p->data > val) {
		flag = remove(p->left, val);
	}

	else if (p && p->data < val) {
		flag = remove(p->right, val);
	}

	else if (p && p->data == val) {
		if (!p->left)
			p = p->right;
		else if (!p->right)
			p = p->left;
		else {
			auto temp = p->right;
			while (temp->left) temp = temp->left;
			p->data = temp->data;
			remove(p->right, p->data);
		}
		flag = true;
	}

	if (flag && p) {
		p->height = getHeight(p->left, p->right) + 1;
		adjustBalanceFactor(p, val);
	}

	return flag;
}

template <typename T>
void AVLTree<T>::printInorder(
	std::ostream& out, std::shared_ptr<typename AVLTree<T>::template AVLNode> p) const {
	if (p) {
		printInorder(out, p->left);
		out << p->data << " ";
		printInorder(out, p->right);
	}
}

template <typename U>
std::ostream& operator<<(std::ostream& out, const AVLTree<U>& A)  // TODO
{
	A.printInorder(out, A.root);
	return out;
}