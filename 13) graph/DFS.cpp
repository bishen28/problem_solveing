#include <bits/stdc++.h>
using namespace std;

int inTime[10000];
int outTime[10000];
int inT = 0, outT = 0;

void DFS(int s,vector<vector<int>> &adj_list,vector<bool> &visited){
       visited[s] = true;
       inTime[s] = inT++;
       for(auto adjNode : adj_list[s]){ 
          if(!visited[adjNode]){
              DFS(adjNode,adj_list,visited);
          }
       }
       outTime[s] = outT++;
}

void solve(){
   int n,m;cin>>n>>m;
   vector<vector<int>> adj_list(n);
   vector<bool> visited(n,false);
   for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
   }
  DFS(0,adj_list,visited);
}


int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    solve();
    return 0;
}
