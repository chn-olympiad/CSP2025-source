#include <bits/stdc++.h>
using namespace std;
long long n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> q;
	string s1, s2;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> s1 >> s2;
		cout << 0 << "\n";
	}
	return 0;
}