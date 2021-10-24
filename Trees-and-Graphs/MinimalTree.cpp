/* Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search
 * tree wth minimal height */

/* To create a tree of minimal height, we need to match the number of nodes in the left subtree
to the number of nodes in the right subtree as much as possible.

The algorithm is as follows:

1. Insert into the tree the middle element of the array
2. Insert (into the left subtree) the left subarray elements
3. Insert (into the right subtree) the right subarray elements
4. Recurse */

#include <cstddef>
#include <iostream>
#include <vector>

struct BinaryTreeNode

{
    BinaryTreeNode() = delete;
    BinaryTreeNode(int value_, BinaryTreeNode* parent_)
        : value(value_)
        , parent(parent_)
    {
    }
    int value;
    BinaryTreeNode* parent = nullptr;
    BinaryTreeNode* leftChild = nullptr;
    BinaryTreeNode* rightChild = nullptr;
};

BinaryTreeNode* createMinimalBST(const std::vector<int>& values, size_t start, size_t end, BinaryTreeNode* parent)
{

    if (end < start)
    {
        return nullptr; // null
    }
    if (start == end)
    {
        return new BinaryTreeNode(values[start], parent);
    }

    size_t mid = (end + start) / 2;

    BinaryTreeNode* n = new BinaryTreeNode(values[mid], parent);

    std::cout << values[start] << " " << values[mid - 1] << std::endl;
    n->leftChild = createMinimalBST(values, start, mid - 1, n);
    std::cout << values[mid + 1] << " " << values[end] << std::endl;
    n->rightChild = createMinimalBST(values, mid + 1, end, n);

    return n;
}

void printNode(BinaryTreeNode* node)
{
    std::cout << "\t" << node->value << "\t" << std::endl;
    std::cout << node->leftChild->value << "\t" << node->rightChild->value << std::endl;
}
int main()
{

    std::vector<int> samples{ 0, 2, 5, 7, 8, 11, 13, 16, 17, 18, 22, 23, 24 };

    BinaryTreeNode* node = createMinimalBST(samples, 0, samples.size(), nullptr);
    /*
        while (node->leftChild || node->rightChild)
        {
            printNode(node);
            node = node->leftChild;
            printNode(node);
        }*/

    return 0;
}
