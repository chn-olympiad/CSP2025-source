#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forl(i, j, k) for(int (i) = (j); (i) <= (k); (i)++)
#define forr(i, j, k) for(int (i) = (j); (i) >= (k); (i)--)
#define er(a, b) cout << (a) << ": " << (b) << '\n';
const int N = 2e5+5;
int T;
int n, q, ans;
string a[N][2];
string t1, t2;

bool check(int idx, int j) {
	string u = t1;
	string y = a[j][0];
	int l = y.length();
	forl(i, 0, l-1) {
		if (u[idx+i] != y[i]) {
			return 0;
		}
	}
	return 1;
}

void replace(int idx, int j) {
	string u;
	u.resize(t1.length());
	forl(i, 0, (int)t1.length()-1) {
		u[i] = t1[i];
	}
	
	string y = a[j][0];
	int l = y.length();
	forl(i, 0, l-1) {
		u[idx+i] = a[j][1][i];
	}
	bool flag = 1;
	forl(i, 0, (int)t2.length()-1) {
		if (u[i] != t2[i]) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		ans++;
	}
}
//
//int special(string y) {
//	int idx = -1;
//	forl(i, 0, (int)y.length()) {
//		if (y[i] == 'b') {
//			if (idx != -1) return -1;
//			idx = i;
//		}
//		if (y[i] != 'a' && y[i] != 'b') {
//			return -1;
//		}
//	}
//	return idx;
//}
//
//struct node {
//	int l1, l2;
//} b[N][2];
//
//node get(string y) {
//	int t = special(y);
//	return (node){t-1, (int)y.length() - t};
//}

void solve() {
	cin >> n >> q;
	forl(i, 1, n) {
		cin >> a[i][0] >> a[i][1];
	}
//	if (special(a[1][0])) {
//		forl(i, 1, n) {
//			
//		}
//	}
	while (q--) {
		ans = 0;
		cin >> t1 >> t2;
		if (t1.length() != t2.length()) {
			cout << 0 << endl;
			continue;
		}
		forl(i, 0, (int)t1.length()-1) {
			forl(j, 1, n) {
				int t = a[j][0].length();
				if (i+t - 1 > n) continue;
				if (check(i, j)) {
					replace(i, j);
				}
			}
		}
		cout << ans << endl;
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

/*
dp
tree
贪心
二分
线段树
数学 
*/
