#include <bits/stdc++.h>
using namespace std;

string s[200005][2];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	
	while (q--) {
		strint x, y;
		cin >> x >> y;
	}
    return 0;
}
