#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BSTnode
{
private:
	typedef BSTnode* nodeptr;
	nodeptr parent;
	nodeptr left;
	nodeptr right;
	int data;

public:
	BSTnode()
	{
		parent = 0;
		left = 0;
		right = 0;
		data = 0;
	}
	BSTnode(int num)
	{
		parent = 0;
		left = 0;
		right = 0;
		data = num;
	}
	
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

		cout << data << " ";
		
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

		cout << data << " ";

		if (left != 0)
		{
			left->bprint();
		}

	}

	friend class BST;



};

class BST
{
private:
	typedef BSTnode* nodeptr;
	nodeptr head;

public:
	BST()
	{
		head = 0;
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
	void addObject(int num)
	{
		bool cont = 1;
		nodeptr cur;
		if (head == 0)
		{
			head = new BSTnode;
			head->data = num;
		}
		else
		{
			cur = head;
			while (cont != 0)
			{
				if (num < cur->data)
				{
					if (cur->left == 0)
					{
						cur->left = new BSTnode;
						(cur->left)->data = num;
						cont = 0;
					}
					else
						cur = cur->left;
				}
				else if (num > cur->data)
				{
					if (cur->right == 0)
					{
						cur->right = new BSTnode;
						(cur->right)->data = num;
						cont = 0;
					}
					else
						cur = cur->right;
				}
				else
				{
					cout << "Structural error. Rework code.\n\n";
					cont = 0;
				}
			}
		}
	}//End addObject

/*---------------------------------------------------------------------
print member function is pretty straightforward. Outputs from low to 
high.
---------------------------------------------------------------------*/
	void LowHigh()
	{
		/*------old code-------
		nodeptr cur;
		cur = head;

		//Takes "cursor" to leftmost node
		while (cur->left != 0)
			cur = cur->left;
		cout << cur->data;
		----------------------*/

		head->rprint();
		cout << endl;
	}

	void HighLow()
	{
		head->bprint();
		cout << endl;
	}


};
#endif // BST_H
