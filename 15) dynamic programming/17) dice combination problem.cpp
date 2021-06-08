//bishen//
//  Dice Combinations

#include <bits/stdc++.h> 
using namespace std; 
int mod = pow(10,9)+7;
int main(){ 
  
  int N;
  cin>>N;
  int dp[N+1] = {0};
  dp[0] = 1; dp[1] = 1;
  
  for(int i=2;i<=N;i++){
      for(int j=1;j<=6;j++){
          if(i-j>=0){
              dp[i] = (dp[i]%mod+ dp[i-j]%mod)%mod;
          }
      }
  }
   cout << dp[N];
return 0; 

}
