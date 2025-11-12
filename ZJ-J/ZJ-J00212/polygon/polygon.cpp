#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;

long long s[5010], ans[5010], res, ns;
int a[5010], n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	for (int i=1; i<=5000; i++) s[i] = 0;
	s[0] = 1;
	ans[0] = 1;
	for (int i=1; i<=n; i++) {
		ans[i] = ans[i-1];
		ns = 0;
		for (int j=0; j<=a[i]; j++) {
			ns = (ns + s[j]) % M;
		}
		ans[i] = (ans[i] + ns) % M;
		for (int j=5000-a[i]; j>=0; j--) {
			s[j+a[i]] = (s[j+a[i]] + s[j]) % M;
		}
	}
	res = 1;
	for (int i=1; i<=n; i++) {
		res = (res * 2) % M;
	}
	res = (res - ans[n] + M) % M;
	printf("%lld", res);
	return 0;
}
