#include <bits/stdc++.h>

using namespace std;

bool ispossible(long long int arr[], long long int m, long long int n,long long int P){

     long long int count = 0;
     for(int i=0;i<n;i++){
         count += (((sqrt(1.0+((8.0*m)/arr[i])))-1.0)/2.0);
         if(count>=P) return true;
     }
return false;
}

long long int largestMinDist(long long int arr[], long long int n, long long int P){
	long long int l = 0;
	long long int r = pow(10,7);
	long long int T = -1;
	
	while(l<r){
	    long long int m = (l+r)/2;
	    if(ispossible(arr,m,n,P)){
	       T = m;
	       r = m;
	    } 
	    
	    else l = m+1;
	}
	return T;
}

int main(){
    int T;cin>>T;
    while(T--){
       long long int P;cin>>P;
       long long int N;cin>>N;
       long long int arr[N];
       
       for(int i=0;i<N;i++){
           cin>>arr[i];
       }
       sort(arr,arr+N);
       long long int T = largestMinDist(arr,N,P);
       cout << T; 
       if(T)cout << endl;
    }
	return 0;
}