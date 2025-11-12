#include <iostream>
#include<stack>
#include <queue>
using namespace std;

int graph[5][5] = {
  {0,1,1,0,0},
  {1,0,0,1,0},
  {1,0,0,1,0},
  {0,1,1,0,1},
  {0,0,0,1,0}
};
int visited[5];

void dfs(int v){
  cout << v << " ";
  visited[v] = 1;
  for(int i=0;i<5;i++)
    if(graph[v][i] && !visited[i])
     dfs(i);
}

void explore(int start) {
  stack<int> s;
  s.push(start);
  visited[start] = 1;

  while (!s.empty()) {
    int v = s.top();
    s.pop();
    cout << v << " ";

    for (int i = 4; i >= 0; i--) {
      if (graph[v][i] && !visited[i]) {
        s.push(i);
        visited[i] = 1;
      }
    }
  }
}


void bfs(int start){
  queue<int> q;
  q.push(start);
  visited[start]=1;  //Same as DFS
  while(!q.empty()){
    int v=q.front(); 
    q.pop(); 
    cout<<v<<" ";   //Same as DFS
    for(int i=0;i<5;i++)
      if(graph[v][i] && !visited[i]){ 
        visited[i]=1; 
        q.push(i);
    }
  }
}

int main(){
  cout<<"DFS: "; 
  dfs(0);
  for(int i=0;i<5;i++){
     visited[i]=0;
  }
  cout<<"\nBFS: "; bfs(0);
}



