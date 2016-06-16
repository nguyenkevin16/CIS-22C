//		
//		AVL.h
//		
//		Team 4
//
//		Kevin Nguyen
//		Ka U Ieong
//		Bret Farley
//		Minting Ye
//
//		AVL class derived from bst class from "bst.h"
// 		For purposes of this assignment, this class only contains
//		insert functions (while maintaining a balanced tree),
//		and various print functions including display (prints indented tree)
//

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

		// Add Functions
		int bfactor(node<ItemType>* ptr);
		node<ItemType>* rr_rotation(node<ItemType>* parent);
		node<ItemType>* ll_rotation(node<ItemType>* parent);
		node<ItemType>* lr_rotation(node<ItemType>* parent);
		node<ItemType>* rl_rotation(node<ItemType>* parent);
		node<ItemType>* balance(node<ItemType>* temp);
		node<ItemType>* insert(node<ItemType>* ptr, node<ItemType>* newNodePtr);
		void add_ptr(ItemType* rbPtr);

		// Display and Save Functions
		void display(node<ItemType>* ptr, int level);
		void rprintInOrder(node<ItemType>* root);
		void rsaveInOrder(node<ItemType>* root, std::ostream& out, int& count);
};

//--------------------------------------------------------------
//						bfactor								
//--------------------------------------------------------------
//	in:		node* to root of tree to calculate balance factor
//	out:	int value containing balance factor
//
//	Calculates the balance factor (difference in heights) between
// 	left and right branches of a tree using bst get_height() method
template <typename ItemType, typename KeyType>
int AVL<ItemType, KeyType>::bfactor(node<ItemType>* ptr) {
	int l_height = get_height(ptr->get_left());
	int r_height = get_height(ptr->get_right());
	int b_factor = l_height - r_height;
	return b_factor;
}

//--------------------------------------------------------------
//						rr_rotation								
//--------------------------------------------------------------
//	in:		original parent node to start the rotation
//	out:	new parent node after rotation takes place
//
//	Performs a right of right rotation
template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::rr_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_right();
	parent->set_right(temp->get_left());
	temp->set_left(parent);
	return temp;
}

//--------------------------------------------------------------
//						ll_rotation								
//--------------------------------------------------------------
//	in:		original parent node to start the rotation
//	out:	new parent node after rotation takes place
//
//	Performs a left of left rotation
template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::ll_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_left();
	parent->set_left(temp->get_right());
	temp->set_right(parent);
	return temp;
}

//--------------------------------------------------------------
//						lr_rotation								
//--------------------------------------------------------------
//	in:		original parent node to start the rotation
//	out:	new parent node after rotation takes place
//
//	Performs a left of right rotation
template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::lr_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_left();
	parent->set_left(rr_rotation(temp));
	return ll_rotation(parent);
}

//--------------------------------------------------------------
//						rl_rotation								
//--------------------------------------------------------------
//	in:		original parent node to start the rotation
//	out:	new parent node after rotation takes place
//
//	Performs a right of left rotation
template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::rl_rotation(node<ItemType>* parent) {
	node<ItemType>* temp;
	temp = parent->get_right();
	parent->set_right(ll_rotation(temp));
	return rr_rotation(parent);
}

//--------------------------------------------------------------
//						balance								
//--------------------------------------------------------------
//	in:		node* to tree to balance
//	out:	returns a node* to balanced tree
//
//	Utilizes balance factor to rotate the subtree appropriately
// 	If balance factor == 0/1/-1, tree is already balanced
// 	If balance factor > 1 --> performs either ll or lr rotations
// 	If balance factor < -1 --> performs either rr or rl rotations
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

//--------------------------------------------------------------
//						add_ptr								
//--------------------------------------------------------------
//	in:		itemtype* to data item to add
//	out:	n/a
//
//	Takes in the pointer to data item, creates a new binarynode
//	linked to that data item; calls the AVL insert() method;
template <typename ItemType, typename KeyType>
void AVL<ItemType, KeyType>::add_ptr(ItemType* ptr) {
	node<ItemType>* newNodePtr = new node<ItemType>(ptr);
	root = insert(root, newNodePtr);
}

//--------------------------------------------------------------
//						insert								
//--------------------------------------------------------------
//	in:		node* of tree to add to, node* of node to add
//	out:	node* of tree (may change based on balancing)
//
//	We allow creation of AVLs using different SORT KEYs: names,
//	pts, and ppg.
//
//	It is possible to add to this section for different SORT KEYS
template <typename ItemType, typename KeyType>
node<ItemType>* AVL<ItemType, KeyType>::insert(node<ItemType>* root, node<ItemType>* newNodePtr) {
	if (key == "name") {
		if (root == nullptr) {
			return newNodePtr;
		} else if (newNodePtr->get_data()->get_name() < root->get_data()->get_name()) {
			root->set_left(insert(root->get_left(), newNodePtr));
			root = balance(root);
		} else if (newNodePtr->get_data()->get_name() >= root->get_data()->get_name()) {
			root->set_right(insert(root->get_right(), newNodePtr));
			root = balance(root);
		}
	} else if (key == "ppg") {
		if (root == nullptr) {
			return newNodePtr;
		} else if (newNodePtr->get_data()->get_ppg() < root->get_data()->get_ppg()) {
			root->set_left(insert(root->get_left(), newNodePtr));
			root = balance(root);
		} else if (newNodePtr->get_data()->get_ppg() >= root->get_data()->get_ppg()) {
			root->set_right(insert(root->get_right(), newNodePtr));
			root = balance(root);
		}
	} else if (key == "pts") {
		if (root == nullptr) {
			return newNodePtr;
		} else if (newNodePtr->get_data()->get_pts() < root->get_data()->get_pts()) {
			root->set_left(insert(root->get_left(), newNodePtr));
			root = balance(root);
		} else if (newNodePtr->get_data()->get_pts() >= root->get_data()->get_pts()) {
			root->set_right(insert(root->get_right(), newNodePtr));
			root = balance(root);
		}
	}

	return root;
}

//--------------------------------------------------------------
//						display								
//--------------------------------------------------------------
//	in:		node* of tree to display; int value to hold current tree "level"
//	out:	n/a
//
//	Displays a horizontal indented tree
// 	Utilizes recursive calls by changing the tree "level"
// 	Each level down, outputs a "tab" or # of spaces
//	Once "tabs" are outputted, outputs a single data point on the line
//
//	It is possible to add more display types the same as the AVL insert() method
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
	} else if (key == "ppg") {
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
	} else if (key == "pts") {
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

//--------------------------------------------------------------
//						rprintInOrder								
//--------------------------------------------------------------
//	in:		node* of tree to print
//	out:	n/a
//
//	Reverse Print in Order (right, root, left)
//	Prints data to screen in reverse in order traversal i.e. DESCENDING ORDER
//	Simply reverse left and right to print IN ORDER i.e. ASCENDING ORDER
template <typename ItemType, typename KeyType>
void AVL<ItemType, KeyType>::rprintInOrder(node<ItemType>* root) {
	if (root == nullptr) return;

	rprintInOrder(root->get_right());
	cout << setw(30) << left << root->get_data() << endl;
	rprintInOrder(root->get_left());
}

//--------------------------------------------------------------
//						rsaveInOrder								
//--------------------------------------------------------------
//	in:		node* of tree to save, ostream to print to, and count for numbering purposes
//	out:	n/a
//
//	Reverse save in Order (right, root, left)
//	Saves data to ostream in reverse in order traversal i.e. DESCENDING ORDER
//	Simply reverse left and right to print IN ORDER i.e. ASCENDING ORDER
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