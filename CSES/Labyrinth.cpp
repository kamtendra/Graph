#include<bits/stdc++.h>
#define ll long long  
using namespace std;

vector<pair<ll,ll>>moves={{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(vector<string>g, ll x, ll y, ll n, ll m){
    return (x>=0 && y>=0 && x<n && y<m && g[x][y]!='#');
} 

int main(){  
    ll n,m;
    cin>>n>>m;
    vector<string> g;
    vector<vector<int>>yo(n,vector<int>(m,0));
    string stepDir = "URDL";
    for(ll i=0;i<n;i++){
        string x;
        cin>>x;
        g.push_back(x);
    }
    // for(auto pp:g)cout<<pp<<endl;
    pair<ll,ll>a,b;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(g[i][j]=='A')a={i,j};
            if(g[i][j]=='B')b={i,j};
        }
    }
    string direction="";
    queue<pair<ll,ll>>q;
    q.push(a);
    g[a.first][a.second]='#';
    while(!q.empty()){
        pair<ll,ll>f=q.front();
        if(f==b)break;
        q.pop();
        for(ll i=0;i<4;i++){
            ll ax=f.first+moves[i].first;
            ll by=f.second+moves[i].second;
            if(isValid(g,ax,by,n,m)){
                q.push({ax,by});
                yo[ax][by]=yo[f.first][f.second]+1;
                g[ax][by]='#';
            }
        }
    }
    for(auto k:yo){
        for(auto l:k)cout<<l<<" ";
        cout<<endl;
    }
    for(auto pp:g)cout<<pp<<endl;
    if(yo[b.first][b.second]==0)cout<<"NO";
    else{
        cout<<"YES"<<endl;
        cout<<yo[b.first][b.second]<<endl; 
		cout << endl;
    }
}
