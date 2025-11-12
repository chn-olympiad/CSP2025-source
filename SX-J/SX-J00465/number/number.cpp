#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

string s;
int n;
priority_queue<char, vector<char>> pq;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;

	n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			pq.push(s[i]);
	}

	while (!pq.empty()) {
		cout << pq.top(), pq.pop();
	}

	return 0;
}
