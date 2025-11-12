#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
string s;
int a[15];
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		while (a[i]--) {
			printf("%lld", i);
		}
	}
	return 0;
}