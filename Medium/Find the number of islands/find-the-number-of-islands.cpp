//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
void bfs(int i, int j, vector<vector<bool>>& visi, vector<vector<char>>& grid) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visi[i][j] = true;
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty()) {
        pair<int, int> fr = q.front();
        q.pop();
        int row = fr.first;
        int col = fr.second;

        for (int nrow = -1; nrow <= 1; nrow++) {
            for (int ncol = -1; ncol <= 1; ncol++) {
                int ngbrow = row + nrow;
                int ngbcol = col + ncol;
                if (ngbrow >= 0 && ngbrow < n && ngbcol >= 0 && ngbcol < m && grid[ngbrow][ngbcol] == '1') {
                    if (!visi[ngbrow][ngbcol]) {
                        visi[ngbrow][ngbcol] = true;
                        q.push({ngbrow, ngbcol});
                    }
                }
            }
        }
    }
}

// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visi(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visi[i][j] && grid[i][j] == '1') {
                try {
                    count++;
                    bfs(i, j, visi, grid);
                } catch (const std::exception& e) {
                    // Handle the exception
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
        }
    }
    return count;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends