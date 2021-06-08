#include <bits/stdc++.h> 
using namespace std; 
void reverse(int arr[], int N);
int main(){ 
   int N;
   cin >> N;
   int arr[N];
   
   for(int i=0;i<N;i++){
       cin >> arr[i];
   }
   
   reverse(arr,N);
   
   for(int i=0;i<N;i++){
       cout << arr[i];
       if(i<N-1) cout << " ";
   }
   
return 0; 
}

void reverse(int arr[], int N){
    int i=0;
    int temp;
    for(i=0;i<N/2;i++){
        temp = arr[i];
        arr[i]= arr[N-1-i];
        arr[N-1-i] = temp;
    }
}