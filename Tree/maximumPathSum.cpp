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

int maxPathDown(Node *root, int &maxi){
    if(root==NULL){
        return 0;
    }
    int left = max(0,maxPathDown(root->left,maxi));
    int right = max(0,maxPathDown(root->right,maxi));

    maxi = max(maxi,left+right+root->data);

    return max(left,right) + root->data;

}

int maxPathSum(Node *root){
    int maxi = INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);

    cout<<maxPathSum(root)<<"\n";

    return 0;
}