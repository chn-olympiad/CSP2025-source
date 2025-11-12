#include <bits/stdc++.h>
using namespace std;

int n, k, a[500001], S[500001];
vector<pair<int, int> > validRange;
map<int, bool> choosen;

bool cmp(pair<int, int> &A, pair<int, int> &B) {
	return A.second < B.second;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	S[0] = 0;

	for (int i = 1; i <= n; i++) {
		S[i] = S[i - 1] ^ a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (abs(S[j] - S[i - 1]) == k) {
				validRange.push_back(make_pair(i, j));
			}
		}
	}

	sort(validRange.begin(), validRange.end(), cmp);

	int ans = 0, l = 0;
	for (int i = 0; i < validRange.size(); i++) {
		if (validRange[i].first > l) {
			ans++;
			l = validRange[i].second;
		}
	}

	cout << ans << endl;
	return 0;
}