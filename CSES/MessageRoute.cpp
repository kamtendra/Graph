#include<bits/stdc++.h>
#define ll long long  
using namespace std;

vector<ll>level(100005,0);
ll vis[100005] = {0};
vector<ll>path;
vector<ll>parent(100005);

void bfs(vector<vector<ll>>& g){
    queue<ll>q;
    q.push(1);
    level[1]=1;
    vis[1]=1;
    while(!q.empty()){
           ll yo=q.front();
           q.pop();
           for(auto x:g[yo]){
                if(vis[x]!=1){
                	q.push(x);
                	parent[x]=yo;
                    level[x]=level[yo]+1;
                    vis[x]=1;
                }
            }
        }
    }

int main(){  
    ll n,e;
    cin>>n>>e;
    vector<vector<ll>>g(n+1);
    for(ll i=0;i<e;i++){
        ll v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bfs(g);
    if(n==1)cout<<1;
    else if(!level[n])cout<<"IMPOSSIBLE";
    else{
        ll u=n;
        cout<<level[n]<<endl;
        vector<ll>ans(level[n]+1);
        for(ll i=level[n];i>=1;i--){
            ans[i]=u;
            u=parent[u];
        }
        for(ll i=1;i<=level[n];i++){
            cout<<ans[i]<<" ";}
    }
}