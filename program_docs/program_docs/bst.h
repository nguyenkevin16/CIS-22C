//		
//		bst.h
//		
//		Kevin Nguyen
//		Ka U Ieong
//
//		Copyright 2016
//
//		Template class for bst - one "root" pointer to the BST
//		Contains various helper methods
//		Used to derive BSTs for other datatypes
//

#ifndef BST_H
#define BST_H
#include "binarynode.h"

template <typename ItemType>
class bst {
protected:
	//typedef binarynode<ItemType>* nodeptr;
	//typedef ItemType* dataptr;

	node<ItemType>* root;
public:
	// Constructors
	bst() : root(nullptr) {}
	// bst(ItemType* d) : root(new node<ItemType>(d)) {}
	bst(node<ItemType>* ptr) { root = copyTree(ptr); }						// Copy Constructor
	~bst() { destroyTree(root); }											// Destructor

	// Accessor/Mutator
	node<ItemType>* get_root() const { return root; }
	void set_root(node<ItemType>* d) { root = d; }

	// Helper Methods
	bool isEmpty() const;
	void destroyTree(node<ItemType>* ptr);
	int get_height(node<ItemType>* node);
	node<ItemType>* find_largest(node<ItemType>* root);
	node<ItemType>* copyTree(node<ItemType>* root);
};

//--------------------------------------------------------------
//						destroyTree								
//--------------------------------------------------------------
//	in:		pointer to the "root" node of the tree to be deleted
//	out:	n/a
template <typename ItemType>
void bst<ItemType>::destroyTree(node<ItemType>* ptr) {
	if (ptr != nullptr) {
		destroyTree(ptr->get_left());
		destroyTree(ptr->get_right());
		delete ptr;
	}
}

//--------------------------------------------------------------
//						copyTree								
//--------------------------------------------------------------
//	in:		pointer to the "root" node of the tree to be copied
//	out:	a pointer to the "root" node of the new tree
template <typename ItemType>
node<ItemType>* bst<ItemType>::copyTree(node<ItemType>* root) {
	node<ItemType>* newRoot = nullptr;

	// Copy tree during a preorder traversal
	if (root != nullptr) {
		// Copy nodes recursively
		newRoot = new node<ItemType>(root->get_data());
		newRoot->set_left(copyTree(root->get_left()));
		newRoot->set_right(copyTree(root->get_right()));
	}

	return newRoot;
}


//--------------------------------------------------------------
//						isEmpty									
//--------------------------------------------------------------
//	in:		n/a
//	out:	true if the tree is empty; false if not
template <typename ItemType>
bool bst<ItemType>::isEmpty() const {
	return root == nullptr;
}

//--------------------------------------------------------------
//						get_height
//--------------------------------------------------------------
//	in:		node pointer to the tree
//	out:	int of the height of the tree
template <typename ItemType>
int bst<ItemType>::get_height(node<ItemType>* node) {
	if (node == nullptr) return 0;
	else {
		// compute the height of each subtree 
		int lheight = get_height(node->get_left());
		int rheight = get_height(node->get_right());

		// use the larger one
		if (lheight > rheight) return(lheight + 1);
		else return(rheight + 1);
	}
}


//--------------------------------------------------------------
//					find_largest
//--------------------------------------------------------------
//	in:		node pointer to the tree
//	out:	node pointer to largest node in the tree
template <typename ItemType>
node<ItemType>* bst<ItemType>::find_largest(node<ItemType>* root) {
	if (root->get_right() == nullptr) {
		return root;
	}

	return find_largest(root->get_right());
}

#endif