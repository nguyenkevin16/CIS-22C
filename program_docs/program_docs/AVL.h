#ifndef AVL_H
#define AVL_H
#include "bst_player.h"
#include <cmath>

template <typename ItemType>
class AVL : public bst_player<ItemType> {
public:
	// Constructors
	AVL() : bst_player() {}
	AVL(ItemType* d) : bst_player(d) {}

	int bfactor(node<ItemType>* ptr);
	node<ItemType>* rr_rotation(node<ItemType>* parent);
	node<ItemType>* ll_rotation(node<ItemType>* parent);
	node<ItemType>* lr_rotation(node<ItemType>* parent);
	node<ItemType>* rl_rotation(node<ItemType>* parent);
	node<ItemType>* balance(node<ItemType>* temp);
	node<ItemType>* insert(node<ItemType>* ptr, node<ItemType>* newNodePtr);
	void add_ptr(ItemType* rbPtr);

	void display(node<ItemType>* ptr, int level);
};

template <typename ItemType>
int AVL<ItemType>::bfactor(node<ItemType>* ptr) {
	int l_height = get_height(ptr->get_left());
	int r_height = get_height(ptr->get_right());
	int b_factor = l_height - r_height;
	return b_factor;
}

template <typename ItemType>
node<ItemType>* AVL<ItemType>::rr_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_right();
	parent->set_right(temp->get_left());
	temp->set_left(parent);
	return temp;
}

template <typename ItemType>
node<ItemType>* AVL<ItemType>::ll_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_left();
	parent->set_left(temp->get_right());
	temp->set_right(parent);
	return temp;
}

template <typename ItemType>
node<ItemType>* AVL<ItemType>::lr_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_left();
	parent->set_left(rr_rotation(temp));
	return ll_rotation(parent);
}

template <typename ItemType>
node<ItemType>* AVL<ItemType>::rl_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_right();
	parent->set_right(ll_rotation(temp));
	return rr_rotation(parent);
}

template <typename ItemType>
node<ItemType>* AVL<ItemType>::balance(node<ItemType>* temp) {
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

template <typename ItemType>
void AVL<ItemType>::add_ptr(ItemType* rbPtr) {
	node<ItemType>* newNodePtr = new node<ItemType>(rbPtr);
	root = insert(root, newNodePtr);
}

template <typename ItemType>
node<ItemType>* AVL<ItemType>::insert(node<ItemType>* root, node<ItemType>* newNodePtr) {
	if (root == nullptr) {
		return newNodePtr;
	} else if (newNodePtr->get_data()->get_name() < root->get_data()->get_name()) {
		root->set_left(insert(root->get_left(), newNodePtr));
		root = balance(root);
	} else if (newNodePtr->get_data()->get_name() >= root->get_data()->get_name()) {
		root->set_right(insert(root->get_right(), newNodePtr));
		root = balance(root);
	}

	return root;
}

template <typename ItemType>
void AVL<ItemType>::display(node<ItemType>* ptr, int level) {
	int i;

	if (ptr != nullptr) {
		display(ptr->get_right(), level + 1);
		std::cout << endl;

		if (ptr == this->get_root())
			std::cout << "";
		for (i = 0; i < level && ptr != this->get_root(); i++)
			std::cout << "     ";
		std::cout << ptr->get_data()->get_name();
		display(ptr->get_left(), level + 1);
	}
}

#endif