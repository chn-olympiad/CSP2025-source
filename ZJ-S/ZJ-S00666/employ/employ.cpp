#include <bits/stdc++.h>
#define mod % 998244353
#define add + 998244353
void smalladd(int &a, int b) {
	a += b, a -= a >= add ? add : 0;
}
long long fact[512], C[512][512];
void prepare() {
	fact[0] = 1;
	for(int i = 1; i < 512; i++)
		fact[i] = fact[i - 1] * i mod;
	for(int i = 0; i < 512; i++)
		for(int j = 0; j <= i; j++)
			if(j == 0)
				C[i][j] = 1;
			else
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) mod;
}
int n, m, s[512], c[512], pc[512], f[512][512], g[512][512];
int main() {
	freopen("employ.in", "rb", stdin);
	freopen("employ.out", "wb", stdout);
	scanf("%d%d", &n, &m), prepare();
	for(int i = 1; i <= n; i++)
		scanf("%1d", &s[i]);
	for(int i = 1, x; i <= n; i++)
		scanf("%d", &x), c[x]++;
	for(int i = 1; i <= n + 1; i++)
		pc[i] = pc[i - 1] + c[i - 1];
/*
	when the count of failure increses from v-1 to v:
	-	all c_i=v after will turn into mad
	f_i,(j),k --> i tests, j failures, k mads not usen
*/
	int ans = 0;
	g[0][0] = 1;
	for(int j = 0; j <= n; j++) {
		memset(f, 0, sizeof f);
		for(int o = 0, t = c[j]; o <= t; o++)
			for(int i = 0; i <= n; i++)
				for(int k = 0; k <= n; k++)
					if(g[i][k] != 0) {
						long long v = g[i][k];
						//	turning %o into mad
						//	pc[j] ==> pc[j + 1]
						int s = i - pc[j] + k;
						smalladd(f[i][k + t - o], v * C[t][o] mod * C[s][o] mod * fact[o] mod);
					}
		memset(g, 0, sizeof g);
		for(int i = 1; i <= n; i++)
			for(int k = 0; k <= n; k++)
				if(f[i - 1][k] != 0) {
					long long v = f[i - 1][k];
					if(s[i] == 0) {
						if(k)
							smalladd(g[i][k - 1], v * k mod);
						smalladd(g[i][k], v);
					} else {
						if(k)
							smalladd(g[i][k - 1], v * k mod);
						smalladd(f[i][k], v);
					}
				}
		if(j + m <= n)
			smalladd(ans, f[n][0] * fact[n - pc[j + 1]] mod);
	}
	printf("%d\n", ans);
	return 0;
}
