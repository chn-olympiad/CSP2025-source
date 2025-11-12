#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=5e3+10,M=1+10,mod=998244353;
const double eps=1e-1;
const long double pi=acos(-1);
int n,a[N],dp[N],suf[N],nxt[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	dp[min(a[1],maxx+1)]++;
	dp[min(a[2],maxx+1)]++;
	dp[min(a[1]+a[2],maxx+1)]++;
	for(int i=maxx+1;i>=0;i--)suf[i]=(suf[i+1]+dp[i])%mod;
	int ans=0;
	for(int i=3;i<=n;i++){
		ans=(ans+suf[a[i]+1])%mod;
		for(int j=0;j<=maxx+1;j++)nxt[j]=dp[j];
		for(int j=0;j<=maxx;j++)nxt[min(j+a[i],maxx+1)]=(nxt[min(j+a[i],maxx+1)]+dp[j])%mod;
		nxt[maxx+1]=(nxt[maxx+1]+dp[maxx+1]%mod)%mod;
		for(int j=0;j<=maxx+1;j++)dp[j]=nxt[j];
		for(int j=maxx+1;j>=0;j--)suf[j]=(suf[j+1]+dp[j])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
