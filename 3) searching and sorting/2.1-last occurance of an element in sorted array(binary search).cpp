#include <bits/stdc++.h> 
using namespace std; 
int n;
int last(int arr[], int l, int r , int x){
   
   if(arr[r]==x) return r;
    while(l<=r){
        int m = (r+l)/2;
        if(arr[m]==x&&arr[m+1]>x) return m;
        else if(arr[m]<=x) l = m+1;
        else r = m-1;
    }

}


int main(){ 
    int k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int l=0,r=n-1,key=k;
    int last_occ = lastbinary(arr,l,r,key);
    cout << last_occ;
return 0; 
}