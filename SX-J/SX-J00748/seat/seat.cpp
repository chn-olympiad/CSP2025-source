#include <bits/stdc++.h>
#define endl '\n'
#define vi vector<int>
using namespace std;

bool cmp(int c, int b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int ct = n * m;
	vi a(ct);
	for (int i = 0; i < n * m; i ++) {
		cin >> a[i];
	}
	int ans = a[0];
	sort(a.begin(), a.end(), cmp);
	int k = 0;
	int j = 0;
	while (ct --) {
		for (int i = 0; i < n; i ++) {
			if (i == n) {
				j ++;
			}
			if (a[k] == ans) {
				cout << j + 1 << ' ' << i + 1 << endl;
				return 0;
			}
			k ++;
		}
	}
	return 0;
}
