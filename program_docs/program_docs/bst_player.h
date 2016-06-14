//		
//		bst_player.h
//		
//		Kevin Nguyen
//		Ka U Ieong
//
//		Copyright 2016
//
//		BST for "person.h" objects derived from "bst.h" template
//		Contains print, add, remove, modify, and search overrides
//

#ifndef bst_player_H
#define bst_player_H
#include <fstream>
#include <iomanip>
#include "bst.h"
#include "player.h"

template <typename ItemType>
class bst_player : public bst<ItemType> {
public:
	// Constructors
	bst_player() : bst() {}
	// bst_player(ItemType* d) : bst(d) {}

	// Print Methods
	void printPostOrder1(node<ItemType>* root);
	void printPostOrder2(node<ItemType>* root);
	void printBreadthFirst(node<ItemType>* root);
	void printGivenLevel(node<ItemType>* root, int level);

	// Add Methods
	void add(const ItemType& newData);
	virtual void add_ptr(ItemType* rbPtr);
	node<ItemType>* add2(node<ItemType>* subTreePtr, node<ItemType>* newNodePtr);

	// Search/Modify Methods
	node<ItemType>* search(node<ItemType>* root, ItemType& target);
	node<ItemType>* search_string(node<ItemType>* root, const std::string& target);
	void modify_person(node<ItemType>* root, const std::string& oldData, const std::string& newData);

	node<ItemType>* remove(node<ItemType>* root, ItemType* dltKey);
	void remove_string(node<ItemType>* root, const std::string& target);
};


//--------------------------------------------------------------
//					printPostOrder1								
//--------------------------------------------------------------
//	in:		node pointer to the tree, int choice (cout or output file)
//	out:	n/a
//
//	Opens an output file stream for file output
//	Calls printPostOrder2() to traverse the tree and output nodes
template <typename ItemType>
void bst_player<ItemType>::printPostOrder1(node<ItemType>* root) {
	// ofstream out(FILE_NAME, ios::trunc || ios::out);

	printPostOrder2(root);

	// out.close();
}

//--------------------------------------------------------------
//					printPostOrder2								
//--------------------------------------------------------------
//	in:		node pointer to the tree, ofstream object, int choice (cout or output file)
//	out:	n/a
//
//	Traverses the tree in post-order (left, right, root) or bottom-up format
//	Prints nodes to file output as it traverses up the tree
template <typename ItemType>
void bst_player<ItemType>::printPostOrder2(node<ItemType>* root) {
	if (root == nullptr) return;

	printPostOrder2(root->get_left());
	printPostOrder2(root->get_right());

	cout << setw(30) << left << root->get_data()->get_name() << endl;
}

//--------------------------------------------------------------
//					printBreadthFirst							
//--------------------------------------------------------------
//	in:		node pointer to the tree, int choice (cout or output file)
//	out:	n/a
//
//	Opens an output file stream for file output
//	Uses get_height to retrieve height of the tree
//	Calls printGivenLevel() to traverse the tree (left->right; up->down)
template <typename ItemType>
void bst_player<ItemType>::printBreadthFirst(node<ItemType>* root) {
	// ofstream out(FILE_BIRTHDAY, ios::trunc || ios::out);

	int h = get_height(root);
	for (int i = 1; i <= h; i++) printGivenLevel(root, i);

	// out.close();
}

//--------------------------------------------------------------
//						printGivenLevel
//--------------------------------------------------------------
//	in:		node pointer to the tree, int of the level, ofstream object, int choice (cout or output file)
//	out:	n/a
//
//	Calls itself recursively for every level
//	Base: Prints nodes to file output
template <typename ItemType>
void bst_player<ItemType>::printGivenLevel(node<ItemType>* root, int level) {

	if (root == nullptr) return;
	if (level == 1) {
		cout << setw(30) << left << root->get_data()->get_name() << endl;
	}
	else if (level > 1) {
		printGivenLevel(root->get_left(), level - 1);
		printGivenLevel(root->get_right(), level - 1);
	}
}

//--------------------------------------------------------------
//								add								
//--------------------------------------------------------------
//	in:		const object of any itemtype (newData)
//	out:	n/a
//
//	Dynamically allocates a new node, assigns newData to the new node
//	Calls add2 with the tree and new node
template <typename ItemType>
void bst_player<ItemType>::add(const ItemType& newData) {
	node<ItemType>* newNodePtr = new node<ItemType>(newData);
	root = add2(root, newNodePtr);
}


template <typename ItemType>
void bst_player<ItemType>::add_ptr(ItemType* rbPtr) {
	node<ItemType>* newNodePtr = new node<ItemType>(rbPtr);
	root = add2(root, newNodePtr);
}

//--------------------------------------------------------------
//								add2								
//--------------------------------------------------------------
//	in:		node pointer to the subtree, node pointer to newData
//	out:	node pointer to subtree
//
//	Recursively finds where to add the newData
//	Once found, adds the newData, returns subtree where newData was added
template <typename ItemType>
node<ItemType>* bst_player<ItemType>::add2(node<ItemType>* subTreePtr, node<ItemType>* newNodePtr) {
	if (subTreePtr == nullptr) return newNodePtr;

	else {
		node<ItemType>* left = subTreePtr->get_left();
		node<ItemType>* right = subTreePtr->get_right();

		if (newNodePtr->get_data()->get_name() >= subTreePtr->get_data()->get_name()) {
			right = add2(right, newNodePtr);
			subTreePtr->set_right(right);
		}
		else {
			left = add2(left, newNodePtr);
			subTreePtr->set_left(left);
		}

		return subTreePtr;
	}
}


//--------------------------------------------------------------
//								search							
//--------------------------------------------------------------
//	in:		node pointer to the tree, target of any itemtype
//	out:	node pointer to the found location
//
template <typename ItemType>
node<ItemType>* bst_player<ItemType>::search(node<ItemType>* root, ItemType& target) {
	if (root == nullptr)
		return nullptr;
	else if (target.get_name() == root->get_data()->get_name())
		return root;
	else if (target.get_name() < root->get_data()->get_name())
		search(root->get_left(), target);
	else if (target.get_name() > root->get_data()->get_name())
		search(root->get_right(), target);
}

//--------------------------------------------------------------
//								search_string							
//--------------------------------------------------------------
//	in:		node pointer to the tree, string target
//	out:	node pointer to the found location
//
//	Creates a person obj depending on the string passed to the function
//	Searches for person obj using normal search
//
template <typename ItemType>
node<ItemType>* bst_player<ItemType>::search_string(node<ItemType>* root, const std::string& target) {
	rb temp;
	temp.set_name(target);

	/*
	if (isdigit(target[0])) {
		temp.set_choice(1);
		temp.set_birthday(target);
		temp.set_name("null");
	}
	else {
		temp.set_choice(0);
		temp.set_birthday("null");
		temp.set_name(target);
	}
	*/

	return search(root, temp);
}


//--------------------------------------------------------------
//								modify_person							
//--------------------------------------------------------------
//	in:		node pointer to the tree, string oldData, string newData
//	out:	n/a
//
//	Finds and removes node of oldData from tree
//	Adds node of newData
//
template <typename ItemType>
void bst_player<ItemType>::modify_person(node<ItemType>* root, const std::string& oldData, const std::string& newData) {
	node<ItemType>* temp = search_string(root, oldData);
	person new_person;
	person old_person;

	if (temp != nullptr) {
		new_person = temp->get_data();
		old_person = temp->get_data();

		if (old_person.get_name() == oldData) new_person.set_name(newData);
		else if (old_person.get_birthday() == oldData) new_person.set_birthday(newData);
		else {
			std::cout << "could not be found." << std::endl;
			return;
		}
	}

	remove(root, old_person);
	add(new_person);
}



//--------------------------------------------------------------
//								remove							
//--------------------------------------------------------------
//	in:		node pointer to the tree, target dltKey
//	out:	node pointer to subtree where target is found
//
//	Finds and removes node where dltKey is found
//
template <typename ItemType>
node<ItemType>* bst_player<ItemType>::remove(node<ItemType>* root, ItemType* dltKey) {
	if (root == nullptr) return root;

	if (dltKey->get_name() < root->get_data()->get_name()) {
		root->set_left(remove(root->get_left(), dltKey));
	}

	else if (dltKey->get_name() > root->get_data()->get_name()) {
		root->set_right(remove(root->get_right(), dltKey));
	}

	else {
		if (root->get_left() == nullptr && root->get_right() == nullptr) {
			delete root;
			root = nullptr;
		}

		else if (root->get_left() == nullptr) {
			node<ItemType>* temp = root;
			root = root->get_right();
			delete temp;
		}

		else if (root->get_right() == nullptr) {
			node<ItemType>* temp = root;
			root = root->get_left();
			delete temp;
		}

		else {
			node<ItemType>* largest;
			largest = find_largest(root->get_left());

			root->set_data(largest->get_data());
			root->set_left(remove(root->get_left(), largest->get_data()));
		}
	}
	return root;
}

//--------------------------------------------------------------
//								remove_string							
//--------------------------------------------------------------
//	in:		node pointer to the tree, string target
//	out:	n/a
//
//	Creates a temp person obj based on input target string
//	Calls normal remove function with temp person obj to remove
//
template <typename ItemType>
void bst_player<ItemType>::remove_string(node<ItemType>* root, const std::string& target) {
	rb* temp = new rb(target);

	/*
	person temp;


	if (isdigit(target[0])) {
		temp.set_choice(1);
		temp.set_birthday(target);
		temp.set_name("null");
	}
	else {
		temp.set_choice(0);
		temp.set_birthday("null");
		temp.set_name(target);
	}
	*/

	remove(root, temp);
	delete temp;
	temp = nullptr;
}

#endif