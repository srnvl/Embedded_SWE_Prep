#include <iostream>
using namespace std;

// Defining a node for Binary Search Tree

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

// Function to create a new node in the heap

BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in the BST

BstNode* Insert (BstNode* root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if(data < root->data)
    {
        root->left = Insert(root->left, data); 
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

// Search for an element in BstNode

bool Search(BstNode* root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    
    else if (root->data == data)
    {
        return true;
    }
    
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else{
        return Search(root->right, data);
    }
}

int main()
{
    BstNode* root = NULL; // Creating an empty BST
    
    root = Insert(root, 15);
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	
	int number;
	cout << "Enter a number to be searched: ";
	cin >> number;
	
	if(Search(root, number) == true)
	    cout << "Found!\n" << endl;
	else 
	    cout << "Not found!\n" << endl;
    
}
