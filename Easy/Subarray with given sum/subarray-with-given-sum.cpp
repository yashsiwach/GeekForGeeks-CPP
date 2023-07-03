//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
  vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        vector<int> result;
        long long sum = 0;
        int start = 0, end = 0;
        if(s == 0)
        {
            result.push_back(-1);
            return result;
        }
        while (end < n)
        {
            sum += arr[end];
    
            while (sum > s)
            {
                sum -= arr[start];
                start++;
            }
    
            if (sum == s)
            {
                result.push_back(start + 1);
                result.push_back(end + 1);
                return result;
            }
    
            end++;
        }
        result.push_back(-1);
        return result;
    }


};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends