#include <bits/stdc++.h>
using namespace std;



int BFS(vector<vector<int>> &mtx, int mx,int n, int m, queue<pair<pair<int,int>,int>> &q,vector<vector<int>> &visited){
    if(q.size()==n*m) return 0;
    
    int mxhr = 0;
    while(!q.empty()){
         int i = q.front().first.first;
         int j = q.front().first.second;
         int hr = q.front().second;
         q.pop();
         //cout <<  q.size() << " ";
         visited[i][j]  = 1;
         //cout << mxhr<< endl;
      for(int r=i-1;r<=i+1;r++){
         if(r<0||r>=n) continue;
         for(int c=j-1;c<=j+1;c++){
             if(c<0||c>=m) continue;
             if(r==i&&c==j) continue;
             if(visited[r][c]==0){
                 visited[r][c]  = 1;
                 q.push({{r,c},hr+1});
                 mxhr = max(mxhr,hr+1);
             }
         }
      }
    }
  return mxhr;
}

void  solve(){
      int n,m;cin>>n>>m;
      int mx = 0;
      vector<vector<int>> mtx(n,vector<int>(m,0));
      vector<vector<int>> visited(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cin>>mtx[i][j];
            mx = max(mx,mtx[i][j]);
         }
      }
      //cout << mx << endl;
      queue<pair<pair<int,int>,int>> q;
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(mtx[i][j]==mx){
              q.push({{i,j},0});
            }
         }
      }
   //cout << q.size() << endl;
   cout << BFS(mtx,mx,n,m,q,visited);

}


int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int T=1;cin>>T;
    while(T--){
        solve();
        if(T)cout << endl;
    }
    return 0;
}
