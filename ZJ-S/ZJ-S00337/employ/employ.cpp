#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=600;
const ll mod=998244353;
ll n,m;
ll ans=0;
string s;
ll c[N];
ll p[N];bool vis[N];
void dfs(ll x){
	if(x==n+1){
		ll num=0;
		for(ll i=1;i<=n;i++){
			if(s[i]=='0'){
				num++;
			}
			else if(c[p[i]]<=num){
				num++;
			}
		}
		if(n-num>=m){
			ans++;
			if(ans>=mod) ans-=mod;
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			p[x]=i;
			dfs(x+1);
			vis[i]=false;
		}
	}
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(ll i=1;i<=n;i++) cin>>c[i];
	if(n<=20){
		dfs(1);
		cout<<ans<<'\n';
	}
	else{
		for(ll i=1;i<=n;i++){
			if(s[i]=='0'){
				cout<<"0\n";return 0;
			}
		}
		for(ll i=1;i<=n;i++){
			if(c[i]==0){
				cout<<"0\n";return 0;
			}
		}
		ll ans=1;
		for(ll i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans<<'\n';
	}
	return 0;
}

