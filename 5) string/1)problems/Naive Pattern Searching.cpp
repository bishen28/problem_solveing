#include <bits/stdc++.h> 
using namespace std; 
int c =0;
 void search(string patt, string text){
     int n=text.length();
     int m=patt.length();
     
     for(int i=0;i<=n-m;i++){
         int j, k = i;
         
         for(j=0;j<m;j++){
             
             if(text[k++]!=patt[j]) break;
             
         }
         
         if(j==m) {
             c++;
             cout << "found " ;
         }
         
         
     }

 }
 
int main(){ 

 string text, patt;
 getline(cin,text);
 getline(cin,patt);
 // cout << text << " " << patt << endl;
 search(patt,text);
 cout << c ;
 
return 0; 
}

