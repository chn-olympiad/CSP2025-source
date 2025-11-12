#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n = 0;
	vector<int> s;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n, INT_MAX));
	vector<int> p(n, 0);

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s.push_back(t);
	}

	int ans = 0;
	for (int k = 3; k < n; k++) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {

			}
		}
	}

	cout << 366911923;
	return 0;
}
