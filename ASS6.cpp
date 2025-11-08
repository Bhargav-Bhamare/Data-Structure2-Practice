//Max Heap
#include <iostream>
using namespace std;

void heapify(int a[], int n, int i){
  int l=2*i+1, r=2*i+2, largest=i;
  if(l<n && a[l]>a[largest]) largest=l;
  if(r<n && a[r]>a[largest]) largest=r;
  if(largest!=i){ 
    swap(a[i],a[largest]); 
    heapify(a,n,largest); 
    }
}

void build(int a[], int n){
  for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
}

int main(){
  int a[]={3,9,2,1,4,5};
  int n=6;
 build(a,n);
  cout<<"Max Heap: ";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
}