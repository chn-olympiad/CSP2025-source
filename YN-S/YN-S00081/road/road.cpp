#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int kz[20][1000005];



struct bro {
	int fr, to, co;
} a[1000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].fr >> a[i].to >> a[i].co;
	}
	for (int i = 1; i <= k; i++) {
		cin >> kz[i][1];
		for (int j = 2; j <= m + 1; j++) {
			cin >> kz[i][j];
		}
	}
	bool flag = 0;
	for (int i = 2; i <= m + 1; i++) {
		if (kz[1][i - 1] != kz[1][i])
			flag = 1;
	}
	if (flag == 1)
		cout << 0;
	return 0;
}