#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left=right=NULL;
    }
};

vector<int> inorder(Node *root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<Node*>st;
    Node *temp = root;
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()) break;
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
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

    vector<int>ans = inorder(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}