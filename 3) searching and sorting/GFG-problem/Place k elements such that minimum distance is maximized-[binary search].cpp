#include <bits/stdc++.h>

using namespace std;

bool ispossible(int mid, long long int arr[], long long int n, long long int k){
     long long int prev = arr[0];
     long long int count = 1;
     for(int i=1;i<n;i++){
         if(arr[i]-prev >= mid){
             count++;
             prev = arr[i];
         }
         if(count==k)return true;
     }
return false;
}

long long int largestMinDist(long long int arr[], long long int n, int k){
	long long int l = 1;
	long long int r = arr[n-1]-arr[0];
	long long int mdis = -1;
	
	while(l<r){
	    long long int m = (l+r)/2;
	    if(ispossible(m,arr,n,k)){
	       mdis = max (mdis,m);
	       l = m+1;
	    } 
	    
	    else r = m;
	}
	return mdis;
}

int main(){
    long long int  T;cin>>T;
    while(T--){
       long long int N,C;cin>>N>>C;
       long long int arr[N];
       
       for(int i=0;i<N;i++){
           cin>>arr[i];
       }
       sort(arr,arr+N);
     long long int maxdis =   largestMinDist(arr,N,C);
       cout << maxdis;
       if(T) cout << endl;
        
    }

	return 0;
}