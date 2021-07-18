#include <iostream>

#include "SearchTree.h"

int main()
{
    DictSearchTree dict;

    if (dict.containsWord("test"))
    {
        std::cout << "Found word\n";
    }
    else
    {
        std::cout << "Did not find word\n";
    }

    dict.addWord("test");

    if (dict.containsWord("test"))
    {
        std::cout << "Found word\n";
    }
    else
    {
        std::cout << "Did not find word\n";
    }

    std::cout << "Hello world\n";
}
