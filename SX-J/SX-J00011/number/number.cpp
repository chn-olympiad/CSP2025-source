#include <bits/stdc++.h>
using namespace std;
string s;
int n[1000005], ans = 1, l;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int nt = s.size();
	for (int i = 0; i < nt; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			n[ans] = s[i] - '0';
			ans++;
		}
	}
	sort(n + 1, n + ans + 1, cmp);
	for (int i = 1; i < ans; i++) {
		cout << n[i];
	}
	return 0;
}
