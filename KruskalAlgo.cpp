#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionByRank(int u, int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v)return;
            if(size[ulp_u]>size[ulp_v])parent[ulp_v]=ulp_u;
            else if(size[ulp_u]<size[ulp_v])parent[ulp_u]=ulp_v;
            else {
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }         
        }
        void unionBySize(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v)return;
            if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else{
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }      
        }
};

int main() {
    int n,e;
    cin>>n>>e;
    vector<pair<int,pair<int,int>>>edges(e);
    for(int i=0;i<e;i++){
        int v,u,w;
        cin>>v>>u>>w;
        edges.push_back({w,{u,v}});
    }
    DisjointSet ds(n);
    sort(edges.begin(),edges.end());
    int weight=0;
    for(auto i:edges){
        if(ds.findUPar(i.second.first)!=ds.findUPar(i.second.second)){
            weight+=i.first;
            ds.unionBySize(i.second.first,i.second.second);
        }
    }
    cout<<weight;
}