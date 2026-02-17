#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1'000'000'007;

int differ_bit_count(vector<int>& arr){
    int n=arr.size();
    ll ans=0,active=0,prod=0;
    for(int i=0;i<31;i++){
        active=0;
        
        for(int j=0;j<n;j++){
            if(arr[j] & (1<<i))
                active++;
        }
        prod=(active*(n-active))%mod;
        ans=(ans+prod)%mod;
    }
    return (ans*2)%mod;
}

int main() {
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  cout<<differ_bit_count(v);   
return 0;
}
