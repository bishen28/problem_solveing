#include <bits/stdc++.h> 
using namespace std; 
void countSort(int arr[], int n){
    int i,Max = -1;
    for(i=0;i<n;i++){
        if(arr[i]>Max) Max=arr[i];
    }
    int count[Max+1]={0};
    for(i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(i=1;i<=n;i++){
        count[i]=count[i]+count[i-1];
    }
    int B[n];
    for(i=n-1;i>=0;i--){
        B[--count[arr[i]]] = arr[i];
    }
    for(i=n-1;i>=0;i--){
        arr[i]=B[i];
    }
    
    
}
int main(){ 
int n,i; cin>>n; int arr[n];
for(i=0;i<n;i++){cin>>arr[i];}
 countSort(arr,n);
for(i=0;i<n;i++){cout<<arr[i]<<" ";} 
return 0; 
}