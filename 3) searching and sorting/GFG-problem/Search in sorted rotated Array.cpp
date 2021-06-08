//bishen//
#include <bits/stdc++.h> 
using namespace std; 

int findpeak(int arr[],int l, int r){
    if(l==r) return l;  //&&arr[l]!=arr[r] this 
    if(r==l+1){     // condition if all element 
                                    // are same
        if(arr[r]>=arr[l])return r;
        else return l;
    }
    while(l<=r){
        int m = (l+r)/2;
        if(arr[m]>arr[m-1]&&arr[m]>arr[m+1])return m;
        else if(arr[m-1]>arr[0]) return findpeak(arr,m+1,l);
        else return findpeak(arr,l,m-1);
    }
    return -1;
}
int findkeyI(int arr[],int l, int r,int key){

    if(l<=r){
        int m = (l+r)/2;
        if(arr[m]==key) return m;
        else if(arr[m]<key) return findkeyI(arr,m+1,r,key);
        else return findkeyI(arr,l,m-1,key);
    }
    return -1;
}

int T;
int main(){ 

cin >> T;
while(T--){
    int n; cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x = findpeak(arr,0,n-1);
    cout << "peek Index:-" << x;
    int index=-1;;
    int key; cin>>key;
    index = findkeyI(arr,0,x,key);
    if(index==-1) index = findkeyI(arr,x+1,n-1,key);
     
    cout << "\nIndex of the Key:- " << index;
    if(T) cout << endl;
}
return 0; 

}
