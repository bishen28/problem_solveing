#include <bits/stdc++.h> 
using namespace std; 
int IternaryS(int arr[],int l,int r,int key){
    while(l<=r){
    int mid1=l+(r-l)/2,mid2=r-(r-l)/2;
    if(arr[mid1]==key)return mid1;
    if(arr[mid2]==key)return mid2;
    if(key<arr[mid1])r=mid1-1;
    else if(key>mid2)l=mid2+1;
    else{l=mid1+1;r=mid2-1;}
    }
    return -1;
}
int main(){
int n,k;cin>>n>>k;
int key=k,arr[n];
for(int i=0;i<n;i++){cin>>arr[i];}
sort(arr,arr+n);
int l =0,r=n-1;
int index = IternaryS(arr,l,r,key);
cout << index;
return 0; 
}