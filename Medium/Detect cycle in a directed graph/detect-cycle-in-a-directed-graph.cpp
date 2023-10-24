//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(vector<int>adj[],vector<bool>&visi,vector<bool>&pathvisi,int node)
  {
      visi[node]=true;
      pathvisi[node]=true;
      for(auto it:adj[node])
      {
          if(!visi[it])
          {
              if(dfs(adj,visi,pathvisi,it))return true;
          }
          else if(pathvisi[it])return true;
      }
      pathvisi[node]=false;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        vector<bool>visi(n);
        vector<bool>pathvisi(n);
        for(int i=0;i<n;i++)
        {
            if(!visi[i])
            {
                if(dfs(adj,visi,pathvisi,i))return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends