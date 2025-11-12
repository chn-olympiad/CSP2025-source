#include <bits/stdc++.h>
using namespace std;
const int MAXX = 1E6;
int a[MAXX + 100];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	int cnts = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[cnts] = s[i] - '0';
			cnts++;
		}
	}
	sort(a, a + cnts, cmp);
	for (int i = 0; i < cnts; i++) {
		cout << a[i];
	}
	return 0;
}
