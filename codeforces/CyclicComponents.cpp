#include<bits/stdc++.h>
#define ll long long  
using namespace std;
int main(){  
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vector<string>a,b,c;
    map<string,ll>y;
    for(ll i=0;i<n;i++){
        string s1,s2,s3;
        cin>>s1;
        cin>>s2;
        cin>>s3;
        a.push_back(s1);
        b.push_back(s2);
        c.push_back(s3);
        y[s1]++;
        y[s2]++;
        y[s3]++;
    }
    ll p1=0,p2=0,p3=0;
    for(ll i=0;i<n;i++){
        cout<<y[a[i]]<<endl;
        if(y[a[i]]==1)p1+=3;
        else if(y[a[i]]==2)p1+=1;
        if(y[b[i]]==1)p2+=3;
        else if(y[b[i]]==2)p2+=1;
        if(y[c[i]]==1)p3+=3;
        else if(y[c[i]]==2)p3+=1;
    }
    cout<<p1<<" "<<p2<<" "<<" "<<p3<<endl;
    }
}