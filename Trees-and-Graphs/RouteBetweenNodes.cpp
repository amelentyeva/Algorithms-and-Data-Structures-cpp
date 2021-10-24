/* The problem: Given a directed graph, design an algorithm to find out whether there
is a route between two nodes */

// iterative implementation of breadth-first search
#include "SimpleGraph.h"
#include <iostream>
#include <queue>
#include <utility>

bool routeExists(Graph& g, Node* start, Node* end)
// without const qualifiers as we edit nodes visited status
{
    if (start == end)
    {
        return true;
    }
    std::queue<Node*> nodeQueue;
    for (auto node : g.nodes)
    {
        node->visited = false;
    }
    nodeQueue.push(start);
    Node temp("");
    while (!nodeQueue.empty())
    {
        temp = *nodeQueue.front();
        nodeQueue.pop();

        for (const auto adjacentNode : temp.neighbors)
        {
            if (adjacentNode->visited)
                continue;
            if (adjacentNode == end)
                return true;
            adjacentNode->visited = true;
            nodeQueue.push(adjacentNode);
        }
    }
    return false;
}

int main()
{

    Graph graph;
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");

    Node e("e");
    Node f("f");
    b.addNeighbor(&d);

    c.addNeighbor(&a);
    a.addNeighbor(&b);
    d.addNeighbor(&c);
    e.addNeighbor(&f);
    f.addNeighbor(&e);
    graph.addNodes({ &a, &b, &c, &d, &e, &f });

    std::cout << routeExists(graph, &a, &e) << std::endl;

    return 0;
}