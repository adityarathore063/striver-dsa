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

vector<int> preOrder(Node *root){
    vector<int>ans;
    if(root==NULL) return ans;

    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node *temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right!=NULL){
            st.push(temp->right);
        }
        if(temp->left!=NULL){
            st.push(temp->left);
        }
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

    vector<int> ans = preOrder(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    
    return 0;
}