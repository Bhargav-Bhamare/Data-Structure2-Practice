// Detailed Max Heap Implementation in C++



#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int a[], int n, int i) {
    int largest = i;        // Assume root is largest
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // Check if left child exists and is greater than root
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than largest so far
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);

        // Recursively heapify the affected subtree
        heapify(a, n, largest);
    }
}

// Function to build a Max Heap from array
void buildMaxHeap(int a[], int n) {
    // Start from last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

// Function to print the heap
void printHeap(int a[], int n) {
    cout << "Heap elements: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Insert a new element into the heap
void insert(int a[], int &n, int value) {
    n++;  // Increase heap size
    a[n - 1] = value;

    int i = n - 1;

    // Fix the max heap property if violated
    while (i != 0 && a[(i - 1) / 2] < a[i]) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete root (maximum element) from heap
void deleteRoot(int a[], int &n) {
    if (n <= 0) {
        cout << "Heap is empty!\n";
        return;
    }

    // Replace root with last element
    a[0] = a[n - 1];
    n--;

    // Heapify root
    heapify(a, n, 0);
}

// Heap Sort using Max Heap
void heapSort(int a[], int n) {
    // Step 1: Build Max Heap
    buildMaxHeap(a, n);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);       // Move current root to end
        heapify(a, i, 0);       // Heapify reduced heap
    }
}

int main() {
    int a[20] = {3, 9, 2, 1, 4, 5};
    int n = 6;

    cout << "Original Array:\n";
    printHeap(a, n);

    // Build Max Heap
    buildMaxHeap(a, n);
    cout << "\nAfter Building Max Heap:\n";
    printHeap(a, n);

    // Insert a new element
    cout << "\nInserting 10 into heap...\n";
    insert(a, n, 10);
    printHeap(a, n);

    // Delete root
    cout << "\nDeleting root (max element)...\n";
    deleteRoot(a, n);
    printHeap(a, n);

    // Heap Sort
    cout << "\nHeap Sort:\n";
    heapSort(a, n);
    printHeap(a, n);

    return 0;
}