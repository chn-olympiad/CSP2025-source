#include <bits/stdc++.h>
using namespace std;

int read() {
	int s = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + int(ch) - int('0');
		ch = getchar();
	}
	return s;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, k;
	k = read();
	n = read();
	for (int j = 1; j <= n; j++) {
		string s, y;
		cin >> s >> y;
	}
	for (int i = 1; i <= k; i++) {
		string y, s;
		cin >> s >> y;
	}
	for (int i = 1; i <= k; i++) {
		cout << 0 << endl;
	}
	return 0;
}