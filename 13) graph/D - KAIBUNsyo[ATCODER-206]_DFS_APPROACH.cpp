// LINK - https://atcoder.jp/contests/abc206/tasks/abc206_d
// D - KAIBUNsyo

#include <bits/stdc++.h>
using namespace std;

// who to get the intitution if raph here
// intuition was because of the fact that result of 1 pair depends on result of another pair
// Like for 1,2,3,2 , result of {1,2} depends on making {2,3} pairs elements equal or vice versa
  
const int N = (int) 1e6;
int BFS(vector<vector<int>> &adj_list, vector<bool> &visited,int s){
    queue<int> q;
    q.push(s);
    int x = 0;
    while(!q.empty()){
      s = q.front(); q.pop();
      for(auto adj_node:adj_list[s]){
        if(!visited[adj_node]){
          visited[adj_node] = true;
          q.push(adj_node);
          x++;
        }
      }
   }
    return x==0 ? 0 : x-1;
}

void  solve(){
      int n;cin>>n;
      int arr[n];
      for(int i=0;i<n;i++){
         cin>>arr[i];
      }
      set<pair<int,int>> s;
      pair<int,int> p;
      vector<vector<int>> adj_list(N);
      vector<bool> visited(N,false);
       int i=0,j=n-1;
       while(i<j){
         if(arr[i]!=arr[j]){
            if(arr[i]<arr[j]){
               s.insert({arr[i],arr[j]});
            }else{
               s.insert({arr[j],arr[i]});
            }  }          
         i++;j--;
       }
      for(auto x:s){
         adj_list[x.first].push_back(x.second);
         adj_list[x.second].push_back(x.first);
      }
     int count = 0;
     for(int i=1;i<=N;i++){
         if(!visited[i]){
            int x = BFS(adj_list,visited,i);
            //cout << i << " " << x << endl;
            count+=x;
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
    int T=1;//cin>>T;
    while(T--){
        solve();
        if(T)cout << endl;
    }
    return 0;
}
