//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
   vector<int> solve(string s) {
    vector<int> v(s.size(), 0);
    for(int i = 1; i < s.size(); i++) {
        int j = v[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = v[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        v[i] = j;
    }
    return v;
}

       vector<int> search(string pat, string txt) {
    vector<int> v;
    vector<int> lps = solve(pat);
    int i = 0, j = 0;
    
    while(i < txt.size()) {
        if(pat[j] == txt[i]) {
            i++;
            j++;
        }
        
        if(j == pat.size()) {
            v.push_back(i - j + 1); // Record the match position
            j = lps[j - 1];
        } else if(i < txt.size() && pat[j] != txt[i]) {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    if(v.size() == 0) {
        v.push_back(-1);
    }
    return v;
}

     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends