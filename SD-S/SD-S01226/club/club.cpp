#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <array>
using namespace std;
typedef long long ll;

ll read() {
	ll x=0, f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	return x*f;
}

#define N 100010
int T;
int n, n1;
int d[N][3];
int a[N];
ll ans;
//#define fi first
//#define se second
//pair<int,int> b[N];
struct cl {
	int idx;
	array<int,2> dt;
} b[N];
bool operator<(cl x, cl y) {
	return max(x.dt[0], x.dt[1])>max(y.dt[0],y.dt[1]);
}

void dfs(int dep, ll sum, array<int, 3> ar) {
	for (int i=0; i<3; ++i) {
		if (ar[i]>(n>>1)) return;
	}
	if (dep==n+1) {
		ans=max(ans, sum);
		return;
	}
	for (int i=0; i<3; ++i) {
		auto ar1=ar;
		++ar1[i];
		dfs(dep+1, sum+d[dep][i], ar1);
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T=read();
	while (T--) {
		n=read(), n1=(n>>1), ans=0;
		for(int i=1; i<=n; ++i) {
			for (int j=0; j<3; ++j) {
				d[i][j]=read();
			}
		}
		if (n<=10) {
			dfs(1,0,{0,0,0});
			printf("%lld\n", ans);
			continue;
		}
		for (int i=1; i<=n; ++i) a[i]=d[i][0];
		for (int i=1; i<=n; ++i) b[i]={i,{d[i][1]-d[i][0],d[i][2]-d[i][0]}};
		sort(b+1, b+n+1);
		array<int,3> cnt={0,0,0};
		for (int i=1; i<=n; ++i) {
//			fprintf(stderr, "%d\n", i);
			assert(cnt[0]<=n1&&cnt[1]<=n1&&cnt[2]<=n1);
			assert(cnt[0]+cnt[1]+cnt[2]<=n); 
			const int &d0=b[i].dt[0];
			const int &d1=b[i].dt[1];
			int c=-1;
			if (d0>d1) c=0;
			else if (d0<d1) c=1;
			else c=2;
			if (i<=n1) {
				a[b[i].idx]+=max(d0,d1);
				++cnt[c];
				continue;
			}
			// i>n1
			if (cnt[0]==n1) {
				if (d1>0) a[b[i].idx]+=d1, ++cnt[1];
				continue;
			}
			if (cnt[1]==n1) {
				if (d0>0) a[b[i].idx]+=d0, ++cnt[0];
				continue;
			}
			if (c==0&&d0>0) a[b[i].idx]+=d0, ++cnt[0];
			if (c==1&&d1>0) a[b[i].idx]+=d1, ++cnt[1];
			if (c==2&&d0>0) {
				assert(d0==d1);
				a[b[i].idx]+=d0, ++cnt[2];
			}
		}
//		for (int i=1; i<=n; ++i) fprintf(stderr, "%d ", a[i]);
		for (int i=1; i<=n; ++i) ans+=a[i];
		printf("%lld\n", ans);
	}
	return 0;
}

