#include <cstdio>
#include <cassert>
#include <algorithm>
int n;
namespace best {
	const int N=100007;
	int n,a[N][3];
	int T;

	int len[3];
	int c[N][2],t[3],id[N][3],d[N];
	int idd[N];
	bool cmps(int i,int j) {
		return d[i]>d[j];
	}
	bool cmp(int i,int j) {
		if (t[i]!=t[j]) return t[i]<t[j];
		return i<j;
	}
	void solve(int n) {
		for (int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for (int i=1;i<=n;i++) {
			for (int j=0;j<3;j++)
				t[j]=a[i][j],id[i][j]=j;
			std::sort(id[i],id[i]+3,cmp);
			d[i]=t[id[i][2]]-t[id[i][1]];
		}
		for (int i=1;i<=n;i++) idd[i]=i;
		std::sort(idd+1,idd+1+n,cmps);
		int ans=0;
		int sum=0;
		for (int i=1;i<=n;i++) {
			if (len[id[idd[i]][2]]+1<=n/2) {
				len[id[idd[i]][2]]++;
				ans+=a[idd[i]][id[idd[i]][2]];
				sum++;
			} else if (len[id[idd[i]][1]]+1<=n/2) {
				len[id[idd[i]][1]]++;
				ans+=a[idd[i]][id[idd[i]][1]];
				sum++;
			} else {
				assert(false);
			}
		}
		printf("%d\n",ans);
		for (int i=0;i<3;i++) len[i]=0;
	}
}
namespace force {
	const int N=16;
	int n;
	int a[N][3];
	int dfs(int now,int sum,int l[3]) {
		if (now>n) return std::max(std::max(l[0],l[1]),l[2])<=n/2?sum:0;
		int ans=0;
		for (int j=0;j<3;j++) {
			l[j]++;
			ans=std::max(ans,dfs(now+1,sum+a[now][j],l));
			l[j]--;
		}
		return ans;
	}
	void solve(int nn) {
		n=nn;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<3;j++)
				scanf("%d",&a[i][j]);
		}
		int l[3]={0,0,0};
		printf("%d\n",dfs(1,0,l));
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	// best::solve();
	int T;scanf("%d",&T);
	for (;T--;) {
		scanf("%d",&n);
		if (n<=15) force::solve(n);
		else best::solve(n);
		// best::solve(n);
	}
	return 0;
}//20pts force