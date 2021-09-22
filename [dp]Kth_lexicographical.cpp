// problem link --> https://atcoder.jp/contests/abc202/tasks/abc202_d
// problem link --> https://codeforces.com/problemset/problem/1328/B

#include <bits/stdc++.h>
using namespace std;

typedef long long               ll;
ll a,b,k;
string ans;
ll dp[105][105];

ll fact(ll a, ll b){
    return dp[a+b][b];
}

void findKth(ll a, ll b, ll from, ll to){
      if(a==0&&b==0) return;
      ll i = fact(a-1,b);
      if((k<=i+from-1)&&k>=from){
        ans+="a";
        findKth(a-1,b,from,from+i-1);
      }else{
        ans+="b";
        findKth(a,b-1,from+i,to);
      }
}



void solve(){
     cin>>a>>b>>k; 
     ans = "";
     findKth(a,b,1,dp[a+b][a]);
     cout << ans;
}



int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int n=1;n<=100;n++){
        for(int r=0;r<=100;r++){
            if(r==0){
                dp[n][r] = 1;
                continue;
            }
            if(n>=r)dp[n][r] = dp[n-1][r] + dp[n-1][r-1];
            else break;
        }
    }

    int T=1;  //cin>>T;
    while(T--){
        solve();
        if(T)cout << endl;
    }
    
    return 0;
}

