// finding palindrom of maximum size in a char array.
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 

 
 string str,str2;
 cin >>str;
 int length = 0,i,j;
 for(i=0;i<str.length()-1;i++){
     for(j=2;j<=str.length()-i;j++){
      string s2,s1=str.substr(i,j);
      s2 = s1;
      reverse(s1.begin(), s1.end());
      int x = s1.compare(s2);
      if(x==0&&j>length){
      length = j;
      str2 = s1;
      }
      
     }
 }
 
 cout << length << " " << str2;;
 
 
return 0; 
}

