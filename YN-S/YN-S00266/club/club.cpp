#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long n, m;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

for (int i = 1; i <= n; i++) {
	cnt += a[i];
}
int maxn = -1;

for (int i = 1; i <= m; i++) {
	if (cnt >= maxn) {
		maxn = cnt;
	}
}
cout << maxn;

return 0;
}