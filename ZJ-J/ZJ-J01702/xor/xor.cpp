#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=5e5+10,M=2e6+10,mod=1e9+7;
const double eps=1e-1;
const long double pi=acos(-1);
int n,k,a[N],pre[N],dp[N],lst[M],vis[M];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
	vis[0]=1;
	for(int i=1;i<=n;i++){
		if(!vis[pre[i]^k])dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[lst[pre[i]^k]]+1);
		lst[pre[i]]=i;
		vis[pre[i]]=1;
	}
	cout<<dp[n]<<endl;
	return 0;
}
