//bishen//
#include <bits/stdc++.h> 
using namespace std; 

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
      int row = matrix.size();
      int col = matrix[0].size();
      int r = 0;
      int c = col-1;
            
        while(r<row&&c>=0){
            if(target==matrix[r][c])return true;
            else if(target>matrix[r][c]) r++;
            else c--;
        }
        
        
      return false;  
    }


int T;
int main(){ 
 
cin >> T;
while(T--){
    
    
    searchMatrix(matrix,target);

    if(T) cout << endl;
}
return 0; 

}
