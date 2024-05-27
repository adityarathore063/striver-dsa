#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

bool isIdentical(Node *root1 , Node *root2){
    if(root1==NULL || root2==NULL)
        return(root1==root2);

    return(root1->data==root2->data) and isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right);
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->left->left = new Node(5);
    root1->right->right = new Node(6);

    cout<<isIdentical(root,root1)<<"\n";

    return 0;
}