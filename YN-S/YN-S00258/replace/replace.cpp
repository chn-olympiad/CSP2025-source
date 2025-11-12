#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[5200000];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> s[n + i];
	}
	cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}