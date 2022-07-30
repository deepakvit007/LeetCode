class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();//rows
        int m=mat[0].size();//col
        
        int sumofdig=0;
        for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){

            if(i == j){
                sumofdig = sumofdig + mat[i][j];
            }

            if(i + j == n-1 && i!=j)
            {
                sumofdig=sumofdig+mat[i][j];
            }


        }
       
    }
        return sumofdig;
    }    
};