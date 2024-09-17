//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
       vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i = 1; i < n; i++) {
        dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends