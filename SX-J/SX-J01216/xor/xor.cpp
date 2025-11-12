#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7+5;
int n, k;
int cnt = 0;
int a[MAXN];

int f(int x) {
	int t = 1, c, ans = 0;
	while (x) {
		c = x % 2;
		ans += c * t;
		x /= 2;
		t *= 10;
	}
	return ans;
}

int f1(int x) {
	int c, ans = 0, t = 1;
	while (x) {
		c = x % 10;
		ans += c * t;
		x /= 10;
		t *= 2;
	}
	return ans;
}

int fxor(int x, int y) {
	int t = 1, ans = 0, c1, c2;
	x = f(x), y = f(y);
	while (x || y) {
		c1 = x % 10;
		c2 = y % 10;
		if (c1 != c2)
			ans += t;
		c1 /= 10;
		c2 /= 10;
		t *= 10;
	}
	return f1(ans);
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int sum = a[j];
			for (int v = j + 1; v <= i; v++) {
				sum += fxor(a[v], sum);
			}
			if (sum == k)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}
