#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> que;

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ((int)s[i] >= 48 and (int)s[i] <= 57) {
			que.push(s[i] - '0');
		}
	}
	while (!que.empty()) {
		cout << que.top();
		que.pop();
	}


	return 0;
}
