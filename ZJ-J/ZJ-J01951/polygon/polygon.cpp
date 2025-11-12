//TLE 60 pts
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[5005],maxn,c[5005][5005];
ll ans;
void dfs(int t,int c,int sum,int p){
	if(t>n){
		if(sum==0||c<3) return;
		if(sum>2*p) ans=(ans+1)%mod;
		return;
	}
	dfs(t+1,c+1,sum+a[t],max(p,a[t]));
	dfs(t+1,c,sum,p);
}
void init(){
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+n+1);
	init();
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans<<'\n';
	}else{
		if(a[1]+a[2]+a[3]>2*maxn){
			for(int i=3;i<=n;i++) ans=(ans+c[n][i])%mod;
			cout<<(ans+mod)%mod<<'\n';
		}else{
			dfs(1,0,0,0);
			cout<<ans<<'\n';
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
