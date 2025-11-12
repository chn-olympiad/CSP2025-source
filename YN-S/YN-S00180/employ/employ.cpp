#include<bits/stdc++.h>
using namespace std;
int n, m, a[600], c[600];
char s;
long long ans = 1, nn;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		s = getchar();
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	nn = n;
	for (long long i = nn; i >= 1; i--)
		ans = (ans * i) % 998244353;
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
