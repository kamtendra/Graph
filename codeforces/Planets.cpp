#include<bits/stdc++.h>
#define ll long long  
using namespace std;
int main(){  
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>g(n+1);
    for(ll i=0;i<m;i++){
        ll v1,v2,d;
        cin>>v1>>v2>>d;
        g[v1].push_back({v2,d});
        g[v2].push_back({v1,d});
    }
    set<pair<ll,ll>>st;
    vector<ll>dist(n+1,LLONG_MAX);
    vector<ll>parent(n+1);
    dist[1]=0;
    parent[1]=0;
    st.insert({dist[1],1});
    while(!st.empty()){
        auto it = *(st.begin());
        ll edge = it.second;
        ll distance = it.first;
        st.erase(it);
        for(auto x:g[edge]){
            if(x.second+distance<dist[x.first]){
                if(dist[x.first]!=LLONG_MAX)st.erase({dist[x.first],x.first});
                dist[x.first]=x.second+distance;
                parent[x.first]=edge;
                st.insert({dist[x.first],x.first});
            }
        }
    }
    if(dist[n]==LLONG_MAX)cout<<-1;
    else{
        vector<ll>ans;
        ll x=n;
        while(x!=0){
            ans.push_back(x);
            x=parent[x];
        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans)cout<<i<<" ";
    }
}