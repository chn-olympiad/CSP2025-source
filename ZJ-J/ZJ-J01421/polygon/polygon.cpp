#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=5e3+10,M=1e2+10,MOD=998244353;
ll n,ans,a[N],b[N],mp[N],c[N],C[N][N];
void dfs(ll x,ll maxx,ll sum=0ll,ll cnt=1ll,ll num=0ll){
	if(x==0){
		if(num<3) return;
		if(sum>maxx*2) ans=(ans+cnt)%MOD;
		return;
	}
	if(b[x]+sum<=maxx*2) return;
	if(sum>maxx*2&&num>=3){
		ans=(ans+((c[x]*cnt)%MOD))%MOD;
		return;
	}
	for(int i=0;i<=mp[a[x]];i++){
		if(a[x]==maxx&&i==0) continue;
		dfs(x-1,maxx,sum+i*a[x],(cnt*C[mp[a[x]]][i])%MOD,num+i);
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	C[0][0]=1ll;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i+1]=1ll;
		for(int j=1;j<=i;j++){
			if(i!=j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
			else C[i][j]=1ll;
			C[i][i+1]=(C[i][i+1]+C[i][j])%MOD;
		}
	}
	sort(a+1,a+1+n);
	ll idx=a[3];
	ll m=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=m;i++) b[i]=(b[i-1]+(a[i]*mp[a[i]])%MOD)%MOD;
	c[0]=1ll;
	for(int i=1;i<=m;i++) c[i]=(c[i-1]*C[mp[a[i]]][mp[a[i]]+1])%MOD;
	idx=lower_bound(a+1,a+1+m,idx)-a;
	for(int i=idx;i<=m;i++) dfs(i,a[i]);
	cout<<ans;
}
int main(){
	IOS;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
