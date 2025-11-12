#include <bits/stdc++.h>
using namespace std;

long long n, m, a[510], c[510], b[510], v[510], ans;
char s[510];
const long long P = 998244353;

void dfs (int x){
	if (x == n + 1){
		long long h = 0, u = 0;
		for (int i = 1; i <= n; i++){
			if (h >= a[c[i]] || s[i] == '0')
				h++;
			else
				u++;
		}
		if (u >= m)
			ans++;
		ans %= P;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (b[i] == 0){
			c[x] = i;
			b[i] = 1;
			dfs (x + 1);
			b[i] = 0;
		}
	}
}

int main (){
//	freopen ("employ3.in", "r", stdin);
//	freopen ("employ.out", "w", stdout);
	scanf ("%lld%lld", &n, &m);
	scanf ("%s", s + 1);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
//	for (int i = 1; i <= n; i++){
//		v[i] = n + 1;
//		int g = 0;
//		for (int j = 1; j <= n; j++){
//			if (a[j] == )
//		}
//	}
	dfs (1);
	printf ("%lld", ans);
	return 0;
}