#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Node structure
struct Node {
    char character;
    int frequency;
    Node *leftChild;
    Node *rightChild;

    // Constructor
    Node(char c, int f) {
        character = c;
        frequency = f;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

// Comparator for priority queue (min heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->frequency > b->frequency) {
            return true;
        } else {
            return false;
        }
    }
};

// Function to create a new node
Node* createNode(char c, int f) {
    Node* temp = new Node(c, f);
    return temp;
}

// Function to insert all nodes into priority queue
void insertIntoQueue(priority_queue<Node*, vector<Node*>, Compare> &pq, char chars[], int freq[], int size) {
    for (int i = 0; i < size; i++) {
        Node* newNode = createNode(chars[i], freq[i]);
        pq.push(newNode);
    }
}

// Function to build Huffman Tree
Node* buildHuffmanTree(priority_queue<Node*, vector<Node*>, Compare> &pq) {

    while (pq.size() > 1) {

        // Step 1: Get two minimum nodes
        Node* leftNode = pq.top();
        pq.pop();

        Node* rightNode = pq.top();
        pq.pop();

        // Step 2: Create parent node
        int combinedFrequency = leftNode->frequency + rightNode->frequency;
        Node* parentNode = createNode('#', combinedFrequency);

        // Step 3: Assign children
        parentNode->leftChild = leftNode;
        parentNode->rightChild = rightNode;

        // Step 4: Push back to queue
        pq.push(parentNode);
    }

    // Final root node
    return pq.top();
}

// Function to print Huffman Codes
void printCodes(Node* root, string code) {

    if (root == nullptr) {
        return;
    }

    // Check if leaf node
    if (root->leftChild == nullptr && root->rightChild == nullptr) {
        cout << root->character << " : " << code << endl;
    }

    // Traverse left
    printCodes(root->leftChild, code + "0");

    // Traverse right
    printCodes(root->rightChild, code + "1");
}

int main() {

    // Input data
    char characters[] = {'A', 'B', 'C', 'D'};
    int frequencies[] = {5, 9, 12, 13};

    int size = 4;

    // Priority Queue (Min Heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Insert nodes
    insertIntoQueue(pq, characters, frequencies, size);

    // Step 2: Build Huffman Tree
    Node* root = buildHuffmanTree(pq);

    // Step 3: Print Codes
    cout << "Huffman Codes:\n";
    printCodes(root, "");

    return 0;
}