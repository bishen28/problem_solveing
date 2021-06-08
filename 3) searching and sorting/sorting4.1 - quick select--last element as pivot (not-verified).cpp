//bishen//
#include <bits/stdc++.h> 
using namespace std; 
int partition(int arr[], int l, int h){
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

int quickselect(int arr[], int l, int h, int k){
    if(l<h){
        int pi = partition(arr,l,h);
        if(pi<k)quickselect(arr,pi+1,h,k);
        if(pi>k)quickselect(arr,l,pi-1,k);
    }
}


int main(){ 
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  int k=0; cin>>k;
  quickselect(arr,0,n-1,k-1);
  cout << arr[k-1];
  
return 0; 

}
