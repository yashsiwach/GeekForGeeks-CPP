//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
void dfs(vector<vector<int>>& ans, vector<vector<bool>>& visi, int n, int m, int i, int j, vector<int>& v1, vector<int>& v2)
{
    visi[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int nrow = i + v1[k];
        int ncol = j + v2[k];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == 1 && !visi[nrow][ncol])
        {
            visi[nrow][ncol] = true;
            dfs(ans, visi, n, m, nrow, ncol, v1, v2);
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    vector<vector<int>> ans = grid;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visi(n, vector<bool>(m, false));
    vector<int> v1 = {-1, 0, 1, 0};
    vector<int> v2 = {0, 1, 0, -1};
    
    for (int i = 0; i < n; i++) {  // Changed the loop to iterate over rows.
        if (ans[i][0] == 1 && !visi[i][0]) {
            dfs(ans, visi, n, m, i, 0, v1, v2);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (ans[i][m-1] == 1 && !visi[i][m-1]) {
            dfs(ans, visi, n, m, i, m-1, v1, v2);
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (ans[0][i] == 1 && !visi[0][i]) {
            dfs(ans, visi, n, m, 0, i, v1, v2);
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (ans[n-1][i] == 1 && !visi[n-1][i]) {
            dfs(ans, visi, n, m, n-1, i, v1, v2);
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 1 && !visi[i][j]) {
                count++;
            }
        }
    }
    
    return count;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends