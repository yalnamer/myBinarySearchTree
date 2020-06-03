#include <iostream>
#include "Tree.h"


int main()
{
	Tree<int> bst;

	bst.insert(25);
	bst.insert(17);


	std::cout << "True - "<< true <<  std::endl;
	std::cout << "False - " << false << std::endl;

	std::cout << bst.search(16) << std::endl;
	std::cout << bst.search(25) << std::endl;
	std::cout << bst.search(2) << std::endl;
}