//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int solve(string& j,int s,int e)
    {
        int ans=1;
        if(s>=e)
        {
            return ans;
        }
        if(j[s]!=j[e])
        {
            return 0;
        }
        solve(j,s+1,e-1);
    }
	
	
	int isPalindrome(string S)
	{
	    int j=0;
	    int e=S.length()-1;
	    return solve(S,j,e);
	  
	    
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends