// insertion sort and rearranging the indices 
/********        Selection Sort         ***************/
//   Time Complexity: O(N2) 

#include <bits/stdc++.h> 
using namespace std;
int arrI[100];
void swapI(int &a,int &b){
    int temp  = a;
    a=b;
    b=temp;
}
void swap(int &a,int &b){
    int temp  = a;
    a=b;
    b=temp;
}
void Selection_Sort(int arr[],int n){
    int min,minI;
  for(int i=0;i<n;i++){
      min = arr[i];
      int f=0;
      for(int j=i;j<n;j++){
         if(arr[j]<min){
             min = arr[j];
             minI = j;
             f=1;
          } 
         } 
         if(f){
             swap(arr[minI],arr[i]);
             swapI(arrI[minI],arrI[i]);
         }
      }
  }

int main(){ 
int n;cin>>n;int arr[n];for(int i=0;i<n;i++){cin>>arr[i];arrI[i]=i;}
Selection_Sort(arr,n);
for(int i=0;i<n;i++){
cout <<  arr[i] << " ";
} cout << endl;
for(int i=0;i<n;i++){
cout <<  arrI[i] << " ";
}
return 0; 
}