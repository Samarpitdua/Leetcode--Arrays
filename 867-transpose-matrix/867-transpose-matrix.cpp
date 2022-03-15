class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix[0].size() , vector<int>(matrix.size() , -1));
        for(int i = 0 ; i < matrix.size() ;i++)
        {
            for(int j = 0 ; j < matrix[0].size() ;j++)
            {
                if(i != j)
                    ans[j][i] = matrix[i][j];
                else
                    ans[i][j] = matrix[i][j];
            }
        }
        return ans;
    }
};