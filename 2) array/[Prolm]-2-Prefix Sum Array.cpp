#include <bits/stdc++.h> 
using namespace std; 
void  Prefix_Sum_Array(int arr[], int N);
int main(){ 
   int N;
   cin >> N ;
   int arr[N];
   for(int i=0;i<N;i++){
       cin >> arr[i];
   }
 Prefix_Sum_Array(arr,N);
 
    for(int i=0;i<N;i++){
       cout <<  arr[i];
       if(i<N-1) cout << " ";
   }
return 0; 
}

void  Prefix_Sum_Array(int arr[], int N){
      int sum = 0;
      for(int i=0;i<N;i++){
          sum = sum+arr[i];  // 
          arr[i] = sum;
      }
}

// good method 

/*void fillPrefixSum(int arr[], int N, int prefixSum[]) 
{ 
    prefixSum[0] = arr[0]; 
  
    // Adding present element  
    // with previous element 
    for (int i = 1; i < N; i++) 
        prefixSum[i] = prefixSum[i-1] + arr[i]; 
} 
*/