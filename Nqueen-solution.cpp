class Solution {
public:
               
    set<int> s;
    int k;
    vector<pair<int ,int>> cell;
   // int c = 0;
    vector<vector<string>> vvs;
    
    bool check(int r, int c){
        for(auto it:cell){
           if(r - it.first == abs(c-it.second) ) return true;
        }
        
        return false;      
    }



void Nqueen(int i){
    
    if(s.size()==k){
        vector<string> vs;
        
        for(int i=0;i<k;i++){
            string str;
            for(int j=0;j<k;j++){
                
                   str  = str + ".";
                
            }
            vs.push_back(str);
        }
        
        for(auto it:cell){
           vs[it.first][it.second]  = 'Q';
        }
        
        
        vvs.push_back(vs);
        //c++;
        return;
    }
    
    
    for(int j=0;j<k;j++){
        if(s.find(j)!=s.end()||check(i,j)) continue;
        pair<int,int> p  = {i,j};
        cell.push_back(p);
        s.insert(j);
        Nqueen(i+1); 
        s.erase(j);
        cell.pop_back();
    }
  
}
    
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        k = n;
        Nqueen(0);
        return vvs;
    }
};