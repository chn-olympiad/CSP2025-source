#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+10, M = 1e6+10;
const int mod = 998244353, P = 47;

int n, q;
string s[N][5], t[N][5], hasht1[N], hasht2[N], hashs1[N], hashs2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; i++)
		cin >> t[i][1] >> t[i][2];
	for (int i = 1; i <= q; i++) {
		int ans = 0;
		if (t[i][1].size() != t[i][2].size()) {
			printf("0\n");
			continue;
		}
		for (int j = 1; j <= n; j++) {
			string s1 = t[i][1];
			for (int k = 0; k < (int)t[i][1].size(); k++) {
				bool fl = 0;
				int id2 = 0;
				for (int id = k; id < (int)s[j][1].size() + k; id++) {
//					cout << k << " " << id << " " << id2 << endl;
//					cout << t[i][1][id] << " " << s[j][1][id2] << endl;
					if (t[i][1][id] != s[j][1][id2]) {
						fl = 1;
						break;
					}
					id2++;
				}
				if (!fl) {
					for (int id = 0; id < (int)s[j][2].size(); id++)
						s1[k + id] = s[j][2][id];
					if (s1 == t[i][2])
						ans++;
					s1 = t[i][1];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
