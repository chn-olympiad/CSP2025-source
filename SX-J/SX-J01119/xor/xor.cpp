#include <bits/stdc++.h>
using namespace std;
int n, a[500005], k, maxx = INT_MIN;

int suan(int x, int y) {
	int num = 0;
	for (int i = x; i <= y; i++) {
		num = num ^a[i];
	}
	return num;
}

void dfs(int x, int sum) {
	for (int i = x; i <= n; i++) {
		if (suan(x, i) == k) {
			dfs(i + 1, sum + 1);
			break;
		}
	}
	maxx = max(maxx, sum);
	return ;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
	}
	cout << maxx;
	return 0;
}