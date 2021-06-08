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
      int product = 1;
      for(int i=0;i<N;i++){
          product = product*arr[i];  // 
          arr[i] = product;
      }
}

// good method 

/*void fill_Prefix_product(int arr[], int N, int Prefix_product[]) 
{ 
    Prefix_product[0] = arr[0]; 
  
    // multiply present element  
    // with previous element 
    for (int i = 1; i < N; i++) 
        Prefix_product[i] = Prefix_product[i-1]*arr[i]; 
} 
*/