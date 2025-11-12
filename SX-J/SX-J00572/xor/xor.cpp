#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
long long n, k, a[N], f[N], v[N], sum, s1, s2;

int main() {
	//¼ì²é×¢ÊÍ
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = a[i];
		for (int j = i; j <= n; j++) {
			if (j != i)
				f[j] = f[j - 1] ^ a[j];
			if (f[j] == k) {
				//printf("%d %d %lld\n", i, j, f[j]);
				v[i]++;
				v[j + 1]--;
				sum++;
				break;
			}
		}
		memset(f, 0, sizeof(f));
	}
	//printf("%lld\n", sum);
	for (int i = 1; i <= n + 1; i++) {
		s1 += v[i];
		if (s1 > 1 && s1 > s2) {
			sum -= s1 - s2;
			//printf("%d %lld %lld\n", i, s1 - s2, s1);
		}
		s2 = s1;
	}
	printf("%lld", sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}