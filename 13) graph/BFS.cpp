#include <bits/stdc++.h>
using namespace std;

// only simple BFS to check which nodes are visited from zero 
/*
void Adjency_list(){   

int s = 0;  // starting point of graph
vector<bool> visited(n,false);
visited[s] = true;
queue<int> q;
q.push(s);
while(!q.empty()){
   s = q.front(); q.pop();
   for(auto x:adj_list[s]){
     if(!visited[x]){
        visited[x] = true;
        q.push(x);
     }
   }
}

for(int i=0;i<n;i++){
  if(visited[i]){
    cout << "Node " << i  << " is visited from Node 0\n";
  }
}


}
*/


// BFS to find the distance of each node form 0;
/*
void Adjency_list(){ 
   int n,m;
   cin>> n>>m;
   vector<vector<int>> adj_list(n);

   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
   }
int inf = 1000000000;
int s = 0;  // starting point of graph
vector<bool> visited(n,false);
visited[s] = true;
vector<int> distance(n,inf);
distance[s] = 0;
queue<int> q;
q.push(s);
while(!q.empty()){
   s = q.front(); q.pop();
   for(auto adj_node:adj_list[s]){
     if(!visited[adj_node]){
        visited[adj_node] = true;
        distance[adj_node] = distance[s] + 1;
        q.push(adj_node);
     }
   }
}

for(int i=0;i<n;i++){
  if(visited[i]){
    cout << "distance of " << i << " is " << distance[i] << endl;
  }
}


}
*/


// Find the number of connected component.





void BFS(vector<vector<int>> &adj_list, vector<bool> &visited,int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      s = q.front(); q.pop();
      for(auto adj_node:adj_list[s]){
        if(!visited[adj_node]){
          visited[adj_node] = true;
          q.push(adj_node);
        }
      }
   }
}




void connected_component(){
  // read the graph
   int n,m;
   cin>> n>>m;
   vector<vector<int>> adj_list(n);

   for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
   }

int s = 0;  // starting point of graph
vector<bool> visited(n,false);
//visited[s] = true;   
 int count = 0;
for(int i=0;i<n;i++){
  if(!visited[i]){
    visited[i] = true;
    count++;
    BFS(adj_list,visited,i);
  }
}

cout << count;
}









int main(){

    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    // Adjency_matrix();
    //Adjency_list();
    connected_component();
  
    return 0;
}
