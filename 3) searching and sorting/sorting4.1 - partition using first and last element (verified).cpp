//bishen//
#include <bits/stdc++.h> 
using namespace std; 


int partition_L(int arr[], int l, int h){
     int piovte = arr[l];                     // first as pivote
     int i = l;
     int j = h;
     while(i<j){
         while(arr[i]<=piovte&&i<j)i++;
         while(arr[j]>piovte&&j>=i)j--;
         if(i<j){
             swap(arr[i],arr[j]);
         }
}
int partition_U(int arr[], int l, int h){
     int piovte = arr[h];                      // last as pivote
     int i = l, j = h;
     while(i<j){
         while(arr[i]<piovte&&i<=j)i++;
         while(arr[j]>=piovte&&j>i)j--;
         if(i<j)swap(arr[i],arr[j]);
     }
    swap(arr[j],arr[h]);
    return j;
}
 swap(arr[j],arr[l]);
 return j;
}

void quickSort(int arr[], int l, int h){
        if(l<h){
        int pi = partition(arr,l,h); //partition using first
                                     // last element
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,h);
    }
}


int main(){ 

int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout << arr[i]<< " ";
    }
return 0; 

}
