#include <bits/stdc++.h>
using namespace std;
int q[100010][4];
int dc[100010][4];

int read() {
	int f = 1, s = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + int(ch) - int('0');
		ch = getchar();
	}
	return f * s;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int k, n, ans = -1, c1, c2, c3, m;
	k = read();
	for (int i = 1; i <= k; i++) {
		n = read();
		m = n / 2;
		//shu
		for (int j = 1; j <= n; j++) {
			for (int s = 1; s <= 3; s++) {
				q[j][s] = read();
			}
		}
		//suan
		dc[1][1] = q[1][1];
		dc[1][2] = q[1][2];
		dc[1][3] = q[1][3];
		for (int j = 2; j <= n; j++) {
			for (int s = 1; s <= 3; s++) {
				int tmp =  max(max(dc[j - 1][3], dc[j - 1][2]), dc[j - 1][1]);
				dc[j][s] = tmp + q[j][s];
			}
		}
		int ans = 0;
		ans += max(dc[n][1], max(dc[n][2], dc[n][3]));
		cout << ans << endl;
	}

	return 0;
}