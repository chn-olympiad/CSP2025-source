#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, q1, nxt[N][N], f[N];
string s1[N], s2[N], t1, t2;

void getnxt(int k) {
	int j = 0, m = s1[k].size() - 1;
	for (int i = 2; i <= m ; i++) {
		while (j && s1[k][i] != s1[k][j + 1])
			j = nxt[k][j];
		if (s1[k][i] == s1[k][j + 1])
			j++;
		nxt[k][i] = j;
	}
}

int KMP() {
	int k = 0, cnt = 0, l1 = t1.size() - 1, l2;
	for (int i = 1; i <= n; i++) {
		l2 = s1[i].size() - 1;
		k = 0;
		for (int j = 1; j <= l1; j++) {
			while (k == l2 || (k && t1[j] != s1[i][k + 1]))
				k = nxt[i][k];
			if (t1[j] == s1[i][k + 1]) {
				k++;
			}

			f[j] = k;
		}
		for (int j = 1; j <= l1; j++) {
			if (f[j] == l2) {
				int flag = true;
				for (int q = 1; q < j - l2 + 1; q++) {
					if (t1[q] != t2[q]) {
						flag = false;
						break;
					}
				}
				if (!flag)
					continue;
				for (int q = 1, w = j - l2 + 1; q <= l2 && w <= j; q++, w++) {
					if (s2[i][q] != t2[w]) {
						flag = false;
						break;
					}
				}
				if (!flag)
					continue;
				for (int q = j + 1; q <= l1; q++) {
					if (t1[q] != t2[q]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					cnt++;
				}
			}

		}
	}
	return cnt;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q1;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		s1[i] = "." + s1[i];
		s2[i] = "." + s2[i];
		getnxt(i);
	}
	for (int i = 1; i <= q1; i++) {
		cin >> t1 >> t2;
		t1 = "." + t1;
		t2 = "." + t2;
		if (t1.size() != t2.size())
			cout << 0 << endl;
		else
			cout << KMP() << endl;
	}
	return 0;
}
