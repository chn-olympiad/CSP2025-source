#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue <int> a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a.push(s[i] - '0');
	}
	while (!a.empty()) {
		printf("%d", a.top());
		a.pop();
	}
	return 0;
}
