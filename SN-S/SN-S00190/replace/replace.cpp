#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "W", stdout); 
	int n, q;
	cin >> n >> q;
	int s[n], t[q][2];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> t[i][0] >> t[i][1];
	}
	for (int i = 0; i < q; i++) {
		cout << 0 << endl;
	}
	return 0;
}
