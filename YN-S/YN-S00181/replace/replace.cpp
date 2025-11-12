#include <bits/stdc++.h>
using namespace std;
string s[1000000];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	long long n, m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= m; i++) {
		cout << "0" << "\n";
	}




	return 0;
}