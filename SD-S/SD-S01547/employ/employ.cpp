#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[505],mod=998244353,fac[505],used[505];
string s;
ll dfs(ll k,ll ans,ll lo){
	if(ans>=m){
		return fac[n-k+1];
	}
	if(ans+(n-k+1)<m)return 0;
	if(k==n+1)return 0;
	ll res=0;
	for(ll i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=1;
		if(s[k-1]=='0'||lo>=a[i]){
			res+=dfs(k+1,ans,lo+1);
		}
		else res+=dfs(k+1,ans+1,lo);
		res%=mod;
		used[i]=0;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	ll t=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(s[i-1]=='0')t=0;
	}
	fac[0]=1;
	for(ll i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	if(t){
		cout<<fac[n];
		return 0;
	}
	cout<<dfs(1,0,0);
	return 0;
}/*

*/

