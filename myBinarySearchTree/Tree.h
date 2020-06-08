#pragma once

#include <iostream>
#include <queue>

#include "Node.h"



template <typename T>
class Tree {

	Node<T>* root;

	
	void insert(Node<T>** root, T x); //>Insert function used recursively

	bool search(Node<T>* root, T x); //> Search a tree recursively

	int getHeight(Node<T>* root); //> Return height of tree

	void printPreorder(Node<T>* root); //>Print nodes in preorder order 

	void printInorder(Node<T>* root); //> Print nodes in inorder form(sorted order in a bst)

	void printPostorder(Node<T>* root); //> Print nodes in post order form

	Node<T>* findMin(Node<T>* root); //> Find min value in a tree

	Node<T>* remove(Node<T>* root, T x); //> Remove a node from tree

	T findNext(Node<T>* root, T x); //> Find the next greater element in tree

	Node<T>* find(Node<T>* root, T x); //> Find the node which holds x

public:

	Tree();

	//Insert data into a tree
	void insert(T x);


	void remove(T x);

	//Search the tree for a value
	bool search(T x);

	//Get Max value in tree
	T max();
	
	//Get min value in tree
	T min();

	int getHeight();

	bool isEmpty();

	//Prints tree data in bread first order
	void printB();

	//Print tree data in Predorder depth first order
	void printPreorder();

	//print tree data in inorder depth first order
	void printInorder();

	//print tree data in postorder depth first order
	void printPostorder();

	//Find next greater value
	T findNext(T x);

};



template<typename T>
inline Tree<T>::Tree()
{
	root = nullptr;
}

template<typename T>
inline void Tree<T>::insert(T x)
{
	//If there doesn't exist a root, then set the tree's
	//root as the data passed in, otherwise
	//send the data to the right or left branch depending 
	//on the value of the data. 
	//**Each Element can be be broken down into a subtree, with the element being the root of that subtree

	if (root == nullptr)
	{
		Node<T>* node = new Node<T>;
		node->data = x;
		root = node;
	}
	else if (x <= root->data)
	{
		insert(&root->left, x);
	}
	else if (x > root->data)
	{
		insert(&root->right, x);
	}

}

template<typename T>
inline void Tree<T>::insert(Node<T>** root, T x)
{
	//If there doesn't exist a root, then set the tree's
	//root as the data passed in, otherwise
	//send the data to the right or left branch depending 
	//on the value of the data. 
	//**Each Element can be be broken down into a subtree, with the element being the root of that subtree
	if ( (*root) == nullptr)
	{
		Node<T>* node = new Node<T>;
		node->data = x;
		*root = node;
	}
	else if (x <= (*root)->data ) 
	{
		insert( &(*root)->left , x);
	}
	else if (x > (*root)->data )
	{
		insert( &(*root)->right , x);
	}
	
}
 
template<typename T>
inline void Tree<T>::remove(T x)
{
	
	if (!search(x))
	{
		std::cout << "[!] ERROR: Data not found.\n";
		return;
	}

	remove(root, x);

}

template<typename T>
inline Node<T>* Tree<T>::remove(Node<T>* root, T x)
{
	//If data is less, then traverse left in the tree
	if (root->data > x)
	{
		root->left = remove(root->left, x);
	}
	//If data is greater, then traverse right in the tree
	else if (root->data < x)
	{
		root->right = remove(root->right, x);
	}
	//If data is found, we are in the right node
	else if (root->data == x)
	{
		//Node has no children
		if ( (root->right == nullptr) && (root->left == nullptr) )
		{
			delete root;
			root = nullptr;
		}
		//Node has one child on the left
		else if (root->right == nullptr)
		{
			Node<T>* temp = root->left;
			delete root;
			return temp;
		}
		//node has one child on the right
		else if (root->left == nullptr)
		{
			Node<T>* temp = root->right;
			delete root;
			return temp;
		}
		//Node has two children
		else
		{
			//Set the node being deleted to the smallest member of right subtree
			Node<T>* min = findMin(root->right);
			root->data = min->data;

			//Delete the smallest member of the right tree now
			root->right = remove(root->right, min->data);
		}

	}
	return root;
	 
}

template<typename T>
inline T Tree<T>::findNext(T x)
{
	Node<T>* temp = find(root, x); //>Node to find next successor
	return findNext(temp, x);
}


template<typename T>
inline T Tree<T>::findNext(Node<T>* root, T x)
{
	//Case 1: root has a right tree, simply find smallest value in that tree and return
	if (root->right != nullptr)
	{
		Node<T>* temp = findMin(root->right);
		return temp->data;
	}
	//Case 2: Root doesn't have a right subtree, find the nearest possible ancestor, where this node could be place left of
	else if (root->right == nullptr)
	{
		Node<T>* next = nullptr; //>Nearest ancestor
		Node<T>* ancestor = this->root; //>current ancestor being explored
		
		//Traverse tree until the node whose successor is being looked for is hit.
		while (ancestor != root)
		{
			//If ancestor is greater than root, that means root can be placed left of the ancestor. This is the nearest ancestor so far
			if (root->data < ancestor->data) 
			{
				next = ancestor;
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right; //> Can not greater value than root so we move on
			}
		}

		return next->data;
	}
}

template<typename T>
inline Node<T>* Tree<T>::find(Node<T>* root, T x)
{

	if (root == nullptr)
		return nullptr;

	if (root->data > x)
	{
		find(root->left,x);
	}
	else if (root->data < x)
	{
		find(root->right, x);
	}
	else
	{
		return root;
	}
}

template<typename T>
inline Node<T>* Tree<T>::findMin(Node<T>* root)
{
	while (root->left != nullptr)
	{
		root = root->left;
	}

	return root;

}





template<typename T>
inline bool Tree<T>::search(T x)
{
	//Lesser data is found in branches to the left
	//Greater data is found in branches to the right

	if (root == nullptr)
	{
		return false;
	}
	else if (x == root->data)
	{
		return true;
	}
	else if(x <= root->data)
	{
		search(root->left, x);
	}
	else if (x > root->data)
	{
		search(root->right, x);
	}

}

template<typename T>
inline bool Tree<T>::search(Node<T>* root, T x)
{
	if (root == nullptr)
	{
		return false;
	}
	else if (x == root->data)
	{
		return true;
	}
	else if (x <= root->data)
	{
		search(root->left, x);
	}
	else if (x > root->data)
	{
		search(root->right, x);
	}

}


template<typename T>
inline T Tree<T>::max()
{
	Node<T>* current = root;

	//Greater data is found in branches to the right
	while (current->right != nullptr)
	{
		current = current->right;
	}
	
	return current->data;
}

template<typename T>
inline T Tree<T>::min()
{
	Node<T>* current = root;

	//Lesser data is found in branches to the left
	while (current->left != nullptr) 
	{
		current = current->left;
	}

	return current->data;
}




template<typename T>
inline int Tree<T>::getHeight()
{
	return getHeight(root);
}

template<typename T>
inline int Tree<T>::getHeight(Node<T>* root)
{
	if (root == nullptr)
	{
		return -1;
	}

	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;

}


template<typename T>
inline bool Tree<T>::isEmpty()
{
	if (root == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void Tree<T>::printB()
{

	if (root == nullptr)
	{
		std::cout << "Tree is empty\n";
		return;
	};

	//Queue used to print nodes in correct order
	std::queue<Node<T>*> traverse;
	
	traverse.push(root);

	std::cout << "Queue print: ";

	//Cycle through elements of queue
	while (!traverse.empty())
	{
		Node<T>* current = traverse.front();

		if (current->left != nullptr)
			traverse.push(current->left);

		if (current->right != nullptr)
			traverse.push(current->right);

		std::cout << current->data <<  " ";

		traverse.pop();
		 
	}
	std::cout << "\n";
}

template<typename T>
inline void Tree<T>::printPreorder()
{
	if (root == nullptr)
	{
		std::cout << "Empty Tree";
		return;
	}
	std::cout << "Depth-First Preorder: ";
	printPreorder(root);
	std::cout << "\n";
}



template<typename T>
inline void Tree<T>::printPreorder(Node<T>* root)
{

	//Preorder: <data><left><right>
	std::cout << root->data << " ";
	
	if (root->left != nullptr)
		printPreorder(root->left);

	if (root->right != nullptr)
		printPreorder(root->right);

}


template<typename T>
inline void Tree<T>::printInorder()
{
	//Inorder: <left><data><right>
	if (root == nullptr)
	{
		std::cout << "Empty Tree";
		return;
	}
	std::cout << "Depth-First Inorder: ";
	printInorder(root);
	std::cout << "\n";
}


template<typename T>
inline void Tree<T>::printInorder(Node<T>* root)
{
	
	//Postorder: <left><right><data>
	if (root->left != nullptr)
		printInorder(root->left);

	std::cout << root->data << " ";

	if (root->right != nullptr)
		printInorder(root->right);

}

template<typename T>
inline void Tree<T>::printPostorder()
{
	if (root == nullptr)
	{
		std::cout << "Empty Tree";
		return;
	}
	std::cout << "Depth-First Postorder: ";
	printPostorder(root);
	std::cout << "\n";
}



template<typename T>
inline void Tree<T>::printPostorder(Node<T>* root)
{
	if (root->left != nullptr)
		printPostorder(root->left);


	if (root->right != nullptr)
		printPostorder(root->right);

	std::cout << root->data << " ";
}


