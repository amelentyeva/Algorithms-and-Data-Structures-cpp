#pragma once
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

struct Node
{
    Node(const char* id_)
        : id(id_)
    {
    }

    std::string id;
    std::vector<Node*> neighbors;
    bool visited = false; // to check during traversal
    void addNeighbor(Node* n) { neighbors.push_back(n); }
};

struct Graph
{
    std::vector<Node*> nodes;

    void addNodes(std::initializer_list<Node*> additional)
    {
        for (auto n : additional)
        {

            nodes.push_back(n);
        }
    }
};
// Graph is represented as a list of adjacent vertices
