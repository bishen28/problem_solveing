// insertion sort and rearranging the indices 
/********        Bubble Sort         ***************/

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
void Bubble_Sort(int arr[],int n){
  for(int i=0;i<n-1;i++){
      for(int j=0;j<(n-1)-i;j++){
         if(arr[j+1]<arr[j]){
             swap(arr[j+1],arr[j]);
             swapI(arrI[j+1],arrI[j]);
         } 
          
      }
  }
}
int main(){ 
int n;cin>>n;int arr[n];for(int i=0;i<n;i++){cin>>arr[i];arrI[i]=i;}
Bubble_Sort(arr,n);
for(int i=0;i<n;i++){
cout <<  arr[i] << " ";
} cout << endl;
for(int i=0;i<n;i++){
cout <<  arrI[i] << " ";
}
return 0; 
}