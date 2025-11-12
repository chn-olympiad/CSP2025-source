#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	priority_queue<int, vector<int>, less<int>> pq;
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9')
			pq.push(s[i] - '0');
	}
	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
	return 0;
}
