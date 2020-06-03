#pragma once

template <typename T>
struct Node {

	T data;

	Node<T>* left = nullptr;
	Node<T>* right = nullptr;

};
