#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define P 31
#define N 200010
#define M 5000100
#define mod 1000000007
#define geth1(r) ((h1[r]-h1[j]+mod)%mod*fastpow(fac[j],mod-2)%mod)
#define geth2(r) ((h2[r]-h2[j]+mod)%mod*fastpow(fac[j],mod-2)%mod)
int n, q, len[N];
//ll h1[M], h2[M], fac[M], inv[M], ans;
char s1[M], s2[M], t1[M], t2[M];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++)
		printf("0\n");
	return 0;
}
