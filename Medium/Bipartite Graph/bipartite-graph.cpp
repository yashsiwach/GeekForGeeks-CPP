//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool isBipartite(int n, vector<int> adj[]) {
    vector<int> visi(n, -1);
    
    for (int i = 0; i < n; i++) {
        if (visi[i] == -1 && !solve(adj, visi, i)) {
            return false;
        }
    }
    
    return true;
}

bool solve(vector<int> adj[], vector<int>& visi, int node) {
    queue<int> q;
    q.push(node);
    visi[node] = 1;

    while (!q.empty()) {
        int fr = q.front();
        q.pop();

        for (auto it : adj[fr]) {
            if (visi[it] == -1) {
                visi[it] = 1 - visi[fr];
                q.push(it);
            } else if (visi[it] == visi[fr]) {
                return false;
            }
        }
    }
    
    return true;
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends