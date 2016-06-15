#ifndef AVL_H
#define AVL_H
#include "bst.h"

template <typename ItemType, typename KeyType>
class AVL : public bst<ItemType> {
protected:
	KeyType key;
public:
	// Constructors
	AVL() : bst() {}
	AVL(KeyType k) : bst(), key(k) {}

	int bfactor(node<ItemType>* ptr);
	node<ItemType>* rr_rotation(node<ItemType>* parent);
	node<ItemType>* ll_rotation(node<ItemType>* parent);
	node<ItemType>* lr_rotation(node<ItemType>* parent);
	node<ItemType>* rl_rotation(node<ItemType>* parent);
	node<ItemType>* balance(node<ItemType>* temp);
	node<ItemType>* insert(node<ItemType>* ptr, node<ItemType>* newNodePtr);
	void add_ptr(ItemType* rbPtr);

	void display(node<ItemType>* ptr, int level);
	void rprintInOrder(node<ItemType>* root);
	void rsaveInOrder(node<ItemType>* root, std::ostream& out, int& count);
};

template <typename ItemType, typename KeyType>
int AVL<ItemType, KeyType>::bfactor(node<ItemType>* ptr) {
	int l_height = get_height(ptr->get_left());
	int r_height = get_height(ptr->get_right());
	int b_factor = l_height - r_height;
	return b_factor;
}

template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::rr_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_right();
	parent->set_right(temp->get_left());
	temp->set_left(parent);
	return temp;
}

template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::ll_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_left();
	parent->set_left(temp->get_right());
	temp->set_right(parent);
	return temp;
}

template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::lr_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_left();
	parent->set_left(rr_rotation(temp));
	return ll_rotation(parent);
}

template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::rl_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_right();
	parent->set_right(ll_rotation(temp));
	return rr_rotation(parent);
}

template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::balance(node<ItemType>* temp) {
	int b_factor = bfactor(temp);

	if (b_factor > 1) {
		if (bfactor(temp->get_left()) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	} else if (b_factor < -1) {
		if (bfactor(temp->get_right()) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	
	return temp;
}

template <typename ItemType, typename KeyType>
void AVL<ItemType, KeyType>::add_ptr(ItemType* rbPtr) {
	node<ItemType>* newNodePtr = new node<ItemType>(rbPtr);
	root = insert(root, newNodePtr);
}

template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::insert(node<ItemType>* root, node<ItemType>* newNodePtr) {
	if (key == "name") {
		if (root == nullptr) {
			return newNodePtr;
		}
		else if (newNodePtr->get_data()->get_name() < root->get_data()->get_name()) {
			root->set_left(insert(root->get_left(), newNodePtr));
			root = balance(root);
		}
		else if (newNodePtr->get_data()->get_name() >= root->get_data()->get_name()) {
			root->set_right(insert(root->get_right(), newNodePtr));
			root = balance(root);
		}

		return root;
	} else if (key == "ppg") {
		if (root == nullptr) {
			return newNodePtr;
		}
		else if (newNodePtr->get_data()->get_ppg() < root->get_data()->get_ppg()) {
			root->set_left(insert(root->get_left(), newNodePtr));
			root = balance(root);
		}
		else if (newNodePtr->get_data()->get_ppg() >= root->get_data()->get_ppg()) {
			root->set_right(insert(root->get_right(), newNodePtr));
			root = balance(root);
		}

		return root;
	} else if (key == "pts") {
		if (root == nullptr) {
			return newNodePtr;
		}
		else if (newNodePtr->get_data()->get_pts() < root->get_data()->get_pts()) {
			root->set_left(insert(root->get_left(), newNodePtr));
			root = balance(root);
		}
		else if (newNodePtr->get_data()->get_pts() >= root->get_data()->get_pts()) {
			root->set_right(insert(root->get_right(), newNodePtr));
			root = balance(root);
		}

		return root;
	}
}

template <typename ItemType, typename KeyType>
void AVL<ItemType, KeyType>::display(node<ItemType>* ptr, int level) {
	if (key == "name") {
		if (ptr != nullptr) {
			display(ptr->get_right(), level + 1);
			std::cout << endl;

			if (ptr == this->get_root())
				std::cout << "Root -> ";
			for (int i = 0; i < level && ptr != this->get_root(); i++)
				std::cout << "        ";

			std::cout << ptr->get_data()->get_name();
			display(ptr->get_left(), level + 1);
		}
	}

	else if (key == "ppg") {
		if (ptr != nullptr) {
			display(ptr->get_right(), level + 1);
			std::cout << endl;

			if (ptr == this->get_root())
				std::cout << "Root -> ";
			for (int i = 0; i < level && ptr != this->get_root(); i++)
				std::cout << "        ";

			std::cout << ptr->get_data()->get_ppg();
			display(ptr->get_left(), level + 1);
		}
	}

	else if (key == "pts") {
		if (ptr != nullptr) {
			display(ptr->get_right(), level + 1);
			std::cout << endl;

			if (ptr == this->get_root())
				std::cout << "Root -> ";
			for (int i = 0; i < level && ptr != this->get_root(); i++)
				std::cout << "        ";

			std::cout << ptr->get_data()->get_pts();
			display(ptr->get_left(), level + 1);
		}
	}
}

template <typename ItemType, typename KeyType>
void AVL<ItemType, KeyType>::rprintInOrder(node<ItemType>* root) {
	if (root == nullptr) return;

	rprintInOrder(root->get_right());
	cout << setw(30) << left << root->get_data() << endl;
	rprintInOrder(root->get_left());
}

template <typename ItemType, typename KeyType>
void AVL<ItemType, KeyType>::rsaveInOrder(node<ItemType>* root, std::ostream& out, int& count) {
	if (root == nullptr) return;

	rsaveInOrder(root->get_right(), out, count);
	out << count << ". ";
	if (count < 10) out << " ";
	count++;
	root->get_data()->save_player(out);
	rsaveInOrder(root->get_left(), out, count);
}

#endif