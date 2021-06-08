#include <bits/stdc++.h> 
using namespace std; 
int RternaryS(int arr[],int l,int r,int key){
    if(l<=r){
    int mid1=l+(r-l)/2,mid2=r-(r-l)/2;
    if(arr[mid1]==key)return mid1;
    if(arr[mid2]==key)return mid2;    
    if(key<arr[mid1])return RternaryS(arr,l,mid1-1,key);
    else if(key>mid2)return RternaryS(arr,mid2+1,r,key);
    else return RternaryS(arr,mid1+1,mid2-1,key);
    }
    return -1;
}
int main(){
int n,k;cin>>n>>k;
int key=k,arr[n];
for(int i=0;i<n;i++){cin>>arr[i];}
sort(arr,arr+n);
int l =0,r=n-1;
int index = RternaryS(arr,l,r,key);
cout << index;
return 0; 
}