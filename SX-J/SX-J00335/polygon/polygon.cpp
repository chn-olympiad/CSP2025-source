#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
const int R = 998244353;
int a1[5010], v[5010], v1[50010];

bool sjx(int a, int b, int c) {
	if (a + b > c && a + c > b && b + c > a && abs(a - b) < c && abs(a - c) < b && abs(b - c) < a) {
		return true;
	}
	return false;
}

bool ch(int he, int ma, int sl1) {
	if (he > ma * 2 && sl1 >= 3 && v1[he] == 0) {
		return true;
	}
	return false;
}

void dfs(int qmh, int maxx, int sl) {
	if (ch(qmh, maxx, sl) == true) {
		ans++;
		v1[qmh] = 1;
		cout << qmh << " " << maxx << " " << sl << " " << endl;
		return ;
	}
	if (sl > n) {
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			dfs(qmh + a1[i], max(maxx, a1[i]), sl + 1);
			v[i] = 0;
		}
	}
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a1[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		if (sjx(a1[1], a1[2], a1[3]) == true) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	dfs(0, -1, 0);
	cout << ans % R;
	return 0;
}
