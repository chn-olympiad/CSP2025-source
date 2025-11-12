#include <bits/stdc++.h>
using namespace std;
const long long N = 998244353;
long long n, sum, suma, maxa;
int a[5005];

int main() {
	//¼ì²é×¢ÊÍ
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int _1 = 1; _1 <= n; _1++) {
		for (int _2 = _1 + 1; _2 <= n; _2++) {
			for (int _3 = _2 + 1; _3 <= n; _3++) {
				suma = _1 + _2 + _3;
				maxa = max(max(_1, _2), _3);
				if (suma > maxa * 2) {
					sum++;
				}
			}
		}
	}
	printf("%lld", sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}