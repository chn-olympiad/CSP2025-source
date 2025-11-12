#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string c;
	for (int i = 1; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c += s[i];
		}
	}
	int maxn;
	if (s[i] > maxn) {
		maxn = s[i];
	}
	cout << maxn;
	return 0;
}
