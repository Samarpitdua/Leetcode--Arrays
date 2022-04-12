class Solution {
public:
    // First find nearest smaller to right and then nearest smallest left
    // consider that as a rectangle and apply the formula
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>>st;
        vector<int> v(n) , v2(n) ;
        for(int i = n - 1; i >= 0; i--)
        {
            if(st.empty())
            {
                v[i] = n;
                st.push( { heights[i] , i } );
            }
            else
            {
                while(!st.empty() and st.top().first >= heights[i])
                    st.pop();
                if(st.empty())
                {
                    v[i] = n;
                    st.push( { heights[i] , i } );
                }
                else
                {
                    v[i] = st.top().second;
                    st.push( { heights[i] , i } );
                }
            }
            
        }
        while(!st.empty()) 
            st.pop();
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                v2[i] = -1;
                st.push( { heights[i] , i } );
            }
            else
            {
                while(!st.empty() and st.top().first >= heights[i])
                    st.pop();
                if(st.empty())
                {
                    v2[i] = -1;
                    st.push( { heights[i] , i } );
                }
                else
                {
                    v2[i] = st.top().second;
                    st.push( { heights[i] , i } );
                }
            }
            
        }
        int ans = 0;
        for(int i = 0; i < n ;i++)
        {
            int temp = abs((v[i] - v2[i]) - 1) * heights[i];;
            ans = max(ans , temp);
        }
        return ans;    
    }
};