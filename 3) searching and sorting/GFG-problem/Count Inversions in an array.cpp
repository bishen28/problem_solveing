#include <bits/stdc++.h>
using namespace std;
long long c = 0; 
void merge(long long arr[],long long temp[],long long l,long long m,long long r){
         
    int i=l;
    int j=m+1;
    int k=l;
    
    while ((i<=m)&&(j<=r)){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			c = c +((m+1) - i);
		}
	}

	while (i <= m) temp[k++] = arr[i++];
	while (j <= r)temp[k++] = arr[j++];
	for (i = l; i <= r; i++) arr[i] = temp[i];
  }  

    
void mergesort(long long arr[],long long temp[], long long l, long long r){
        
        if(l<r){
           int m = (l+r)/2;
           mergesort(arr,temp,l,m);
           mergesort(arr,temp,m+1,r);
           merge(arr,temp,l,m,r);
        }
    }

    long long int inversionCount(long long arr[], long long N){
       long long temp[N];
       mergesort(arr,temp,0,N-1);
       return c;  
    }

int main(){
    int n;cin>>n;
	int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	mergeSort(arr, n);
	cout << c;
	return 0;
}

