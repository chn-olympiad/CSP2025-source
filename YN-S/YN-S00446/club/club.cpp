#include <bits/stdc++.h>
using namespace std;
int t, n;
int anum, bnum, cnum, Max;

struct uiu {
	int a, b, c;
} s[100010];

void dfs(int num, int n1, int op) {
	Max = max(Max, num);
	if (n1 == 0) {
		return;
	}
	if (anum < n / 2) {
		anum++;
		dfs(num + s[op].a, n1 - 1, op + 1);
		anum--;
	}
	if (bnum < n / 2) {
		bnum++;
		dfs(num + s[op].b, n1 - 1, op + 1);
		bnum--;
	}
	if (cnum < n / 2) {
		cnum++;
		dfs(num + s[op].c, n1 - 1, op + 1);
		cnum--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	while (t--) {
		cin >> n;
		Max = 0;
		for (int i = 1; i <= n; i++) {
			cin >> s[i].a >> s[i].b >> s[i].c;
		}
		dfs(0, n, 1);
		cout << Max << endl;
	}
	return 0;
}