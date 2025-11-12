#include <iostream>
#include <cstdio>
#include <algorithm>
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

#define N 510
ll n, m;
const ll mod=998244353;
bool s[N];
int c[N];
int p[N];
int ans;

signed main() {
	freopen("employ1.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	n=read(), m=read(), ans=0;
	for (int i=1; i<=n; ++i) {
		char ch=getchar();
		s[i]=ch-'0';
//		fprintf(stderr, "%d\n", s[i]);
	}
//	fprintf(stderr, "\n");
	for (int i=1; i<=n; ++i) c[i]=read();
	for (int i=1; i<=n; ++i) p[i]=i;
	while (next_permutation(p+1, p+n+1)) {
//		puts("-");
		int l=0, suc=0;
		for (int i=1; i<=n; ++i) {
			int &x=p[i];
			if (!s[x]) {
				++l; continue;
			}
			if (l>=c[x]) {
				++l; continue;
			}
			++suc, l=0;
		}
		if (suc>=m) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}

