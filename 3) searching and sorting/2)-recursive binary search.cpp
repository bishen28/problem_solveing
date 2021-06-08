// this function work for assending sorted array********

#include <bits/stdc++.h> 
using namespace std;

int binarys(int arr[], int l , int r, int key){
  int mid = (l+r)/2;   
  if(l<=r){
     if(arr[mid]<key) return binarys(arr,mid+1,r,key);
     if(arr[mid]>key) return binarys(arr,l,mid-1,key);
     if(arr[mid]==key) return mid;
  }else{
     return -1;
  }
}
int main(){ 
int n,k;
cin >>n>>k;
int arr[n];
for(int i=0;i<n;i++){
    cin >> arr[i];
}
sort(arr,arr+n);
int l = 0;
int  r = n-1;
int key = k;
int index = binarys(arr,l,r,key) ;
cout << index;
return 0; 
}

