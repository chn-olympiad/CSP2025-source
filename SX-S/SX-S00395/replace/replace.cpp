#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, q, l1, l2;
string s[N][5], t[N][5];

int main() {
	freopen("replace.in", "w", stdin);
	freopen("replace.out", "r", stdout);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> s[i][1] >> s[i][2];
		l1 += s[i][1].size() + s[i][2].size();
	}
	for (int i = 1; i < q; i++) {
		cin >> s[i][1] >> s[i][2];
		l2 += s[i][1].size() + s[i][2].size();
	}
	return 0;
}