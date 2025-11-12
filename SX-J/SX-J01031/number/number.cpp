#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int p[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int t = 1;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			p[t] = s[i] - '0';
			t++;
		}
	}
	sort(p + 1, p + 1 + t, cmp);
	for (int i = 1; i <= t - 1; i++)
		cout << p[i];
	return 0;
}
