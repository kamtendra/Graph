#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll spanningTree(ll V, vector<vector<pair<int,int>>>& adj, vector<ll>& vis){
        priority_queue<pair<ll,ll>,
        vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        ll summ=0;
        while(!pq.empty()){
            auto f=pq.top();
            pq.pop();
            ll node=f.second;
            ll w=f.first;
            if(vis[node]==1)continue;
            vis[node]=1;
            summ+=w;
            for(auto i:adj[node]){
                ll adjn=i.first;
                ll adjw=i.second;
                if(!vis[adjn])pq.push({adjw,adjn});
            }
        }
        return summ;
}
int main(){  
    ll n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>>adj(n);
    vector<ll>vis(n,0);
    for(ll i=0;i<e;++i){
        ll v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].push_back({v2,w});
        adj[v2].push_back({v1,w});
    }
    cout<<spanningTree(n,adj,vis);
}