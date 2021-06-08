// this function work for only ascending sorted array*****
#include <bits/stdc++.h> 
using namespace std; 
int IbinaryS(int arr[],int l,int r, int key){
    while(l<=r){
        int  mid = (r+l)/2;
        if(arr[mid]==key) return mid;
        if(arr[mid]>key){
            r = mid-1;
        }
        if(arr[mid]<key){
            l = mid+1;
        }
    }
    return -1;
}

int main(){ 
 int n,k;
 cin >> n >>  k;
 int arr[n];
 for(int i=0;i<n;i++){
     cin >> arr[i];
 }
 //  sort the array in ascending order 
 sort(arr,arr+n);
 int l = 0, r = n-1, key = k;
 int index = IbinaryS(arr,l,r,key);
 cout << index;
return 0; 
}