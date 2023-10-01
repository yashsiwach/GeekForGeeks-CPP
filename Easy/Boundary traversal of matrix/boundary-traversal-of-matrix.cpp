//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m) {
    int i = 0, j = 0;
    vector<int> ans;
    if(n==1) 
    {
        for(auto i:matrix[0]) ans.push_back(i);
        return ans;
    }
    if(m==1) 
    {
        for(int i=0;i<n;i++)ans.push_back(matrix[i][0]);
        return ans;
    }
    while (j < m - 1) {
        ans.push_back(matrix[i][j++]);
    }

    while (i < n - 1) {
        ans.push_back(matrix[i++][j]);
    }

    while (j > 0) {
        ans.push_back(matrix[i][j--]);
    }

    while (i > 0) {
        ans.push_back(matrix[i--][j]);
    }

    return ans;
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends