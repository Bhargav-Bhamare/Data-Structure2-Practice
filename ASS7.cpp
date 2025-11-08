//Selection

#include <iostream>
using namespace std;

int main(){
    int a[]={5,3,8,1,2}, n=5;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
    for(int x:a) cout<<x<<" ";
}

//Insertion



#include <iostream>
using namespace std;

int main(){
    int a[]={5,3,8,1,2}, n=5;
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key) a[j+1]=a[j--];
        a[j+1]=key;
    }
    for(int x:a) cout<<x<<" ";
}


//Quick Sort

#include <iostream>
using namespace std;

int part(int a[], int l, int r){
    int p=a[r], i=l-1;
    for(int j=l;j<r;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int pi=part(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

int main(){
    int a[]={5,3,8,1,2}, n=5;
    quickSort(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}


//Radix
#include <iostream>
using namespace std;

int getMax(int a[], int n){int m=a[0];for(int i=1;i<n;i++) if(a[i]>m)m=a[i];return m;}

void countSort(int a[], int n, int e){
    int o[n], c[10]={0};
    for(int i=0;i<n;i++) c[(a[i]/e)%10]++;
    for(int i=1;i<10;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) o[--c[(a[i]/e)%10]]=a[i];
    for(int i=0;i<n;i++) a[i]=o[i];
}

void radix(int a[], int n){
    for(int e=1; getMax(a,n)/e>0; e*=10) countSort(a,n,e);
}

int main(){
    int a[]={170,45,75,90,802,24,2,66}, n=8;
    radix(a,n);
    for(int x:a) cout<<x<<" ";
}


//Merge

#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r){
    int i=l, j=m+1, b[100], k=l;
    while(i<=m && j<=r) b[k++]=(a[i]<a[j])?a[i++]:a[j++];
    while(i<=m) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(i=l;i<=r;i++) a[i]=b[i];
}

void sort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int a[]={5,3,8,1,2}, n=5;
    sort(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}

