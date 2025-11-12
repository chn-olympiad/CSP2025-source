#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int ans[N];
string s;
int a;
int n, m;

int cmp(int n, int m) {
	return n > m;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	for (int i = 0 ; i < s.size() ; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			ans[i] = s[i] - '0';
			a++;
		}
	}
	for (int i = 0 ; i < a ; i++) {
		cmp(n, m);
	}
	for (int i = a - 1 ; i >= 0 ; i--) {
		cout << ans[i];
	}
	return 0;
}