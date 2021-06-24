#include <bits/stdc++.h>
using namespace std;


namespace adjacency_matrix{
    G[100+5][100+5];
    void readGraph(){
        int n,m; cin>>n>>m;
        
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            G[x][y] = 1;
            G[y][x] = 1;
        }
   }
   
    vector<int> getAllNeighbour(int x){
            vector<int> res;
    
            for(int i=1;i<=n;i++){
                if(G[x][i]) res.push_back(i);
            }
        return res;  
    }
    
    bool is_adjacent(int x, int y){
        return G[x][y];
    }
   
    
}

namespace adjacency_list{
    const int  N = 10e5;
    const int  M = 10e6;
    vector<int> G[N];
    int n,m;
    
    void readGraph(){
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    
    vector<int> getAllNeighbour(int x){
        // ordrr degree of x
        return G[x];
    }
    
    bool is_adjacent(int x, int y){
        for(auto w:G[x]){
            if(w==y) return true;
        }
        return false;
    }
    
}

namespace edge_list{
    const int  N = 10e5;
    const int  M = 10e6;
    
    int U[M],V[M],W[M];
    
    // i'th edge will be between vertex U[i] and V[i]. 
    // The weight of the i'th edge  will be W[i];
    vector<int> G[N];
    int n,m;
    void readGraph(){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            // int x,y;
            // cin>>x>>y;
            // ordering is same as the order in which they appear in the input.
            cin>>U[i]>>V[i]>>W[i];
            G[U[i]].push_back(i);
            G[V[i]].push_back(i);
        }
    }
    
    vector<int> getAllNeighbour(int x){
        // ordrr degree of x
        return G[x];
    }
    
    bool is_adjacent(int x, int y){
        for(auto w:G[x]){
            if(w==y) return true;
        }
        return false;
    }
    
}



int main(){
    readGraph();

    return 0;
}
