//bipartite coloring good question
#include<bits/stdc++.h>
#define ll long long  
using namespace std;
const ll N= 2e5+5;
vector<ll> color(N,-1);
bool dfs(vector<vector<ll>>& graph,ll vertex){
        if(color[vertex]==-1)color[vertex]=1;
        for(auto child:graph[vertex]){
            if(color[child]==-1){
                color[child]=!color[vertex];
                if(!dfs(graph,child))return false;
            }
            else if(color[child]==color[vertex])return false;
        }
        return true;
    }
    
bool isBipartite(vector<vector<ll>>& graph) {
        ll n=graph.size();
        for(ll i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(graph,i))
                    return false;
            }
        }
        return true;
}

int main(){  
    ll n,e;
    cin>>n>>e;
    vector<vector<ll>>g(n);
    map<pair<ll,ll>,ll>m;
    for(ll i=0;i<e;i++){
        ll v1,v2;
        cin>>v1>>v2;
        m[{v1-1,v2-1}]++;
        if((m[{v1-1,v2-1}]+m[{v2-1,v1-1}])%2){
        cout<<m[{v1-1,v2-1}]<<" "<<m[{v2-1,v1-1}]<<endl;
        g[v1-1].push_back(v2-1);
        g[v2-1].push_back(v1-1);
        }
        if(!isBipartite(g))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}