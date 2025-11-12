#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll a[5005], b[25], cnt, qz[5005];
ll f[5005][5005][2];
ll jc[5005];
ll maxn, ans;
int n;
ll qpow(ll x, ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll C(ll num, ll x){
	return jc[num]*qpow(jc[num-x],mod-2)%mod*qpow(jc[x],mod-2)%mod;
}
bool vis[25];
bool check(){
	ll sum=0;
	for(int i=1; i<=cnt; i++) sum+=b[i];
	if(sum>2*b[cnt]) return 1;
	else return 0;
}
void dfs(int x){
	if(x==n+1){
		if(check()) ans++;
		return;
	}
	vis[x]=1;
	b[++cnt]=a[x];
	dfs(x+1);
	vis[x]=0;
	cnt--;
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1; i<=n; i++) 
		scanf("%lld",&a[i]), maxn=max(maxn,a[i]), qz[i]=qz[i-1]+a[i];
	sort(a+1,a+1+n);
	jc[0]=1;
	for(int i=1; i<=n; i++) jc[i]=jc[i-1]*i%mod;
	if(n<=2){
		cout<<0; return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxn) cout<<1;
		else cout<<0;
		return 0;
	}
	if(maxn==1){
		for(int i=3; i<=n; i++){
			ans=(ans+C(n,i))%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(a[1]+a[2]>a[3]) f[3][3][1]=1;
	for(int i=4; i<=n; i++){
		if(qz[i-1]>a[i]) f[i][i][1]=1;
		for(int j=i-1; j>=3; j--){
			f[i][j][0]=(f[i-1][j][1]+f[i-1][j][0])%mod;
			f[i][j][1]=(f[i-1][j-1][1]+f[i-1][j-1][0])%mod;
		}
	}
	for(int i=3; i<=n; i++){
	     ans=(ans+f[n][i][0]+f[n][i][1])%mod;
	}
	cout<<ans;
	return 0;
}