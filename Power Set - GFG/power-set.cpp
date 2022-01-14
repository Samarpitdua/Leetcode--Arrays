// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n = s.size();
		    vector<string> ans;
		    for(int  i = 0 ; i < (1<<n) ; i++)
		    {
		        string temp = "";
		        for(int j = 0 ;j <= (n-1) ;j++)
		        {
		            if((i & (1<<j))!=0)
		                temp += s[j];
		        }
		        ans.push_back(temp);
		    }
		    sort(ans.begin() , ans.end());
		    ans.erase(ans.begin());
		    return ans;
		    // Code here
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends