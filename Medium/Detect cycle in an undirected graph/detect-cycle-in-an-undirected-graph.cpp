//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool bfsCycle( vector<int> adj[] , vector<bool>&visited ,  vector<int>&parent,int node){
        visited[node] = true ;
        parent[node] = -1 ;
        
        queue<int>q ;
        q.push(node) ;
        
        while(!q.empty()){
            int front = q.front() ;
            q.pop() ;
            
            for( auto neighbour : adj[front]){
                if(!visited[neighbour]){
                    visited[neighbour]= true ;
                    parent[neighbour] = front ;
                    q.push(neighbour) ;
                }
                
                else if(parent[front] != neighbour){
                    return true ;
                }
            }
        }
        return false ;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool>visited(V ,0) ;
        vector<int>parent(V , 0) ;
        for(int i = 0 ;i < V ;i++){
            if(!visited[i]){
                // int ans = dfsCycle(adj , visited , i , -1) ;
                bool ans = bfsCycle(adj , visited , parent ,i) ;
                if(ans){
                    return true ;
                }
            }
        }
        
        return false ;
    }
   
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends