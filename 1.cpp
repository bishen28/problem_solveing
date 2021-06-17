#include <bits/stdc++.h>
using namespace std;


void  BFS(int s,vector<vector<int>> &adj_list,vector<int> &Protected, int S, vector<bool> & visited){
       Protected[s]++;
       queue<int> q;
       q.push(s);
       while(!q.empty()&&S>0){
          int node = q.front();q.pop();S--;
          for(auto adj_node:adj_list[node]){ 
            if(visited[adj_node]==false){ 
                   Protected[adj_node]++;
                   q.push(adj_node);
                   visited[adj_node] = true; 
            }    
          }
       }
}

void solve(){
   int n,r,m;cin>>n>>r>>m;
   vector<vector<int>> adj_list(n+1);
   vector<int> Protected(n+1,0);
   vector<bool> visited(n+1,false);
   for(int i=0;i<r;i++){
    int A,B;cin>>A>>B;
    adj_list[A].push_back(B);
    adj_list[B].push_back(A);
   }
   vector<int> strength(n+1,-1);
   for(int i=0;i<m;i++){
       int K,S;cin>>K>>S;
       strength[K] = S;
   }
   for(int i=1;i<=n;i++){
      if(strength[i]>0){
       BFS(i,adj_list,Protected,strength[i],visited);
      }else{
        if(strength[i]==0) Protected[i]++; 
      }
      for(int i=0;i<=n;i++) visited[i] = false;
   }
   for(int i=1;i<=n;i++){
    if(Protected[i]>1){
      cout << "No";
      return;
    }
   }
   cout << "Yes";
   return;
}


int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int T;cin>>T;
    while(T--){
     solve();if(T)cout << "\n";
    }
    return 0;
}
