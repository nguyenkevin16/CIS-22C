//		
//		node.h
//		
//		Kevin Nguyen
//		Ka U Ieong
//
//		Copyright 2016
//
//		Template class node with 3 data members: data, left pointer, and right pointer
//		Data can be any native or non-native itemtype
//		For non-native items, must override set_data() or overload the assignment= operator in your class definition
//

#ifndef binarynode_H
#define binarynode_H

template <typename ItemType>
class node {
	protected:
		// typedef node<ItemType>* bst_nodeptr;
		// typedef ItemType* dataptr;

		ItemType* data;
		node<ItemType>* left;
		node<ItemType>* right;
	public:
		// Constructors (Automatically sets next to 0 or nullptr)
		node() : data(nullptr), left(nullptr), right(nullptr) {}
		node(ItemType* d) : data(d), left(nullptr), right(nullptr) {}
		node(ItemType* d, node<ItemType>* p1, node<ItemType>* p2) : data(d), left(p1), right(p2) {}

		// Accessors
		ItemType* get_data() { return data; }
		node<ItemType>* get_left() const { return left; }
		node<ItemType>* get_right() const { return right; }

		// Mutators
		void set_data (ItemType* d) { data = d; }
		void set_left(node<ItemType>* ptr) { left = ptr; }
		void set_right(node<ItemType>* ptr) { right = ptr; }

		// Methods
		bool isLeaf() const;
		int numChild() const;
};


//		isLeaf
//	in:		n/a
//	out:	true if this node is a leaf (no children); false if it has children
//
template <typename ItemType>
bool node<ItemType>::isLeaf() const {
	if (left == nullptr && right == nullptr && data != nullptr) return true;
	else return false;
}


//		numChild
//	in:		n/a
//	out:	int for how many direct children this node has (only 1 level)
//
template <typename ItemType>
int node<ItemType>::numChild() const {
	int num;

	if (left != nullptr) num++;
	if (right != nullptr) num++;

	return num;
}

#endif