#include <iostream>
using namespace std;

//AVL

struct Node {
    int data, h;
    Node *l, *r;
    Node(int v) { data=v; l=r=NULL; h=1; }
};

int height(Node* n){ 
    return n ? n->h : 0;
 }

Node* rightRotate(Node* y){
    Node* x=y->l; 
    Node* t=x->r;
    x->r=y; 
    y->l=t;
    y->h=1+max(height(y->l), height(y->r));
    x->h=1+max(height(x->l), height(x->r));
    return x;
}

Node* leftRotate(Node* x){
    Node* y=x->r; 
    Node* t=y->l;
    y->l=x; 
    x->r=t;
    x->h=1+max(height(x->l), height(x->r));
    y->h=1+max(height(y->l), height(y->r));
    return y;
}

Node* insert(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->data) root->l=insert(root->l,val);
    else if(val > root->data) root->r=insert(root->r,val);
    else return root;

    root->h = 1 + max(height(root->l), height(root->r));
    int b = height(root->l) - height(root->r);

    if(b>1 && val<root->l->data) return rightRotate(root);       // LL
    if(b<-1 && val>root->r->data) return leftRotate(root);       // RR
    if(b>1 && val>root->l->data){ root->l=leftRotate(root->l); return rightRotate(root); } // LR
    if(b<-1 && val<root->r->data){ root->r=rightRotate(root->r); return leftRotate(root); } // RL

    return root;
}

void pre(Node* r){ if(r){ cout<<r->data<<" "; pre(r->l); pre(r->r); } }

int main(){
    Node* root=NULL;
    int a[]={10,20,30,40,50,25};
    for(int x:a) root=insert(root,x);
    cout<<"Preorder AVL: "; pre(root);
}
