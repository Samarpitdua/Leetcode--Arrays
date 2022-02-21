class Solution {
public:
//     int memo(vector <vector <vector<int>>>& dp, int start, int m, int n, int size, vector<string>& strs){

//         if(start>= size || m<0 || n<0)return 0;
//         if(m ==0 && n == 0 )return 0 ; 
//         if(dp[start][m][n]!= -1 )return dp[start][m][n];
//         int res = 0 ;
//         int i = start; 
//         int ones = count(strs[i].begin(), strs[i].end(), '1'); 
//         int zeros = strs[i].size() -ones;
//         if(m-zeros>=0 && n-ones >=0) res = max(1+memo(dp,i+1,m-zeros, n-ones,size, strs),memo(dp,i+1,m, n,size, strs));
//         else res = memo(dp,i+1,m, n,size, strs); 
  
//         return dp[start][m][n] = res; 
//     }
    
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1,vector<int>(n+1,-1)));
//         return memo(dp, 0, m,n, strs.size(), strs); 
//     }

int solve(vector<string>& strs , int m , int n , vector<vector<vector<int>>>& dp , int index)
{
    if(index < 0 || m < 0 || n < 0)
        return 0;
    if(m == 0 && n == 0)
        return 0;
    
    if(dp[index][m][n] != -1)
        return dp[index][m][n];
    
    int z = count(strs[index].begin() , strs[index].end() , '0');
        int o = strs[index].size() - z;
    
        int take = INT_MIN;
        if((m - z) >= 0 && (n - o) >= 0)
            take = 1 + solve(strs , m - z, n - o, dp , index - 1);
        int notTake = solve(strs , m , n , dp , index - 1);
        return dp[index][m][n] = max(take , notTake);
    
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m + 1 , vector<int>(n + 1 , -1)));
        return solve(strs , m , n , dp , sz - 1);
    }
};
