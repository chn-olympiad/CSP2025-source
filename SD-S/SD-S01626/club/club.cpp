#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N], c[N];

int solve() {
	cin >> n;
	for (int i = 1; i <= n; ++ i ) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	int res = 0;
	vector<int> A, B, C;
	for (int i = 1; i <= n; ++ i ) {
		int t = max(max(a[i], b[i]), c[i]);
		res += t;
		if (t == a[i]) {
			A.push_back(max(b[i] - a[i], c[i] - a[i]));
		} else if (t == b[i]) {
			B.push_back(max(a[i] - b[i], c[i] - b[i]));
		} else if (t == c[i]) {
			C.push_back(max(a[i] - c[i], b[i] - c[i]));
		} else {
			assert(0);
		}
	}
	if ((int)A.size() <= n / 2 && (int)B.size() <= n / 2 && (int)C.size() <= n / 2) {
		return res;
	}
	vector<int> v;
	if ((int)A.size() > n / 2) v = A;
	else if ((int)B.size() > n / 2) v = B;
	else if ((int)C.size() > n / 2) v = C;
	else assert(0);
	
	sort(v.begin(), v.end());
	int cnt = v.size() - n / 2;
	while (cnt -- ) res += v.back(), v.pop_back();
	return res;
} 

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) cout << solve() << '\n';
	return 0;
} 
