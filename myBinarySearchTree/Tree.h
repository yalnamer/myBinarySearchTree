#pragma once

#include <iostream>
#include "Node.h"



template <typename T>
class Tree {

	Node<T>* root;

	void insert(Node<T>** root, T x);
	bool search(Node<T>* root, T x);

public:

	Tree();

	void insert(T x);


	void remove(T x);


	bool search(T x);

};



template<typename T>
inline Tree<T>::Tree()
{
	root = nullptr;
}

template<typename T>
inline void Tree<T>::insert(T x)
{

	if (root == nullptr)
	{
		Node<T>* node = new Node<T>;
		node->data = x;
		root = node;
		//std::cout << root->data << std::endl << std::endl;
	}
	else if (x <= root->data)
	{
		insert(&root->left, x);
		std::cout << "Left\n";
	}
	else if (x > root->data)
	{
		insert(&root->right, x);
		std::cout << "Right\n";
	}

}

template<typename T>
inline void Tree<T>::insert(Node<T>** root, T x)
{
	if ( (*root) == nullptr)
	{
		Node<T>* node = new Node<T>;
		node->data = x;
		*root = node;
	}
	else if (x <= (*root)->data ) 
	{
		insert((&(*root)->left), x);
	}
	else if (x > (*root)->data)
	{
		insert((&(*root)->left), x);
	}
	
}

template<typename T>
inline void Tree<T>::remove(T x)
{
}

template<typename T>
inline bool Tree<T>::search(T x)
{
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