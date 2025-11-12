#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	vector<int> n;
	string s;
	cin >> s;

	for (char c : s) {
		if ('0' <= c && '9' >= c) {
			n.push_back(c - '0');
		}
	}

	sort(n.begin(), n.end(), cmp);

	int i = 0;
	while (n[i] == 0 && i < n.size() - 1) {
		i++;
	}
	for (i; i < n.size(); i++) {
		cout << n[i];
	}
	return 0;
}