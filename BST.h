#pragma once
#ifndef BST_H
#define BST_H

#include <iostream>
#include "linkedList.h"
#include "person.h"

using namespace std;

template <typename Key, typename Type> class BSTnode
{
private:
	typedef BSTnode<Key, Type>* nodeptr;

	nodeptr left;
	nodeptr right;
	Type data;
	Key key;

public:
	BSTnode()
	{
		left = 0;
		right = 0;
		//data = 0;
		//key = 0;
	}
	BSTnode(Key k, Type obj)
	{
		left = 0;
		right = 0;
		data = obj;
		key = k;
	}

	//Accessor Functions
	Key getKey()
	{
		return key;
	}
	Type getData()
	{
		return data;
	}
	nodeptr getLeft()
	{
		return left;
	}
	nodeptr getRight()
	{
		return right;
	}
	void setKey(Key obj)
	{
		key = obj;
	}
	void setData(Type obj)
	{
		data = obj;
	}
	void setLeft(Key k, Type obj)
	{
		left = new BSTnode<Key, Type>;
		left->key = k;
		left->data = obj;
	}
	void setRight(Key k, Type obj)
	{
		right = new BSTnode<Key, Type>;
		right->key = k;
		right->data = obj;
	}
	
	/*-------------------------Print functions-----------------------------
	Note that all print functions require an overloaded << operator function
	in order to operate. This is designed to display an necessary data in 
	the desired fasion.
	----------------------------------------------------------------------*/

	/*----------------------------------------------------------------
	Stands for recursive print. For the purposes of outputting a sorted
	BST, using a recursive call was the most logical route in terms of
	both code simplicity and structural efficiency. The code is pretty
	straightforward and is broken into 3 steps:

	1)calls itself on the left node if the left exists
	2)outputs the data of the node
	3)calls itself on the right node if it exists

	The main problem with this implementation is that it calls itself
	on every single node within a BST. I will try to streamline this
	to make it more efficient.
	----------------------------------------------------------------*/

	void rprint()
	{
		if (left != 0)
		{
			left->rprint();
		}

		cout << data;

		if (right != 0)
		{
			right->rprint();
		}

	}

	//Backwards print
	void bprint()
	{
		if (right != 0)
		{
			right->bprint();
		}

		cout << data;

		if (left != 0)
		{
			left->bprint();
		}

	}

	// Pre-fix print
	void prePrint()
	{
		cout << data;

		if (left != 0)
		{
			left->rprint();
		}


		if (right != 0)
		{
			right->rprint();
		}

	}

	//Post-fixprint
	void postPrint()
	{
		if (left != 0)
		{
			left->rprint();
		}

		if (right != 0)
		{
			right->rprint();
		}

		cout << data;
	}

	//Breadth search/ print
	void breadth(int iter, int height, linkedList<Type> values[])
	{
		//add to appropriate spot
		values[iter].push(data);
		if (left != 0)
		{
			left->breadth(iter + 1, height, values);
		}

		if (right != 0)
		{
			right->breadth(iter + 1, height, values);
		}

		if (iter == 0)
		{
			for (int i = 0; i < height; i++)
			{
				(values[i]).print();
			}
		}
	}
	/*commented out for debugging
	linkedList fPrint(int iter, int height, linkedList<person> values[])
	{
		//add to appropriate spot
		values[iter].push(data);
		if (left != 0)
		{
			left->breadth(iter + 1, height, values);
		}

		if (right != 0)
		{
			right->breadth(iter + 1, height, values);
		}

		if (iter == 0)
		{
			return values;
		}
	}*/




	friend class BST;



};

template <typename Key, typename Type> class BsT
{
private:
	typedef BSTnode<Key, Type>* nodeptr;
	nodeptr head;
	int height;

public:
	BsT()
	{
		head = 0;
		height = 0;
	}

	/*---------------------------------------------------------------------
	addObject member function adds an object to the BST in the appropriate
	location. It uses a while loop to look at each object individually. If
	the data in question is less than the current object, it checks to see
	if there is an object to the left. If there isn't, it assigns the
	object to that location and breaks the loop, otherwise it makes the
	object on the left the next current node. This is likewise for the
	righthand side as well.
	---------------------------------------------------------------------*/



	void addObject(Key k, Type obj)
	{
		int count = 1;
		bool cont = 1;
		nodeptr cur;
		nodeptr add = new BSTnode<Key,Type>;
		add->setKey(k);
		add->setData(obj);
		if (head == 0)
		{
			head = new BSTnode < Key, Type>;
			head->setKey(k);
			head->setData(obj);
			height = 1;
		}
		else
		{
			cur = head;
			while (cont != 0)
			{
				count++;
				if (k < cur->getKey())
				{
					if (cur->getLeft() == 0)
					{
						cur->setLeft(k, obj);
						cont = 0;
					}
					else
						cur = cur->getLeft();
				}
				else if (k > cur->getKey())
				{
					if (cur->getRight() == 0)
					{
						cur->setRight(k, obj);
						cont = 0;
					}
					else
						cur = cur->getRight();
				}
				else
				{
					cout << "Structural error. Rework code.\n\n";
					cont = 0;
				}
			}
			if (count > height)
				height++;
		}
	}//End addObject

	 /*-------------------------------------------------------------------------
	 deleteNode member function is incredibly tricky with regards to its coding.
	 Considering that there are many different scenarios of deletion to take into
	 consideration, I have added a bunch of "safety nets" to make sure that the
	 right data gets allocated to the proprer location. This makes for some messy
	 code
	 --------------------------------------------------------------------------*/



	void deleteNode(Key k)
	{
		nodeptr cur;
		nodeptr prev = 0;
		cur = head;
		bool cont = true;
		bool remove = false;
		bool right = true;
		bool root = true;
		if (k != cur->key)
			root = false;

		while (cont)
		{
			if ((k < cur->key) && (cur->left != 0)) // less than exists
			{
				prev = cur;
				cur = cur->left;
				if (k == cur->key)
				{
					right = false;
					remove = true;
					cont = false;
				}
			}
			else if ((k > cur->key) && (cur->right != 0)) // greater than exists
			{
				prev = cur;
				cur = cur->right;
				if (k == cur->key)
				{
					remove = true;
					cont = false;
				}
			}

			else if (k == cur->key) // data is found
			{
				remove = true;
				cont = false;
			}
			else // data is not found or is in wrong location
			{
				cout << "The desired value could not be found\n";
				cont = false;
			}

		}//End search while loop
		if (remove)
		{
			nodeptr holder = 0;
			if ((cur->left == 0) && (cur->right == 0)) // is leaf node
			{
				if (root)
					delete[] head;
				else if (!right)// left of previous node
				{
					delete[] prev->left;
					delete[] cur;
				}
				else if (right)// right of previous node
				{
					delete[]prev->right;
					delete[] cur;
				}
				else
					cout << "\nError in removing leaf node\n";
			}
			else if ((cur->right != 0) && (cur->left != 0)) // has 2 child branches
			{
				nodeptr temp = cur; //marks node to be replaced
				nodeptr prev2 = 0; // used to properly remove nodes
				cur = (cur->right);
				while (cur->left != 0) // takes to left-most node on right
				{
					prev2 = cur;
					cur = cur->left;
				}
				if ((temp->right)->left == 0) //awk coding, but fits with implentation
				{
					prev2 = temp;
				}
				holder = cur;
				if ((cur->right != 0) && (prev2 != temp)) //2nd expression in case node to right is smallest number
					prev2->left = cur->right;

				delete[] cur;

				if (root)
				{
					cout << "\nTest\n";
					system("pause");
					holder->right = head->right;
					holder->left = head->left;
					head = 0;
					head = holder;
					holder = 0;
				}
				else if (!right) // left of parent
				{

					holder->left = temp->left;
					if (temp->right != holder)
						holder->right = temp->right;
					prev->left = 0;
					prev->left = holder;
					delete[] prev2->left;
				}
				else if (right)// right of parent
				{
					holder->left = temp->left;
					if (temp->right != holder)
						holder->right = temp->right;
					prev->right = 0;
					prev->right = holder;
					delete[] prev2->left;
				}
				else
					cout << "\nError in 2 branch node deletion\n";
			}
			else //has 1 child branch
			{
				if (root)
				{
					if (cur->left != 0) // If branch is on left
					{
						holder = cur->left;
						delete[] cur;
						head = 0;
						head = holder;
					}
					else // If branch is on right
					{
						holder = cur->right;
						delete[] cur;
						head = 0;
						head = holder;
					}
				}
				else if (!right) // left of parent node
				{
					if (cur->left != 0) // If branch is on left
					{
						holder = cur->left;
						delete[] cur;
						prev->left = 0;
						prev->left = holder;
					}
					else // If branch is on right
					{
						holder = cur->right;
						delete[] cur;
						prev->left = 0;
						prev->left = holder;
					}
				}
				else // right of parent node
				{
					if (cur->left != 0) // If branch is on left
					{
						holder = cur->left;
						delete[] cur;
						prev->right = 0;
						prev->right = holder;
					}
					else // If branch is on right
					{
						holder = cur->right;
						delete[] cur;
						prev->right = 0;
						prev->right = holder;
					}
				}
			}
		}
	}


	/*---------------------------------------------------------------------
	print member function is pretty straightforward. Outputs from low to
	high.
	---------------------------------------------------------------------*/



	void LowHigh()
	{

		head->rprint();
		cout << endl;
	}


	void HighLow()
	{
		head->bprint();
		cout << endl;
	}

	void preFix()
	{
		head->prePrint();
		cout << endl;
	}

	void postFix()
	{
		head->postPrint();
		cout << endl;
	}

	void breadthSort()
	{
		const int num = 4;
		linkedList<Type> out[num];
		head->breadth(0, height, out);
	}
	/* Commented out for later debugging
	linkedList filePrint()
	{
		const int num = 4;
		linkedList out[num];
		linkedList output = head->fPrint(0, height, out);
		return output;
	}
	*/

	//Search function ADD TO BST CLASS
	Type search(Key k)
	{
		bool cont = true;
		bool found = false;
		nodeptr cur = head;
		while (cont)
		{
			if (cur->key == k)
			{
				cont = false;
				found = true;
			}
			else if ((k < key) && (cur->left != 0))   // Goes left
				cur = cur->left;
			else if ((k > key) && (cur->right != 0)) // Goes right
				cur = cur->right;
			else                                     //not found
			{
				cout << "\nKey not found\n";
				cont = false;
			}
		}//End While loop
		if (found)
			return cur->data;
	}


};
#endif // BST_H