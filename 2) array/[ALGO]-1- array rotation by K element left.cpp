#include <bits/stdc++.h> 
using namespace std; 
void rotate_by_1(int arr[], int N);
int main(){
    
    int arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int N=12,K=3, i;
    
    for(i=0;i<K;i++){
    rotate_by_1(arr,N);
    }
    
    for(i=0;i<N;i++){
        cout << arr[i];
        if(i<N-1) cout << 
    }
       
return 0; 
}

 void rotate_by_1(int arr[], int N){
    int i = 0;
    int temp = arr[0];
    for(i=0;i<N-1;i++){
        arr[i] = arr[i+1];
    }
    arr[N-1] = temp;
}