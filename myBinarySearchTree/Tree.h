#pragma once

#include <iostream>
#include <queue>

#include "Node.h"



template <typename T>
class Tree {

	Node<T>* root;

	
	void insert(Node<T>** root, T x); //>Insert function used recursively
	bool search(Node<T>* root, T x); //> Search a tree recursively
	int getHeight(Node<T>* root);
	void printPreorder(Node<T>* root);
	void printInorder(Node<T>* root);
	void printPostorder(Node<T>* root);

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
	std::cout << root->data << " ";
	
	if (root->left != nullptr)
		printPreorder(root->left);

	if (root->right != nullptr)
		printPreorder(root->right);

}


template<typename T>
inline void Tree<T>::printInorder()
{
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
