#include <iostream>
using namespace std;




// ===================== COMMON FUNCTION =====================
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

// ===================== SELECTION SORT =====================
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

// ===================== INSERTION SORT =====================
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// ===================== QUICK SORT =====================
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// ===================== MERGE SORT =====================
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[100];

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int x = 0; x < k; x++)
        a[l + x] = temp[x];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// ===================== RADIX SORT =====================
int getMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void countSort(int a[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (a[i] / exp) % 10;
        output[--count[index]] = a[i];
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n) {
    int maxVal = getMax(a, n);

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

// ===================== MAIN MENU =====================
int main() {
    int a[100] = {5, 3, 8, 1, 2};
    int n = 5;
    int choice;

    cout << "Original Array:\n";
    printArray(a, n);

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Radix Sort\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(a, n);
            cout << "\nSelection Sort Result:\n";
            break;

        case 2:
            insertionSort(a, n);
            cout << "\nInsertion Sort Result:\n";
            break;

        case 3:
            quickSort(a, 0, n - 1);
            cout << "\nQuick Sort Result:\n";
            break;

        case 4:
            mergeSort(a, 0, n - 1);
            cout << "\nMerge Sort Result:\n";
            break;

        case 5:
            radixSort(a, n);
            cout << "\nRadix Sort Result:\n";
            break;

        default:
            cout << "Invalid choice!";
            return 0;
    }

    printArray(a, n);

    return 0;
}