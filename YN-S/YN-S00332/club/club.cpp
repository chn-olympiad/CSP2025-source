#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, ans, a[N], b[N], c[N];

void search1(int dep = 1, int num1 = 0, int num2 = 0, int num3 = 0, int sum = 0) {
	if (dep > n) {
		ans = max(ans, sum);
		return;
	}
	if (num1 >= n / 2) {
		search1(dep + 1, num1, num2 + 1, num3, sum + b[dep]);
		search1(dep + 1, num1, num2, num3 + 1, sum + c[dep]);
		return;
	}
	if (num2 >= n / 2) {
		search1(dep + 1, num1 + 1, num2, num3, sum + a[dep]);
		search1(dep + 1, num1, num2, num3 + 1, sum + c[dep]);
		return;
	}
	if (num3 >= n / 2) {
		search1(dep + 1, num1 + 1, num2, num3, sum + a[dep]);
		search1(dep + 1, num1, num2 + 1, num3, sum + b[dep]);
		return;
	}
	search1(dep + 1, num1 + 1, num2, num3, sum + a[dep]);
	search1(dep + 1, num1, num2 + 1, num3, sum + b[dep]);
	search1(dep + 1, num1, num2, num3 + 1, sum + c[dep]);
}

void search2(int dep = 1, int num1 = 0, int num2 = 0, int sum = 0) {
	if (dep > n) {
		ans = max(ans, sum);
		return;
	}
	if (num1 >= n / 2) {
		search2(dep + 1, num1, num2 + 1, sum + b[dep]);
		return;
	}
	if (num2 >= n / 2) {
		search2(dep + 1, num1 + 1, num2, sum + a[dep]);
		return;
	}
	search2(dep + 1, num1 + 1, num2, sum + a[dep]);
	search2(dep + 1, num1, num2 + 1, sum + b[dep]);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		//qingkong
		bool flag1 = true, flag2 = true;
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			if (flag1 == true && b[i] != 0) {
				flag1 = false;
			}
			if (flag2 == true && c[i] != 0) {
				flag2 = false;
			}
		}
		if (flag2 == true) {
			if (flag1 == true) {
				sort(a + 1, a + 1 + n, greater<int>());
				for (int i = 1; i <= n / 2; i++) {
					ans += a[i];
				}
			} else {
				search2();
			}
		} else {
			search1();
		}
		printf("%d\n", ans);
	}
	return 0;
}