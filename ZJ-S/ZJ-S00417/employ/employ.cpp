#include <bits/stdc++.h>
using namespace std;
char *pa, *pb, buf[1000000];
#define int long long
#define db double
#define p_b push_back
#define nc() (pa==pb && (pb=(pa=buf)+fread(buf,1,1000000,stdin),pa==pb)?EOF:*pa++)
inline int in() { int x=0,f=1;char c=nc();while(!isdigit(c))f*=c==45?-1:1,c=nc();while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=nc();return x*f; }
inline char inc() { char c=nc();while(!isdigit(c))c=nc();return c; }

const int N = 505, M = 998244353;

int n, m, s[N], c[N], p[N], fl[N], res = 0;

void dfs(int t) 
{
	if (t == n) {
		int k = 0;
		for (int i = 1; i <= n; ++i) if (k >= c[p[i]] || s[i] == 0) ++k;
		( res += n-k >= m ) %= M;
		return;
	}
	for (int i = 1; i <= n; ++i) if (!fl[i]) {
		p[t+1] = i, fl[i] = 1; 
		dfs(t+1);
		p[t+1] = 0, fl[i] = 0;
	}
}

signed main() 
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = in(), m = in();
	for (int i = 1; i <= n; ++i) s[i] = inc() == '1';
	for (int i = 1; i <= n; ++i) c[i] = in();
	dfs(0);
	printf("%lld\n", res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}