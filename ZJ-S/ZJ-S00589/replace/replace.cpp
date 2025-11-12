#include <bits/stdc++.h>
//#define int long long

using namespace std;
const int N = 30 * 30 * 30 * 30;
vector <int> cr1[N], cr2[N];
int change(string x, int L = 0, int z = 4) {
	int tmp = 0;
	int k = 1;
	for (int i = L ; i < x.size() ; i ++) {
		if (i - L == z) break;
		tmp = tmp + k * (x[i] - 'a' + 1);
		k *= 30;
	}
	return tmp;
}
string s1[100005], s2[100005];
int Ans;
string A, B;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i ++)
		cin >> s1[i] >> s2[i];
	for (int i = 1 ; i <= n ; i ++) {
		int len = s1[i].size();
		for (int j = 1 ; j <= min(len, 4) ; j ++) {
			cr1[change(s1[i], 0, j)].push_back(i);
			cr2[change(s2[i], 0, j)].push_back(i);
		}
	}
//	cout << 1 << '\n';
	while (q --) {
		cin >> A >> B;
		if (A.size() != B.size()) {
			cout << 0 << '\n';
			continue;
		}
		int len = A.size();
		int L = -1, R = -1;
		for (int i = 0 ; i < len ; i ++) {
			if (A[i] != B[i]) {
				if (L == -1) L = i;
				R = i;
			}
		}
//		cout << L << ' ' << R << '\n';
//		cout << q << "M\n";
		int ans = 0;
		for (int i = 0 ; i <= L ; i ++) {
			int X = change(A, i, min(R - i + 1, 4));
			int Y = change(B, i, min(R - i + 1, 4));
			int w = 0;
//			cout << i << "S\n";
//			cout << X << ' ' << Y << '\n';
//			for (int v : cr1[X]) cout << v << ' '; cout << "AA\n";
//			for (int v : cr2[Y]) cout << v << ' '; cout << '\n';
//			cout << "BB";
			for (int v : cr1[X]) {
				if (s1[v].size() + i - 1 < R || s1[v].size() + i - 1 >= A.size())
					continue;
//				cout << "CC";
				while (w + 1 < cr2[Y].size() && cr2[Y][w] < v) w ++;
				if (w >= cr2[Y].size() || cr2[Y][w] != v) continue;
				bool flag = 0;
				for (int j = 0 ; j < s1[v].size() ; j ++) {
					if (A[j + i] != s1[v][j] || B[j + i] != s2[v][j]) {
						flag = 1;
						break;
					}
				}
				if (!flag) ans ++;
			}
//			cout << "End";
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
3 1
a b
b c
c d
b a
*/