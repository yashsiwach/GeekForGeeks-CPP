//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    void makeset(int row,int col,vector<vector<int>>&matrix,int i,int j)
    {
        for(int k=0;k<row;k++)
        {
            matrix[k][j]=1;
        }
        for(int k=0;k<col;k++)
        {
            matrix[i][k]=1;
        }
    }
    
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        
        int col=matrix[0].size();
        int row=matrix.size();
        vector<vector<int> >temp(row,vector<int>(col,0));
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(matrix[i][j]==1)
                    {
                        makeset(row,col,temp,i,j);
                    }
                }
            }
        matrix=temp;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends