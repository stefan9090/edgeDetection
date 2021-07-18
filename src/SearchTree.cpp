//
// Created by beerd on 7/18/2021.
//

#include "SearchTree.h"

Node::Node(char value):
    m_value(value)
{
}

DictSearchTree::DictSearchTree():
    m_root(std::make_shared<Node>(' '))
{
}

void DictSearchTree::addWord(std::string_view strWord)
{
    std::shared_ptr<Node> current = m_root;
    for (char letter : strWord)
    {
        bool m_found = false;
        for (auto &child : current->m_children)
        {
            if (child->m_value == letter)
            {
                m_found = true;
                current = child;
                break;
            }
        }

        if (!m_found)
        {
            auto newNode = std::make_shared<Node>(letter);
            current->m_children.emplace_back(newNode);
            current = std::move(newNode);
        }
    }
}
bool DictSearchTree::containsWord(std::string_view strWord)
{
    auto current = m_root;

    bool isFound = true;

    for (char letter : strWord)
    {
        bool isLetterFound = false;
        for (auto &child : current->m_children)
        {
            if (child->m_value == letter)
            {
                isLetterFound = true;
                current = child;
                break;
            }
        }

        if (!isLetterFound)
        {
            isFound = false;
            break;
        }
    }
    return isFound;
}
