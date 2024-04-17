#include <iostream>


#include"C:/Users/Work/Downloads/TreeNode.h"
#include"C:/Users/Work/Downloads/someTestTrees.h"

using namespace std;


using namespace MySpace::DataStructs::Trees; 

int main()
{
    //TreeNode<int> tree(1); 
    //tree.left = new TreeNode<int>(2); //be careful of "naked new" (a new that doesn't have a delete) 
    //tree.right = new TreeNode<int>(3); 

    //cout << tree.nodeValue << endl; 
    //cout << tree.left->nodeValue << endl; 
    //cout << tree.left->left << endl; 


    auto exampleTree1 = generateExampleTree1(); 

    //cout << exampleTree1->left->left->right->nodeValue << endl; 

    cout << std::boolalpha; 
    auto nodeOfInterest = exampleTree1->left->left->left; 

    cout << "Is the node containing the character " << nodeOfInterest->nodeValue << endl; 

    cout << "... a leaf node? " << nodeOfInterest->isLeaf() << endl; 
    cout << "A breadth-first search (traversal) of that tree yields: " << endl; 
    levelOrderTraverse(exampleTree1);


    //TreeNode<int> tree(1);
    //tree.left = new TreeNode<int>(2); 
    //tree.right = new TreeNode<int>(3); 

    //cout << tree.left->left->left << endl; 

    //auto tree = generateExampleTree1();
    //tree->inorderTraverse(tree);
    //inorderTraverse(tree); 

    return 0;
}