//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(vector<vector<char>>& ans, vector<vector<bool>>& visi, int n, int m, int i, int j, vector<int>& v1, vector<int>& v2)
{
    visi[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int nrow = i + v1[k];
        int ncol = j + v2[k];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == 'O' && !visi[nrow][ncol])
        {
            visi[nrow][ncol] = true;
            dfs(ans, visi, n, m, nrow, ncol, v1, v2); // Corrected the parameters here.
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<char>> ans = mat;
    vector<vector<bool>> visi(n, vector<bool>(m, false));
    vector<int> v1 = {-1, 0, 1, 0};
    vector<int> v2 = {0, 1, 0, -1};
    for (int i = 0; i < m; i++)
    {
        if (ans[0][i] == 'O' && !visi[0][i])
        {
            dfs(ans, visi, n, m, 0, i, v1, v2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i][0] == 'O' && !visi[i][0])
        {
            dfs(ans, visi, n, m, i, 0, v1, v2);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (ans[n - 1][i] == 'O' && !visi[n - 1][i])
        {
            dfs(ans, visi, n, m, n - 1, i, v1, v2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i][m - 1] == 'O' && !visi[i][m - 1])
        {
            dfs(ans, visi, n, m, i, m - 1, v1, v2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == 'O' && !visi[i][j])
            {
                ans[i][j] = 'X';
            }
        }
    }
    return ans;
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends