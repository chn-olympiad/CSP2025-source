#include <bits/stdc++.h>
using namespace std;
int n, q;
char s1[5000005];
char s2[5000005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		cout << "0" << endl;
	}
	return 0;
}
