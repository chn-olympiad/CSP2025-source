#include <bits/stdc++.h>
using namespace std;
int n, an;
int h[5010];

void ans(int t, int all, int point) {
	if (t == 1) {
		if (all > h[point]) {
			an++;
		}
		return ;
	}
	for (int i = point; i < n; i++) {
		ans(t - 1, all + h[i], i + 1);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	sort(h + 1, h + n + 1);
	for (int i = 3; i <= n; i++) {
		ans(i, 0, 1);
	}
	printf("%d", an);
	return 0;
}
