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

int maxHeight(Node *root){
    Node *temp = root;
    if(temp==NULL){
        return 0;
    }
    int lh = maxHeight(temp->left);
    int rh = maxHeight(temp->right);

    return 1 + max(lh,rh);
}
int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);

    cout<<maxHeight(root)<<endl;

    return 0;
}