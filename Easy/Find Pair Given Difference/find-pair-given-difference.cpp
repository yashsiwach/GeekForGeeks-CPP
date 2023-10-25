//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int B) {
    sort(arr,arr+size);
    int i=0,j=1;
    if(B<0)B=B*-1;
    while(j<size)
    {
        if(arr[j]-arr[i]==B)return 1;
        else if(arr[j]-arr[i]<B)j++;
        else if(arr[j]-arr[i]>B)i++;
        if(i==j)j++;
    }
    return 0;
}

