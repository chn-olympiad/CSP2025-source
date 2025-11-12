#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int t, n, zh1[N], zh2[N], zh3[N];
int z1c = 1, z2c = 1, z3c = 1;
int ans = 0;

bool cmp(int a, int b) {
	return a > b;
}

void mxn(int a, int b, int c) {
	if (a > b && a > c) {
		zh1[z1c++] = a;
	} else if (b > a && b > c) {
		zh2[z2c++] = b;
	} else if (c > a && c > b) {
		zh3[z3c++] = c;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		int zc = n / 2;
		for (int i = 1; i <= n; i++) {
			int z1, z2, z3;
			scanf("%d%d%d", &z1, &z2, &z3);
			mxn(z1, z2, z3);
		}
		sort(zh1 + 1, zh1 + z1c + 1, cmp);
		sort(zh2 + 1, zh2 + z2c + 1, cmp);
		sort(zh3 + 1, zh3 + z3c + 1, cmp);
		int a = min(zc, z1c);
		int b = min(zc, z2c);
		int c = min(zc, z3c);
		for (int i = 1; i <= a; i++) {
			ans += zh1[i];
		}
		for (int i = 1; i <= b; i++) {
			ans += zh2[i];
		}
		for (int i = 1; i <= c; i++) {
			ans += zh3[i];
		}
		cout << ans << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
