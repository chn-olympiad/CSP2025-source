#include <bits/stdc++.h>
using namespace std;
string s;
long long k, a[1000100];

bool cmp(int x, int y) {
	return x >= y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= '9' && s[i] >= '0')
			a[s[i] - '0']++ ;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
