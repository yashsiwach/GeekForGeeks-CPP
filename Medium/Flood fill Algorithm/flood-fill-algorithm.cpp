//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void solve(vector<vector<int>>&temp,vector<vector<int>>&image,int sr,int sc,int newcolor,int inicolor,vector<int>&v1,vector<int>&v2)
{
    temp[sr][sc]=newcolor;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++)
    {
        int nrow=sr+v1[i];
        int ncol=sc+v2[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&temp[nrow][ncol]!=newcolor&&image[nrow][ncol]==inicolor)
        {
            solve(temp,image,nrow,ncol,newcolor,inicolor,v1,v2);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>temp=image;
        vector<int>v1={-1,0,1,0};
        vector<int>v2={0,+1,0,-1};
        int inicolor=image[sr][sc];
        solve(temp,image,sr,sc,newColor,inicolor,v1,v2);
        return temp;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends