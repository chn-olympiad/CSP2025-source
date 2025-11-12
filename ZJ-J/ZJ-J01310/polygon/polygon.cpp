#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=30,mod=998244353;

int n;
int a[N];
int mem[N][N*100][N];
int jc[5140];

namespace base1 {
	int ans;

	int dfs(int d,int len,int mxid) {
		if(mem[d][len][mxid]!=-1) return mem[d][len][mxid];
		if(d==n+1) {
			if(len>2*a[mxid]) {
				return mem[d][len][mxid]=1;
			}
			return mem[d][len][mxid]=0;
		}
		mem[d][len][mxid]=(dfs(d+1,len,mxid) + dfs(d+1,len+a[d],d))%mod;
		return mem[d][len][mxid];
	}

	void solve() {
		memset (mem,-1,sizeof(mem));
		sort(a+1,a+1+n);
		cout<<base1::dfs(1,0,0);
	}
}

namespace base2 {

	int quick_pow(int a,int n) {
		if(n==0) return 1;
		if(n==1) return a%mod;
		int t=quick_pow(a,n>>1);
		return t*t%mod*quick_pow(a,n&1)%mod;
	}

	void init() {
		jc[0]=1;
		for(int i=1; i<=n; i++) jc[i]=jc[i-1]*i%mod;
	}

	int C(int i,int j) {
		return jc[i]*quick_pow(jc[j]*jc[i-j]%mod,mod-2)%mod;
	}

	void solve() {
		int ans=0;
		init();
		for(int i=3; i<=n; i++) {
			for(int j=2; j<i; j++) {
				ans+=C(i-1,j);
				ans%=mod;
			}
		}
		cout<<ans;
	}
}

signed main() {
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag) {
		base2::solve();
		return 0;
	} else base1::solve();
}
// DFS niubi!!!

// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF
// I love CCF



//writen by binary_carrot
//luogu uid = 1300065 ?
