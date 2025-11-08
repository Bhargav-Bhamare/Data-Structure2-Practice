#include <iostream>
#include <queue>
#include <string> 
// Need this for std::string
using namespace std;

struct Node {
    char c;
    int f;
    Node *l, *r;
    
    // 1. Simplified the constructor using an "initializer list".
    // It does the same thing as your 'this->c = c', just shorter.

    Node(char c_in, int f_in) : c(c_in), f(f_in), l(nullptr), r(nullptr) {}
};

// Your comparator is perfect, no change needed.

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

void print(Node* r, string s = "") {
    if (!r) return;
    
    // Check for a leaf node (no children)
    if (!r->l && !r->r) {
        cout << r->c << ":" << s << endl;
    }
    
    print(r->l, s + "0");
    print(r->r, s + "1");
}

int main() {
    char c[] = {'A', 'B', 'C', 'D'};
    int f[] = {5, 9, 12, 13};
    
    priority_queue<Node*, vector<Node*>, cmp> q;
    
    for (int i = 0; i < 4; i++) {
        q.push(new Node(c[i], f[i]));
    }
    
    while (q.size() > 1) {
        Node* l = q.top(); 
        q.pop();
        Node* r = q.top(); 
        q.pop();
        
        // a. Create the new parent node

        Node* parent = new Node('#', l->f + r->f);
        
        // b. Assign its children

        parent->l = l;
        parent->r = r;
        
        // c. Push the new parent back onto the queue

        q.push(parent);
    }
    
    print(q.top());

    return 0; // Good practice to add a return
}