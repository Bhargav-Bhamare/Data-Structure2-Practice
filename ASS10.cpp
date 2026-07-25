#include <iostream>
#include <string>
using namespace std;

int main(){
  string text="hello world", pat="world";
  int n=text.size(), m=pat.size();
  for(int i=0;i<=n-m;i++){
    int j;
    for(j=0;j<m;j++)
      if(text[i+j]!=pat[j]) break;
    if(j==m) cout<<"Found at Index: "<<i;
  }
}