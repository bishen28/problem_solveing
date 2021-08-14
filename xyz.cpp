#include <bits/stdc++.h>
using namespace std;

int findmaxsub(string &S1,string &S2,int &res){
    int n = S1.length();
      vector<vector<int>> dp(n+1, vector<int>(n+1,0));
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               if(S1[i-1]==S2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
               else dp[i][j] = 0;
               res =  max(res,dp[i][j]);  
           }
       }

   for(int i=0;i<n-res;i++){
      string s = S1.substr(i,res);
      if(S2.find(s)!=-1) return S2.find(s);
   }
return res;
}

void solve(){
    string A,B;cin>>A>>B;
    int C;cin>>C;
    string str = B; reverse(str.begin(), str.end());
    //cout << A << '\n' << B << '\n' << str << '\n';
    int res = -1;
    int c = findmaxsub(A,str,res);
    //cout << c << '\n' << res << '\n';
    int cost = 0;
    int res2 = res;
    for(int i=c;i<c+res;i++){
        if(A[i]==B[i]) res2--;
    }
    if(res2>=C&&res){
        cost+=C;
        for(int i=0;i<A.length();i++){
            if(i>=c&&i<c+res) continue;
            if(A[i]!=B[i]) cost++;
        }
        cout << cost;

    }else{
       for(int i=0;i<A.length();i++){
        if(A[i]!=B[i])cost++;
       }
       cout << cost;
    }
 
}

int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20); 
    int T=1;//cin>>T;
    while(T--){
        solve();
        if(T)cout << endl;
    }
    return 0;
}
