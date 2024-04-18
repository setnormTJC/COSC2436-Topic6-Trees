#include <iostream>

//#include"C:/Users/Work/Downloads/TreeNode-1.h"


template<typename T>
class TreeNode
{
public:
    //member vars:
    T nodeValue;
    TreeNode<T>* left, * right;

    //general tree could be made by using a VECTOR of childrenLinks: 
    //vector<TreeNode<T>*> childrenLinks; 


    TreeNode()
    {
        nodeValue = 0; 
        left = nullptr; 
        right = nullptr; 
    }

    TreeNode(T nodeValue)
        :nodeValue(nodeValue) {}; 


}; //end TreeNode class def. 

using namespace std;


/*
* This function generates the following tree:
*           A
*          /  \
*         B    C
*       /       \
*      D         E
*/
TreeNode<char>* generateFirstExampleTree()
{
    //new int; 
    TreeNode<char>* addressOfRoot = new TreeNode<char>('A');
    //new does 2 things: 
    //1: makes space in RAM 
    //2: returns a memory address

    addressOfRoot->left = new TreeNode<char>('B');
    addressOfRoot->right = new TreeNode<char>('C');


    addressOfRoot->left->left = new TreeNode<char>('D');
    addressOfRoot->right->right = new TreeNode<char>('E');

    return addressOfRoot; 
}

int main()
{
    //our first tree - hooray!
 
    auto root = generateFirstExampleTree(); 
    

    //cout << "The nodeValue in the ROOT of that tree is: " << root->nodeValue << endl; 
    //cout << "The LEFT child of the root contains the nodeValue = " << root->left->nodeValue << endl; 
    
    TreeNode<char>* currentNode; 
    currentNode = root; 

    while (currentNode != nullptr)
    {
        //go right 
        cout << currentNode->nodeValue << endl; 
        currentNode = currentNode->right; 
    }

    //cout << "Error? " << root->left->left->nodeValue << endl; 
    return 0;
}