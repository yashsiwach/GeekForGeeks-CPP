//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int i=0;
        stack<char>temp;
        if(x.length()==1) {return false;}
        while(i<x.length())
        {
            if(x[i]=='('||x[i]=='{'||x[i]=='[')
            {
                temp.push(x[i]);
                i++;
            }
            else
            {
                if(temp.empty()) return false;
                if ((temp.top() == '(' && x[i] == ')') || (temp.top() == '{' && x[i] == '}') || (temp.top() == '[' && x[i] == ']'))

                {
                    temp.pop();
                    i++;
                }
                else
                {
                    return false;
                }
            }
        }
        if(temp.empty())
        {
            return true;
        }
        else return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends