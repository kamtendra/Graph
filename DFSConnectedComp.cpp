#include<bits/stdc++.h>
#define ll long long  
using namespace std;
const ll N= 1e5+10;

bool vis[N];
vector<ll> g[N];

void dfs(ll vertex){
    vis[vertex] =true;
    for(ll child: g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
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
    ll c=0;
    for(ll i=1;i<n+1;i++){
            if(!vis[i]){
                dfs(i);
                c++;
            }
    }
    cout<<c;
}