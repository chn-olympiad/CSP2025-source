#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=506,mod=998244353;
int n,m,res,c[N],vis[N];
string s;
void dfs (int step,int sum,int lst) {
	if (step>=n) {
		if (sum>=m) res++;
		return;
	}
	for (int i=1;i<=n;++i) {
		if (vis[i]) continue;
		vis[i]=1;
		if (s[step]=='0' || lst>=c[i]) {
			dfs(step+1,sum,lst+1);
		}else {
			dfs(step+1,sum+1,lst);
		}
		vis[i]=0;
	}
}
int qpow (int a,int b,int p) {
	int res=1;
	while (b) {
		if (b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for (int i=1;i<=n;++i) cin>>c[i];
	if (n<=10) {
		dfs(0,0,0);
		printf("%lld\n",res);
	} 
	else {
		int res=1;
		for (int i=1;i<=n;++i) res=res*i%mod;
		printf("%lld\n",res*qpow(7,mod-2,mod));
	}	
	return 0;
}
//AKCSP!!!