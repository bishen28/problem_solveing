#include <bits/stdc++.h> 
using namespace std; 
int  Maxsum(int arr[], int N , int K);
int main(){ 
   int N,K;
   cin >> N >> K;
   int arr[N];
   for(int i=0;i<N;i++){
       cin >> arr[i];
   }
  if(K<N){
   int  sum = Maxsum(arr,N,K);
   cout << sum;
  }else{
      cout << "Invalid";
  } 
   
return 0; 
}

int  Maxsum(int arr[], int N, int K){
    int i=0,j;
    int sum = 0, max = -10000000;
    
    for(i=0;i<=N-K;i++){
        sum = 0;
        for(j=i;j<K+i;j++){
            sum = sum + arr[j];
        }
        if(sum>=max) max = sum;
    }
    return max;
}