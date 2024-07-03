//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(vector<bool>&visi,unordered_map<int,vector<int>>&mp,int node)
{
    visi[node]=1;
    for(auto &it:mp[node])
    {
        if(!visi[it])
        {
            dfs(visi,mp,it);
        }
    }
}
    int numProvinces(vector<vector<int>> v, int V) {
        // code here
        unordered_map<int,vector<int>>mp;
        vector<bool>visi(v.size());
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    mp[i+1].push_back(j+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(!visi[i])
            {
                count++;
                dfs(visi,mp,i);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends