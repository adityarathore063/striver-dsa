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

// Naive solution

bool check(Node *root){
    if(root==NULL){
        return true;
    }

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    if(abs(lh-rh)>1) return false;

    bool left = check(root->left);
    bool right = check(root->right);

    if(!left or !right) return false;

    return true;

}
// optimized solution
int checkBalanced(Node *root){
    Node *temp = root;
    if(temp==NULL){
        return 0;
    }
    int lh = maxHeight(temp->left);
    if(lh==-1 ) return -1;
    int rh = maxHeight(temp->right);
    if(rh==-1 ) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1 + max(lh,rh);
}
int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);


    if(checkBalanced(root)==-1){
        cout<<"Tree is not balanced\n";
    }
    else{
        cout<<"Tree is balanced\n";
    }

    return 0;
}