#include <bits/stdc++.h>
using namespace std;
long long n, k;
int  a[100009];
int f[50009][21];

int find(int x, int y) {
	if (x == y)
		return a[x];
	int l = (__lg(y - x + 1)) - 1;
	int r = y - (1 << l) + 1;
	return f[x][l] ^ f[r][l];
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i][0] = a[i];
	}
	for (int j = 1; j <= 20; j++) {
		for (int i = 1; i <= n; i++) {
			if ((1 << j) + i > n)
				break;
			f[i][j] = f[i][j - 1] ^ f[i + (1 << j)][j - 1];
		}
	}
	int stt = 1;
	long long cnt = 0;
	long long ans = 0;
	while (stt <= n) {
		cnt = 0;
		for (int i = stt; i <= n; i++) {
			if (find(stt, i) == k) {
				cnt++;
				stt = i + 1;
			}
		}
		ans = max(ans, cnt);
		stt++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}