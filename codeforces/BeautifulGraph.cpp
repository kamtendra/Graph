#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  string s;
  string t="Timur";
  cin>>s;
  sort(t.begin(),t.end());
  sort(s.begin(),s.end());
  if(t==s)cout<<"YES\n";
  else cout<<"NO\n";
 }
 return 0;
}