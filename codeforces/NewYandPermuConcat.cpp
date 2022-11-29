#include<bits/stdc++.h>
#define ll long long  
using namespace std;

int main(){  
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll sum=0;
    sum = accumulate(a.begin(), a.end(), 0);
    vector<vector<int>>dp(n+1,vector<int>(sum/2+1,0));
    for(ll i=0;i<=a.size();i++){
        for(ll j=0;j<=sum;j++){
             if(j==0)dp[i][j]=1;
                else if(i==0)dp[i][j]=0;
                else{ 
                    dp[i][j]|=dp[i-1][j];
                    if(j-a[i-1]>=0)
                        dp[i][j]|=dp[i-1][j-a[i-1]];
                }
        }
    }
    if(dp[n][sum/2])cout<<"YES";
    else cout<<"NO";
}
