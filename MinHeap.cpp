#include <iostream>
using namespace std;

// ===================== DISPLAY FUNCTION =====================
void printHeap(int a[], int n) {
    cout << "Heap elements: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// ===================== HEAPIFY (MIN HEAP) =====================
void heapify(int a[], int n, int i) {
    int smallest = i;        // Assume root is smallest
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // Check left child
    if (left < n && a[left] < a[smallest]) {
        smallest = left;
    }

    // Check right child
    if (right < n && a[right] < a[smallest]) {
        smallest = right;
    }

    // If root is not smallest
    if (smallest != i) {
        swap(a[i], a[smallest]);

        // Recursively heapify affected subtree
        heapify(a, n, smallest);
    }
}

// ===================== BUILD MIN HEAP =====================
void buildMinHeap(int a[], int n) {
    // Start from last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

// ===================== INSERT =====================
void insert(int a[], int &n, int value) {
    n++;                 // Increase heap size
    a[n - 1] = value;    // Insert at end

    int i = n - 1;

    // Fix heap property (bubble up)
    while (i != 0 && a[(i - 1) / 2] > a[i]) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// ===================== DELETE ROOT =====================
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

// ===================== GET MIN =====================
int getMin(int a[], int n) {
    if (n <= 0) {
        cout << "Heap is empty!\n";
        return -1;
    }
    return a[0];
}

// ===================== HEAP SORT USING MIN HEAP =====================
void heapSort(int a[], int n) {
    // Step 1: Build Min Heap
    buildMinHeap(a, n);

    int size = n;

    cout << "Sorted order (ascending): ";

    // Step 2: Extract min repeatedly
    while (size > 0) {
        cout << a[0] << " ";    // Print min element

        // Move last element to root
        a[0] = a[size - 1];
        size--;

        // Heapify root
        heapify(a, size, 0);
    }
    cout << endl;
}

// ===================== MAIN MENU =====================
int main() {
    int a[100] = {10, 20, 15, 30, 40};
    int n = 5;
    int choice, value;

    do {
        cout << "\n==== MIN HEAP MENU ====\n";
        cout << "1. Build Min Heap\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Root (Min)\n";
        cout << "4. Get Min Element\n";
        cout << "5. Heap Sort\n";
        cout << "6. Display Heap\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buildMinHeap(a, n);
                cout << "Min Heap built successfully!\n";
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(a, n, value);
                break;

            case 3:
                deleteRoot(a, n);
                cout << "Root deleted.\n";
                break;

            case 4:
                cout << "Minimum element: " << getMin(a, n) << endl;
                break;

            case 5:
                heapSort(a, n);
                break;

            case 6:
                printHeap(a, n);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}