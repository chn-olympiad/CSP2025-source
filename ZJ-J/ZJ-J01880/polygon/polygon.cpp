#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10;
const ll mod=998244353;
int n,a[N];
ll ans;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void dfs(int u,int maxn,int sm,int cnt){
	if(u>n){
		if(cnt>=3&&maxn*2<sm)ans=(ans+1)%mod;
		return;
	}
	dfs(u+1,maxn,sm,cnt);
	dfs(u+1,max(maxn,a[u]),sm+a[u],cnt+1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int a_max=0;
	for(int i=1;i<=n;i++)a_max=max(a_max,a[i]);
	if(a_max==1){
		ans=qpow(2ll,(ll)n);
		ans=(ans-1-n-n*(n-1)/2+mod)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
