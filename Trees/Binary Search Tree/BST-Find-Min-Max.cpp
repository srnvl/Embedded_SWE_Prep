// Find the min and max element in a BST

#include <iostream>
using namespace std;

// Function to define a node in a BST
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// Function to find minimum in a BST
int FindMin (BstNode* root)
{
    if(root == NULL)
    {
        cout << "BST is empty!";
        return -1;
    }
    BstNode* curr = root;
    while(curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->data;
}

// Function to find maximum in a BST
int FindMax (BstNode* root)
{
    if(root == NULL)
    {
        cout << "BST is empty!";
        return -1;
    }
    BstNode* curr = root;
    while(curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr->data;
}

// Function to create a new node
BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
BstNode* Insert(BstNode* root , int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

// Search for an element in BST

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
// 	cout << "Enter a number to be searched: ";
// 	cin >> number;
	
// 	if(Search(root, number) == true)
// 	    cout << "Found!\n" << endl;
// 	else 
// 	    cout << "Not found!\n" << endl;
	    
    int min = FindMin(root);
    cout << "Minimum number is: " <<  min << endl;
    int max = FindMax(root);
    cout << "Maximum number is: " <<  max << endl;
    return 0;
}
