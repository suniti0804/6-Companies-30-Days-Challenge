#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) 
    {
        if(n<=2)
          return n;
        int ans=0;
        vector<unordered_map<int, int>> t(n);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int diff=A[i]-A[j];
                if(t[j].count(diff)>0)
                   t[i][diff]=t[j][diff]+1;
                else
                  t[i][diff]=2;
                  
                ans=max(ans, t[i][diff]);  
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends