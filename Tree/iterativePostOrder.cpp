#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left=right = NULL;
    }
};

vector<int> postOrderTwoStack(Node *root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<Node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node *temp = st1.top();
        st1.pop(); 
        st2.push(temp);

        if(temp->left!=NULL){
            st1.push(temp->left);
        }
        if(temp->right!=NULL){
            st1.push(temp->right);
        }
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

int main(){

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> ans = postOrderTwoStack(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    
    return 0;
}