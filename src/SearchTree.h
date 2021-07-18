//
// Created by beerd on 7/18/2021.
//

#ifndef EDGEDETECTION_SEARCHTREE_H
#define EDGEDETECTION_SEARCHTREE_H

#include <memory>
#include <vector>

struct Node
{
    Node(char value);
    std::vector<std::shared_ptr<Node>> m_children;
    char m_value;
};

class DictSearchTree
{
private:
    std::shared_ptr<Node> m_root;
public:
    DictSearchTree();
    void addWord(std::string_view strWord);
    bool containsWord(std::string_view strWord);
};


#endif//EDGEDETECTION_SEARCHTREE_H
