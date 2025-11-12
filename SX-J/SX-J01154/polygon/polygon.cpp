#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

void dfs(vector<int> &a, int t, int sum, long long &fang) {
	for (int i = t; i < a.size(); i++) {
		sum += a[i];
		for (int k = i + 1; k < a.size(); k++) {
			if (sum > a[k]) {
				//cout << sum << ' ' << a[k] << endl;
				fang++;
				fang %= MOD;
			} else {
				break;
			}
		}
		dfs(a, i + 1, sum, fang);
		sum -= a[i];
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> a;
	long long num = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	dfs(a, 0, 0, num);
	cout << num << endl;
	return 0;
}