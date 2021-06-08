//bishen//
#include <bits/stdc++.h> 
using namespace std; 
int removeduplicate(int arr[], int n){
    sort(arr,arr+n);
    int j=0;
    for(int i=1;i<n;i++){
       if(arr[i]!=arr[j]){
           j++;
           arr[j]=arr[i];
       }
    }
    
 return j;   
}
int main(){ 
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  int j = removeduplicate(arr,n);
  for(int i=0;i<=j;i++){
      cout<< arr[i] << " ";
  }


return 0; 

}
