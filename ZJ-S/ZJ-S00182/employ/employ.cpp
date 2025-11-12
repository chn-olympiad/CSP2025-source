#include <cstdio>
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n;
	scanf("%d", &n);
	long long ans = 1;
	for (int i=1;i<=n; i++){
		ans = (ans * i)%998244353;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}