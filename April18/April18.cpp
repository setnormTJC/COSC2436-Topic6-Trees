#include <iostream>
#include <queue>

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
    //this->nodeValue = nodeValue; 

    bool isLeaf()
    {
        return (left == nullptr && right == nullptr);

        //if (this)
    }




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


/*
* Makes
(a + b) / ( c - d) -> 
            /
          /   \
        +      -
       / \   /   \
      a   b  c    d
*/
TreeNode<char>* generateArithmeticExpressionTree()
{
    //lvl 0 node: 
    TreeNode<char>* root = new TreeNode<char>('/'); 

    //lvl 1: 
    root->left = new TreeNode<char>('+'); 
    root->right = new TreeNode<char>('-'); 

    //lvl 2: 
    root->left->left = new TreeNode<char>('a'); 
    root->left->right = new TreeNode<char>('b');
  
    root->right->left = new TreeNode<char>('c');
    root->right->right = new TreeNode<char>('d');

    return root; 
}

void inorderTraverse(TreeNode<char>* root)
{
    if (root != nullptr) //base case 
    {
        inorderTraverse(root->left); //recursion!
        
        cout << root->nodeValue << " "; //omitting endl
        
       inorderTraverse(root->right);

       //LNR -> "inorder" (BST) 


    }
}

/*
*               1
*             /  \ 
            2      3
           /  \   / 
          4    5 6  
*/
TreeNode<int>* generateLevelOrderTree()
{
    //level (depth) 0 node 
    TreeNode<int>* ptrToRootOfTree = new TreeNode<int>(1);

    //level 1 nodes: 
    ptrToRootOfTree->left = new TreeNode<int>(2);
    ptrToRootOfTree->right = new TreeNode<int>(3);
    
    //level 2 nodes: 
    ptrToRootOfTree->left->left = new TreeNode<int>(4); 
    ptrToRootOfTree->left->right = new TreeNode<int>(5); 

    ptrToRootOfTree->right->left = new TreeNode<int>(6); 


    return ptrToRootOfTree;

}


void levelOrderTraverse(TreeNode<int>* root)
{
    std::queue<TreeNode<int>*> treeNodeQueue;

    treeNodeQueue.push(root);

    while (!treeNodeQueue.empty())
    {
        TreeNode<int>* current;
        current = treeNodeQueue.front();
        cout << current->nodeValue << endl;
        treeNodeQueue.pop();


        if (current->left != nullptr)
        {
            treeNodeQueue.push(current->left);
        }
        if (current->right != nullptr)//switch left and right, if desired
        {
            treeNodeQueue.push(current->right);
        }
    }

    //2^ 32 = 4 GB


}

int main()
{


    auto root = generateArithmeticExpressionTree(); 

    cout << std::boolalpha; 
    cout << root->isLeaf() << endl; //false

    //auto root = generateLevelOrderTree(); 
    //levelOrderTraverse(root); 
    
    //for (int i = 0)
    
    //Node<T>* current = front; 

    inorderTraverse(root); 
    
    //levelOrderTraverse(root); 
    //cout << root->isLeaf() << endl; 
    cout << "HERE!" << root->left->left->isLeaf() << endl;
    //TreeNode<int>* current = root; 



    ///traverse (roughly) HALF of the tree algorithm: 
  /*  while (current != nullptr)
    {
        cout << current->nodeValue << " "; 
        current = current->left; 

    }*/

    //cout << "Root->nodeValue yields: " <<  root->nodeValue << endl;

    //cout << "Root->left->nodeValue yields: " << root->left->nodeValue << endl;

    //breadth-first search call: (BFT/DFT)
 
    //preorderTraverse(arithemeticTreeRoot); 

    //our first tree - hooray!
 
    //auto root = generateFirstExampleTree(); 
    //

    ////cout << "The nodeValue in the ROOT of that tree is: " << root->nodeValue << endl; 
    ////cout << "The LEFT child of the root contains the nodeValue = " << root->left->nodeValue << endl; 
    //
    //TreeNode<char>* currentNode; 
    //currentNode = root; 

    //while (currentNode != nullptr)
    //{
    //    //go right 
    //    cout << currentNode->nodeValue << endl; 
    //    currentNode = currentNode->right; 
    //}

    //cout << "Error? " << root->left->left->nodeValue << endl; 
    return 0;
}