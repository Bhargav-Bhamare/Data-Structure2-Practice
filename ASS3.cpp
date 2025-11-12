#include<iostream>
using namespace std;


//Binary search Tree

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int v){
      data=v,left=right=NULL;
    }
};

//Insertion

Node* insert(Node* r,int x){
    if(!r){
        return new Node(x);
    }
    if(x < r->data){
        r ->left= insert(r->left,x);
    }else{
        r ->right= insert(r->right,x);
    }
    return r;
};

//Searching
bool search(Node* r, int key) {
    while (r) {
        if (r->data == key) return true;
        else if (key < r->data) r = r->left;
        else r = r->right;
    }
    return false;
}

//Traversal methods

//Inorder
void inorder(Node* r){
    if(r){
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
};

//Preorder
void preorder(Node* r){
    if(r){
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
};

//Postorder
void postorder(Node* r){
    if(r){
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" "; 
    }
};

int main(){
    Node* root= NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,60);
    insert(root,70);
    cout<<"Traversals of The Created Binary Search Tree:"<<endl;
    cout<<"\n Preoder:"<<endl;
    preorder(root);
    cout<<"\n Inorder:"<<endl;
    inorder(root);
    cout<<"\n Postorder:"<<endl;
    postorder(root);
};