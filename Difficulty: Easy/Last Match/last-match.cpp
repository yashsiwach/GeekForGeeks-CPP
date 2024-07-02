//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
vector<int> solve(string s)
{
    vector<int>v(s.size(),0);
    for(int i=1;i<s.size();i++)
    {
        int j=v[i-1];
        while(j>0&&s[i]!=s[j])
        {
            j=v[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        v[i]=j;
    }
    return v;
}
    int findLastOccurence(string a,string b){
        //Code Here
        vector<int>v;
        vector<int>lps=solve(b);
        int i=0,j=0;
        while(i<a.size())
        {
            if(a[i]==b[j])
            {
                i++;j++;
            }
            if(j==b.size())
            {
                v.push_back(i-b.size()+1);
                j=lps[j-1];
            }
            else if(a[i]!=b[j])
            {
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        if(v.size()==0)return -1;
        else return v.back();
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends