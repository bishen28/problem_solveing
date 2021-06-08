// insertion sort and rearranging the indices 
/********       Insertion Sort                 ***************/
//Time Complexity: O(N2), where N is the size of the array.
#include <bits/stdc++.h> 
using namespace std;
int arrI[100];
void insertion_sort(int arr[] ,int n){
    int key,i,j,keyI;
    for(i=1;i<n;i++){
        key = arr[i];
        keyI = i;
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            arrI[j+1] = arrI[j];
            j--;
        }
        arr[j+1]=key;
        arrI[j+1]=keyI;
    }
}

int T;
int main(){ 
int n;
cin >>  n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
    arrI[i]=i;
}
insertion_sort(arr,n);
for(int i=0;i<n;i++){
    cout<< arr[i] << " ";
}
cout << endl;
for(int i=0;i<n;i++){
    cout<< arrI[i] << " ";
}
return 0; 
}