#include <bits/stdc++.h> 
using namespace std; 
int size=3;

void permutation(char S[],int k){
    static int A[10]={0};
    static char ReS[10];
    int i;
    if(S[k]=='\0'){
        ReS[k]='\0';
        for(int j=0;j<size;j++){
            cout << ReS[j];
        }
        cout << endl;
    }else{
        for(i=0;S[i]!='\0';i++){
            if(A[i]==0){
                ReS[k]=S[i];
                A[i]=1;
                permutation(S,k+1);
                 A[i]=0;
            }
            
        }
       
    }
}
int main(){ 
 char  S[] = "ABC";
 permutation(S,0);
return 0; 
}

