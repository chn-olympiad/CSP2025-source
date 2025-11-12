#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e6+7;
int a[maxn];
string s;

signed main(signed argc, char const *argv[]) {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = 0;
	for (char &c : s) {
		if ('0' <= c && c <= '9') {
			a[++n] = c - 48;
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i; i--)
		cout << a[i];
	return 0;
}
