#include<bits/stdc++.h>
using namespace std;
int maxi = 0;
struct Node
{
    Node *left, *right;
    int data;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int maxHeight(Node *root){
    Node *temp = root;
    if(temp==NULL){
        return 0;
    }
    int lh = maxHeight(temp->left);
    int rh = maxHeight(temp->right);

    return 1 + max(lh,rh);
}

// Naive solution
void longest(Node *root){
    if(root==NULL){
        return;
    }

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    maxi = max(maxi,lh+rh);
    longest(root->left);
    longest(root->right);
    

}

// optimized solution
int height(Node *root, int &diameter){
    Node *temp = root;
    if(temp==NULL){
        return 0;
    }
    int lh = height(temp->left, diameter);
    int rh = height(temp->right, diameter);

    diameter = max(diameter,lh+rh);

    return 1 + max(lh,rh);
}

int diameterTree(Node *root){
    int diameter = 0;
    height(root,diameter);
    return diameter;
}



int main(){

    // Diameter of the tree -> longest path between the any two nodes and this path does not need to pass through the root

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);

    cout<<diameterTree(root)<<"\n";

    return 0;
}