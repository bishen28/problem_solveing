//bishen//
#include <bits/stdc++.h> 
using namespace std; 
void co(int dp[],int N,int arr[]){
    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);
    
for(int i=2;i<=N;i++){
dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
}
   
}
int main(){ 

  int N;cin>>N;
  int arr[N];
  for(int i=0;i<N;i++){
      cin>> arr[i];
  }
  int dp[N] = {0};
  co(dp,N-1,arr);
  cout << dp[N-1]; 
return 0; 

}
