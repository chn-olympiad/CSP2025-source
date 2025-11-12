#include <bits/stdc++.h>
using namespace std;
long long n, m, sum = 1;
string s;
int c[505], f[505];

//998244353
//161088479
//35305197
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	cin >> s;//льA
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		sum *= i;
		sum %= 998244353;
	}
	printf("%lld", sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
