#include <bits/stdc++.h>
using namespace std;
priority_queue<char, vector<char> >v;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9') {
			v.push(s[i]);
		}
	while (v.size()) {
		char a = v.top();
		v.pop();
		cout << a;
	}
	return 0;
}
