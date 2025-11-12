#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll mod=998244353;
ll n,m,ans;
char s[501];
ll c[501];
ll f;
ll a[501];
ll vis[501];
void init(){
	a[0]=1;
	for(ll i=1;i<=500;++i){
		a[i]=a[i-1]*i;
		a[i]%=mod;
	}
}
void dfs(ll d,ll g){
	if(g==m){
		ans+=a[n-d+1];
		ans%=mod;
		return ;
	}
	if(g+n-d+1<m) return ;
	if(d>n) return ;
	for(ll i=1;i<=n;++i){
		if(vis[i]!=0) continue;
		vis[i]=d;
		if(s[d]=='0'||d-g-1>=c[i]) dfs(d+1,g);
		else dfs(d+1,g+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>s[i];
		if(s[i]=='1') f++;
	}	
	for(ll i=1;i<=n;++i){
		cin>>c[i];
	}
	if(f<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
