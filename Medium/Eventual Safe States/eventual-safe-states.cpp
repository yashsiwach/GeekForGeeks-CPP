//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
bool dfs(vector<bool>& visi, vector<bool>& path, vector<bool>& check, vector<int> adj[], int node) {
    visi[node] = true;
    path[node] = true;
    check[node] = false;
    for (auto it : adj[node]) {
        if (!visi[it]) {  // Corrected the condition here
            if (dfs(visi, path, check, adj, it)) {
                check[node] = false;
                return true;
            }
        } else {
            if (path[it]) {  // Corrected the condition here
                check[node] = false;
                return true;
            }
        }
    }
    check[node] = true;
    path[node] = false;  // Changed path[node] to false
    return false;
}

vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
    vector<bool> visi(n);
    vector<bool> path(n);
    vector<bool> check(n);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!visi[i]) {
            dfs(visi, path, check, adj, i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i]) {  // Push the node index if check[node] is true
            ans.push_back(i);
        }
    }
    return ans;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends