#include <bits/stdc++.h>
using namespace std;
int s[100005];
int a[1005][1005];
long long n, m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {

	cin >> n >> m;
	long long t = m * n;
	for (int i = 1; i <= t; i++) {
		cin >> s[100005];
	}
	long long rs = s[1];
	sort(s + 1, s + t + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == n and j % 2 != 0) {
				a[n][j + 1] = s[i + 2];
				a[i][j] = s[i];
			} else if (i == 1 and j % 2 == 0) {
				a[1][j + 1] = s[i + 2];
				a[i][j] = s[i];
			} else {
				a[i][j] = s[i];
			}
		}
	}
	int c, r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << c << " " <<   r;

	return 0;
}
