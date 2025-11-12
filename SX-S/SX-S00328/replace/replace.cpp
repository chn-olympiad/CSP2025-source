#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
string c[N], d[N];
int nxt[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m, cnt;
	int l, r, flag;
	string a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> d[i];
	}
	while (m--) {
		cnt = 0;
		flag = l = r = 0;
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i] && r != i - 1 && l) {
				cout << 0 << endl;
				flag = 1;
				break;
			}
			if (a[i] != b[i] && !l)
				l = r = i;
			else if (a[i] != b[i] && l)
				r++;
		}
		if (flag == 1)
			continue;
		for (int t = 1; t <= n; t++) {
			for (int i = 0; i < c[t].size(); i++) {
				nxt[i] = -1;
			}
			for (int i = 1, j = -1; i < c[t].size(); i++) {
				while (j != -1 && c[t][i] != c[t][j + 1])
					j = nxt[j];
				if (c[t][i] == c[t][j + 1]) {
					j++;
				}

				nxt[i] = j;
			}
			for (int i = 0, j = -1; i < a.size(); i++) {
				while (j != -1 && a[i] != c[t][j + 1]) {
					j = nxt[j];
				}

				if (a[i] == c[t][j + 1])
					j++;
				if (j == a.size() - 1) {
					flag = 0;
					int len = d[t].size();
					if (i >= r && i - len + 1 <= l) {
						for (int w = i - len + 1, y = 0; w <= i, y <= j; w++, y++) {
							if (d[t][y] != b[w]) {
								flag = 1;
								break;
							}
						}
						if (flag == 0)
							cnt++;
					}
				}
			}
		}
		cout << cnt + 1 << endl;
	}
	return 0;
}