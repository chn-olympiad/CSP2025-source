#include <bits/stdc++.h>
using namespace std;

int n, q;
string s1[200005], s2[200005], s3[200005], s4[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		int cnt = 0;
		cin >> s3[i] >> s4[i];
		int m = s4[i].size();
		for (int j = 1; j <= n; j++) {
			if (s4[i].find(s2[j]) != -1) {
				int h = s4[i].find(s2[j]), y = 1;
				for (int k = 0; k < m; k++) {
					if (k < h && k > h + s2[j].size() && s3[k] != s4[k]) {
						y = 0;
					}
				}
				if (y == 1)
					cnt++;
			}

		}
		printf("%d\n", cnt);
	}
	return 0;
}