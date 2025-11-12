#include <bits/stdc++.h>
using namespace std;

struct node {
	int start;
	int end;
};

bool cmp(node i, node j) {
	return i.end < j.end;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n + 1], dp[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = (dp[i - 1] ^ a[i]);
	}
	vector<node> v;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((dp[j]^dp[i - 1]) == k) {
				node x;
				x.start = i;
				x.end = j;
				v.push_back(x);
				//cout << x.start << ' ' << x.end << ' ' << (dp[j]^dp[i - 1]) << endl;
			}
		}
	}
	int ndp[v.size()][n + 1] = {0};
	int newdp[v.size()][n + 1] = {0};
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 0) {
				if (v[i].end <= j) {
					ndp[i][j] = v[i].end;
					newdp[i][j] = 1;
				} else {
					ndp[i][j] = 0;
					newdp[i][j] = 1;
				}
			} else if (v[i].end > j) {
				newdp[i][j] = newdp[i - 1][j];
				ndp[i][j] = ndp[i - 1][j];
			} else if (v[i].start <= ndp[i - 1][j]) {
				newdp[i][j] = newdp[i - 1][v[i].start - 1] + 1;
				ndp[i][j] = v[i].end;
			} else {
				newdp[i][j] = max(newdp[i - 1][v[i].start - 1] + 1, newdp[i - 1][j] + 1);
				ndp[i][j] = v[i].end;
			}
		}
	}

	cout << newdp[v.size() - 1][n] << endl;
	return 0;
}