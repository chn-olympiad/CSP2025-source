#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
string a[N], b[N];
int n, q;
int c[N][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		int len = a[i].size();
		for (int j = 0; j < len; j++) {
			if (a[i][j] == 'b') {
				c[i][0] = i;
			}
			if (b[i][j] == 'b') {
				c[i][1] = i;
			}
		}
	}
	while (q--) {
		string u, v;
		cin >> u >> v;
		int lenu = u.size();
		int lenv = v.size();
		
		if (lenu != lenv) {
			printf("0\n");
			continue;
		}
		
		int idx1, idx2;
		for (int i = 0; i < lenu; i++) {
			if (u[i] == 'b') idx1 = i;
		}
		
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			string t1 = u;
			int len1 = a[i].size();
			for (int j = max(0, idx1 - c[i][0]), k = 0; j <= len1; j++, k++) {
				if (j >= lenu) {
					break;
				}
				t1[j] = b[i][k];
			}
			if (t1 == v) {
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
