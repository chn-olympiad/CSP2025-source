#include <cstdio>
#include <algorithm>
#include <cassert>
int n,K;
namespace force {
	const int N=16;
	int a[N];
	int ans=0;
	
	int len=0,c=0;
	int f[N];
	void dfs() {
		if (len==n) {
			bool fl=true;
			for (int i=1;i<=n;i++) printf("%d",f[i]);
			puts("");
			for (int i=1;i<=n;i++) {
				int j=i;
				while (j+1<=n && f[j+1]==f[j]) j++;
				if (f[i]) {
					int sum=0;
					for (int k=i;k<=j;k++) sum^=a[k];
					fl&=(sum==K);
				}
				i=j;
			}
			if (fl) ans=std::max(ans,c);
			return;
		}
		f[++len]=++c;
		dfs();
		f[len--]=0;c--;
		
		f[++len]=c;
		dfs();
		f[len--]=0;
		
		f[++len]=0;
		dfs();
		f[len--]=0;
	}
	void solve() {
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		dfs();
		printf("%d\n",ans);
	}
}
namespace better {
	const int N=1007,MAXK=(1<<20)+7;
	int dp[N];
	int a[N];
	int s[N];
	int c[MAXK],pos[N];
	int edp[N];
	void solve() {
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		for (int i=n;i>=1;i--) {
			c[s[i]]=i;
			if (c[K^s[i-1]]) pos[i]=c[K^s[i-1]];
		}
		for (int i=1;i<=n;i++) if (pos[i]) {
			assert(K==s[pos[i]]^s[i-1]);
		}
		dp[n+1]=0;
		edp[n+1]=0;
		for (int i=n;i>=1;i--) if (pos[i]) {
			int maxv=0; 
			for (int j=pos[i]+1;j<=n;j++) {
				maxv=std::max(maxv,dp[j]);
			}
			dp[i]=maxv+1;
			edp[i]=std::max(edp[i+1],dp[i]);
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans=std::max(ans,dp[i]);
		printf("%d\n",ans);
	}
}
namespace best {
	const int N=500007,MAXK=(1<<20)+7;
	int dp[N];
	int a[N];
	int s[N];
	int c[MAXK],pos[N];
	int edp[N];
	void solve() {
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		for (int i=n;i>=1;i--) {
			c[s[i]]=i;
			if (c[K^s[i-1]]) pos[i]=c[K^s[i-1]];
		}
		for (int i=1;i<=n;i++) if (pos[i]) {
			assert(K==s[pos[i]]^s[i-1]);
			assert(pos[i]>=i);
		}
		dp[n+1]=0;
		edp[n+1]=0;
		for (int i=n;i>=1;i--) {
			if (pos[i]){
				dp[i]=edp[pos[i]+1]+1;
			}
			edp[i]=std::max(edp[i+1],dp[i]);
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans=std::max(ans,dp[i]);
		printf("%d\n",ans);
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&K);
	if (n<=15) force::solve();
	else if (n<=1000) better::solve();
	else best::solve();
	return 0;
}
