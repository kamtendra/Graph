#include<bits/stdc++.h>
#define ll long long  
using namespace std;
bool vis[501][501];
void dfs(vector<string>& g, ll i,ll j,ll n, ll m){
    if (g[i][j]!='.' || vis[i][j]) return;
    if((g[i-1][j]=='.' && g[i+1][j]=='#' && g[i][j-1]=='#' && g[i][j+1]=='#')||(g[i-1][j]=='#' && g[i+1][j]=='.' && g[i][j-1]=='#' && g[i][j+1]=='#')||(g[i-1][j]=='#' && g[i+1][j]=='#' && g[i][j-1]=='.' && g[i][j+1]=='#')||(g[i-1][j]=='#' && g[i+1][j]=='#' && g[i][j-1]=='#' && g[i][j+1]=='.'))
        g[i][j]='X'; 
    vis[i][j]=true;
    dfs(g,i+1,j,n,m);
    dfs(g,i,j+1,n,m);
    dfs(g,i-1,j,n,m);
    dfs(g,i,j-1,n,m);
}
 
int main(){  
    ll n,m;
    cin>>n>>m;
    vector<string> g;
    string yo="";
    for(int i=0;i<m;i++)yo+='#';
    g.push_back(yo);
    for(ll i=0;i<n;i++){
        string x;
        cin>>x;
        x='#'+x+'#';
        g.push_back(x);
    }
    g.push_back(yo);
    dfs(g,1,1,n,m);
    for(auto ele:g)cout<<ele<<endl;
}
