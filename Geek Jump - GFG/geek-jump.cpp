//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int ans = 0;
        vector<int> dp(n , 10000000);
        dp[0] = 0;
        for(int i = 1 ; i < n ;i++)
        {
            for(int j = max(i - 2 , 0) ; j < i ;j++)
            {
                dp[i] = min(dp[i] , dp[j] + abs(height[i] - height[j]));
            }
            // cout<<dp[i]<<" ";
        }
        return dp[n - 1];
        // Code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends