#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string b = "";
	int n[100000];
	int x = s.length();
	for (int i = 0; i <= x; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b += s[i];
		}
	}
	int a = b.length();
	for (int i = 0; i <= a - 1; i++) {
		n[i] = b[i] - '0';
	}
	sort(n, n + a, cmp);
	for (int i = 0; i <= a - 1; i++) {
		cout << n[i];
	}




	return 0;
}
