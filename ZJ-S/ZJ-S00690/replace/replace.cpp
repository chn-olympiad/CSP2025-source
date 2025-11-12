#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1159764;

int n,q;
map<string,string>mp;
string s,t;
void solve() {
  cin>>n>>q;
  for(int i = 1;i <=n;i ++){
  	string a,a2;cin>>a>>a2;
  	mp[a]=a2;
  }
  while(q--){
  	cin >>s>>t;
  	map<string,int>vis,tmp;
  	vis[s]++;
  //	for(int ppp=0;ppp<4;ppp++){
	tmp=vis;
  	for(auto i : tmp){
  	  string s1=i.first;
	  int val=i.second;
	  for(int j=0;j<s1.size();j++){
	  	for(auto k:mp){
	  	  string l=k.first,r=k.second;
	  	  int len=l.size();
	  	  string sub=s1.substr(j,len);
	  	  if(sub==l){
	  	  	string s11=s1.substr(0,j);
	  	  	string s12=s1.substr(j+len,s1.size());
	  	  	vis[s11+r+s12]+=val;
		  }
		}
	  }
	}
  //}
    cout<<vis[t]<<"\n";
  }
  return;
  cout<<"CSP-S 2025 rp++!";
}
int main() {
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll T=1;
  while(T--)solve();
  return 0;
}