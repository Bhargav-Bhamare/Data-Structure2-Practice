#include <iostream>
using namespace std;

//Hash Function

int main(){
  int hash[10]; 
  for(int i=0;i<10;i++) hash[i]=-1;
  int keys[]={15,25,35,20};
  for(int k:keys){ 
    int i=k%10; 
    while(hash[i]!=-1) 
    i=(i+1)%10; 
    hash[i]=k; 
}

//Searching An Elementin the Hash (Linear Probing Method)

  int s=25, i=s%10;
  while(hash[i]!=s && hash[i]!=-1) 
  i=(i+1)%10;
  cout<<(hash[i]==s?"Found":"Not Found ")<<(" at Index :")<<i;
  
  return 0;
}