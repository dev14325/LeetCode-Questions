class Solution {
public:

    
    void rotate(vector<vector<int>>& matrix) {

        // transpose

        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[0].size();j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // swap row value


        for(int i=0;i<matrix.size();i++){
            int li = 0;
            int hi = matrix[i].size()-1;


            while(li<hi){
                int temp = matrix[i][li];
                matrix[i][li] = matrix[i][hi];
                matrix[i][hi] = temp;


                li++;
                hi--;
            }
        }
        
    }
};