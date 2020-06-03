#include <iostream>
#include "Tree.h"


int main()
{
	Tree<int> bst;

	bool over = false;

	while (!over)
	{

		std::cout << "\n ******************\n"
					<< "-:>> Tree Menu \n"
					<< "   [1]. Insert \n"
					<< "   [2]. Search \n"
					<< "   [0]. Quit \n\n";

		int choice;

		std::cout << "[!]Enter your choice: ";
		std::cin >> choice;

		if (choice == 1)
		{
			std::cout << "Enter a number to insert to tree: ";

			int num;
			std::cin >> num;

			bst.insert(num);
		}

		if (choice == 2)
		{
			std::cout << "Enter a number to search for in tree: ";

			int num;
			std::cin >> num;

			if (bst.search(num))
				std::cout << "[!] Number found!\n";
			else
				std::cout << "[!] Not Found\n";


		}

		if (choice == 0)
		{
			over = true;
		}

		std::cout << "  >| Info: \n";

		if (bst.isEmpty())
		{
			std::cout << "  >>>|: Height: 0 \n"
					  << "  >>>>>|: Max: Empty Tree \n"
					  << "  >>>>>>>|: Min: Empty Tree \n\n";
		}
		else
		{
			std::cout << "  >>>|: Height: " << bst.getHeight() <<"\n"
					  << "  >>>>>|: Max: " << bst.max() << "\n"
					  << "  >>>>>>>|: Min: " << bst.min() << "\n\n";

		}

			

	}


}