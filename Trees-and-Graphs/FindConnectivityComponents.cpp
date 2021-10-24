#include "SimpleGraph.h"
#include <iostream>
#include <utility>

void DFS(Node* n);

int countConnectedComponents(Graph& g)
{
    int count = 0;
    for (Node* node : g.nodes)
    {
        node->visited = false;
    }

    for (Node* node : g.nodes)
    {

        if (!node->visited)
        {

            DFS(node);

            count++;
        }
    }
    return count;
}

void DFS(Node* node)
{
    node->visited = true;
    std::cout << node->id << " ";
    for (auto& adj : node->neighbors)
    {

        if (!adj->visited)
        {
            DFS(adj);
            std::cout << adj->id << " ";
        }
    }
    std::cout << "\n";
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
    std::cout << countConnectedComponents(graph);
}