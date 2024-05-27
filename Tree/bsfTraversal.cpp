#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> levelorder(Node *root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i = 0; i<size; i++){
            Node *temp = q.front();
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<vector<int>> a = levelorder(root);
    for(int i = 0; i<a.size(); i++){
        for(int j = 0; j<a[i].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}