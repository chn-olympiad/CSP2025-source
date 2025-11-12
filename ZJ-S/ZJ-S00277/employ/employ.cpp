#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,an,vis[20],a[550],mod=998244353;
vector<int> v;
string s;
void dfs(){
	ll i;
	if(v.size()==n){
		ll x=0;
		for(i=0;i<n;i++){
			if(s[i]=='1'&&i-x<a[v[i]]) x++;
		}
		if(x>=m) an++;
		return;
	}
	for(i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			v.push_back(i);
			dfs();
			v.pop_back();
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	ll i;
	for(i=1;i<=n;i++) cin>>a[i];
	dfs();
	cout<<an;
	return 0;
}