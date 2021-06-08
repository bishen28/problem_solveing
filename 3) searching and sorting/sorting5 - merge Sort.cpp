//*************  Merge Sort  *****************
// merge sort with taking acconunt the index of the arrays

#include <bits/stdc++.h> 
int arrI[100];
using namespace std;
void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    int LI[n1], RI[n2];
    
    for (i=0; i<n1; i++){
        L[i] = arr[l + i];
        LI[i] = arrI[l + i];}
    for (j=0; j < n2; j++){
        R[j] = arr[m + 1+ j];
        RI[j] = arrI[m + 1+ j];
    }
        
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i<n1&&j<n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            arrI[k] = LI[i];
            i++;
        }else{
            arr[k] = R[j];
            arrI[k] = RI[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        arrI[k] = LI[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        arrI[k] = RI[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[],int l, int r){
  if(l<r){
      int m = l + (r-l)/2;
      MergeSort(arr, l,  m);
      MergeSort(arr, m+1,  r);
      merge(arr, l, m, r);
  }
}
int main(){ 
 int n,i; cin >> n; int arr[n]; for(i=0;i<n;i++){cin>>arr[i];
     arrI[i]=i;
 }
 MergeSort(arr,0,n-1);
 for(i=0;i<n;i++){cout<<arr[i]<<" ";} cout << endl;
 for(i=0;i<n;i++){cout<<arrI[i]<<" ";}
 return 0; 
}