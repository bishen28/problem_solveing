//bishen//
#include <bits/stdc++.h> 
using namespace std; 

int partition_L(int arr[], int l, int h){
     int piovte = arr[h];
     int i = l;
     int j = h;
     while(i<j){
         while(arr[i]<piovte&&i<=j)i++;
         while(arr[j]>=piovte&&j>i)j--;
         if(i<j){
             swap(arr[i],arr[j]);
         }
     }
    swap(arr[j],arr[h]);
    return j;
    
}




void quicksortL(int arr[],int l, int h){
    if(l<h){
        int pi = partition_L(arr,l,h);
        quicksortL(arr,l,pi-1);
        quicksortL(arr,pi+1,h);
    }
}








int main(){ 
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout << arr[i]<< " ";
    }
return 0; 

}
