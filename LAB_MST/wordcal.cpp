#include <bits/stdc++.h>
using namespace std;

int main()
{
    string words[6]={"abcw","foo","bar","baz","xyz","xyz"};
    int n=6;
    
   
    int mask[n];
    
    
    for(int i = 0; i < n; i++)
    {
        mask[i] = 0;  
        
        
        for(char c : words[i])
        {
            
            mask[i] |= (1 << (c - 'a'));
        }
    }
    
    int prod=1;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            if((mask[i]&mask[j])==0)
            {
                prod=words[i].size()*words[j].size();
                ans=max(ans,prod);
            }
        }
    }
    cout<<ans;
    return 0;
}

