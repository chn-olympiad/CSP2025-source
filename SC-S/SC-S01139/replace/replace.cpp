#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6 + 5;

int n, m, ls[maxn];

string s1[maxn], s2[maxn];

char t1[maxn], t2[maxn];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> (t1 + 1) >> (t2 + 1);
		ls[i] = strlen(t1 + 1);
		for(int j = 1; j <= ls[i]; j++) s1[i][j] = t1[j], s2[i][j] = t2[j];
	}
	while(m--) {
		cin >> (t1 + 1) >> (t2 + 1);
		int len = strlen(t1 + 1);
		if(strlen(t2 + 1) != len) { cout << "0\n"; continue; }
		int ans = 0;
		for(int i = 1; i <= len; i++) {
			for(int j = 1; j <= n; j++) {
				if(i + ls[j] - 1 > len) continue;
				bool failed = 0;
				for(int k = 1; k <= ls[j]; k++)
					if(s1[j][k] != t1[i + k - 1])
						{ failed = 1; break; }
				if(failed) continue;
				for(int k = 1; k <= len; k++) {
					if(i <= k && k <= i + ls[j] - 1) {
						if(s2[j][k - i + 1] != t2[k]) {
							failed = 1;
							break;
						}
					}
					else if(t1[k] != t2[k]) { failed = 1; break; }
				}
				ans += (!failed);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}