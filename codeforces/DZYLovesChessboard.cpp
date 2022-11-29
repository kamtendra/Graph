#include<bits/stdc++.h>
#define ll long long  
using namespace std;

void yo(vector<string>& chess, int i,int j, int n, int m){
     if(i<0 || j<0 || i>n-1 || j>m-1 || chess[i][j]!='.') return;
     if((i+j)%2)chess[i][j]='B';
     else chess[i][j]='W';
     yo(chess,i+1,j,n,m);
     yo(chess,i,j+1,n,m);
     yo(chess,i-1,j,n,m);
     yo(chess,i,j-1,n,m);
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<string>chess;
    for(int i=0;i<n;i++){
            string s;
            cin>>s;
            chess.push_back(s);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(chess[i][j]=='.')yo(chess,i,j,n,m);
        }
    }
    for(auto x:chess)cout<<x<<endl;
}