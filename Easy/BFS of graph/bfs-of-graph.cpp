//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void solve(int node,vector<int>adj[],vector<int>&ans,vector<bool>&visi)
  {
      queue<int>q;
      q.push(node);

     visi[node]=true;
      while(!q.empty())
      {
          int fr=q.front();
          q.pop();
          ans.push_back(fr);
          for(auto it:adj[fr])
          {
              if(!visi[it]){
              visi[it]=true;
              q.push(it);
              }
          }
      }
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>visi(n,0);
        solve(0,adj,ans,visi);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends