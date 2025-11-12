#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, e;
string a[N][2];
int b[N][2];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &e);
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
		for (int j = 0; j < int(a[i][0].length()); j++) {
			if (a[i][0][j] == 'b') b[i][0] = i;
			if (a[i][1][j] == 'b') b[i][1] = i;
		}
	}
	for (int i = 1; i <= e; i++) {
		string s1, s2;
		int p, q;
		cin >> s1 >> s2;
		int lens = s1.length();
		for (int j = 0; j < lens; j++) {
			if (s1[j] == 'b') p = i;
			if (s2[j] == 'b') q = i;
		}
		if (p == q) {
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				if (b[i][0]  == b[i][1]) ans ++;
			}
			cout << ans;
		} else if (p > q) {
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				if(b[i][0] > b[i][1] && p - q == b[i][0] - b[i][1] && b[i][0] <= p && b[i][1] <= q && int(a[i][0].length()) - (p - b[i][0]) <= lens && int(a[i][1].length()) - (q - b[i][1]) <= lens){
					ans ++;
				}
			}
			cout << ans;
		}
		cout << endl;
	}


	return 0;
}
