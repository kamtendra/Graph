#include<bits/stdc++.h>
#define ll long long  
using namespace std;
 
void dfs(vector<string>& g, ll i,ll j,ll n, ll m){
    if (i<0 || j<0 || i>n-1 || j>m-1 || g[i][j]=='#') return;
    g[i][j]='#';
    dfs(g,i+1,j,n,m);
    dfs(g,i,j+1,n,m);
    dfs(g,i-1,j,n,m);
    dfs(g,i,j-1,n,m);
}
 
int main(){  
    ll n,m;
    cin>>n>>m;
    vector<string> g;
    for(ll i=0;i<n;i++){
        string x;
        cin>>x;
        g.push_back(x);
    }
    ll c=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(g[i][j]=='.'){
                dfs(g,i,j,n,m);
                c++;
            }
        }
    }
    cout<<c;
}
