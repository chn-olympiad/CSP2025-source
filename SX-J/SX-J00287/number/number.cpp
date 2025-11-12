#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s, n;
bool b;
priority_queue<ll> a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a.push(s[i] - '0');
		}
	}
	if (a.top() == 0) {
		cout << 0;
	} else {
		while (!a.empty()) {
			cout << a.top();
			a.pop();
		}
	}

}
