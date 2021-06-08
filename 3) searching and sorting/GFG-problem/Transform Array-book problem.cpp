//bishen
/*Transform ArrayHow would you swap elements of an array like 
[a1 a2 a3 a4 b1 b2 b3 b4] toconvert it into 
[a1 b1 a2 b2 a3 b3 a4 b4] */

#include <bits/stdc++.h> 
using namespace std; 
void Transform(char arr[],int n){
   int k = 0;
   for(int i=(n/2)-1;i>0;i--){
        for(int j=i;j<n-i;j+=2){
            swap(arr[j],arr[j+1]);
        }
   }
}
int main(){ 

int n;cin>>n;
char arr[n] = { 'a' ,'b', 'c', 'd', '1', '2', '3', '4'};

 Transform(arr,n);
 
for(int i=0;i<n;i++){
    cout<< arr[i] << " ";
}

return 0; 

}
