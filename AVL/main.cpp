#include "AVLTree.h"
#include <iostream>


int main()
{
    AVLTree<int> T1;
    int ch;
    int x;
    while (1)
    {
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            std::cin >> x;
            T1.insert(x);
            std::cout << T1;
            break;
        case 2:
            std::cin >> x;
            std::cout << T1.search(x);
            break;
        case 3:
            std::cin >> x;
            T1.remove(x);
            std::cout << T1;
            break;

        }
        std::cout << std::endl;
        if (ch == 4)
            break;
    }
    std::cout << "Success! ";
    return 0;
}