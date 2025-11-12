#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int MAXN = 5e5 + 10;
int n, k, a[MAXN], ans = 0;
vector<PII> records;
int getXOR(int l, int r) {
	int result = a[l];
	for (int i = l + 1; i <= r; i++) {
		result = a[i] xor result;
	}
	return result;
}
bool isInBound(int cl, int cr, int wl, int wr) {
	bool lBound = (cl <= wl && wl <= cr);
	bool rBound = (cl <= wr && wr <= cr);
	return lBound || rBound;
}
bool check(int l, int r) {
	for (int i = 0; i < records.size(); i++) {
		if (isInBound(records[i].first, records[i].second, l, r)) {
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int v = getXOR(i, j);
			if (v == k && !check(i, j)) {
				records.push_back({i, j});
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}