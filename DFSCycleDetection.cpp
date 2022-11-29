#include<bits/stdc++.h>
#define ll long long  
using namespace std;
const ll N= 1e5+10;

bool vis[N];
vector<ll> g[N];

bool dfs(ll vertex, ll par){
    vis[vertex]=true;
    for(auto child: g[vertex]){
        if(vis[child] && child==par)continue;
        if(vis[child]) return true;
        dfs(child,vertex);
    }
    return false;
}
int main(){  
    ll n,e;
    cin>>n>>e;
    for(ll i=0;i<e;++i){
        ll v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(int i=1;i<n+1;i++){
        if(vis[i])continue;
        if(dfs(i,0)){
            cout<<"LOOP EXIST";
            return 0;
            }
    } 
    cout<<"LOOP DOES NOT EXIST";
}