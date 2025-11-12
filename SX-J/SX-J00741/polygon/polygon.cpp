#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int b[5010];
int cnt = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i + 3; j <= n; j++) {
			int ma = b[j] - b[i];
			if (ma / 2 >= a[j]) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
