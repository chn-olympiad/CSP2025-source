#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], ans;
string s[500010];
string b[500010];//求前缀和 异或和[r,l]=[1,l]-[1,r];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	string ans1 = "";
	int kk = k;
	if (k == 0)
		ans1 = "0";
	while (k != 0) {
		ans1 = to_string(k % 2)   + ans1;
		k = k / 2;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		string r = "";
		int x = a[i];
		if (x == 0)
			r = "0";
		while (x != 0) {
			r = to_string(x % 2)   + r;
			x = x / 2;
		}
		int cha = s[i - 1].size() - r.size();
		if ( cha > 0) {
			for (int j = 1; j <= cha; j++) {
				r = "0" + r;
			}
		} else {
			for (int j = 1; j <= r.size() - s[i - 1].size(); j++) {
				s[i - 1] = "0" + s[i - 1];
			}
		}
		s[i] = r;
	}
	b[1] = s[1];
	for (int i = 2; i <= n; i++) {
		string r = "";
		int cha = b[i - 1].size() - s[i].size();
		if ( cha > 0) {
			for (int j = 1; j <= cha; j++) {
				s[i] = "0" + s[i];
			}
		} else {
			for (int j = 1; j <= s[i].size() - b[i - 1].size(); j++) {
				b[i - 1] = "0" + b[i - 1];
			}
		}
		for (int j = 0; j <= s[i].size() - 1; j++) {
			if (b[i - 1][j] == s[i][j]) {
				r = r + "0";
			} else {
				r = r + "1";
			}
		}
		b[i] = r;
	}
	int l = 1;
	while (l <= n) {
		if (a[l] == kk) {
			ans++;
			l++;
		} else {
			for (int r = l + 1; r <= n; r++) {
				string rr = "";
				int cha = b[r].size() - b[l - 1].size();
				if ( cha > 0) {
					for (int j = 1; j <= cha; j++) {
						b[l - 1] = "0" + b[l - 1];
					}
				} else {
					for (int j = 1; j <= b[l - 1].size() - b[r].size(); j++) {
						b[r] = "0" + b[r];
					}
				}
				for (int j = 0; j <= b[r].size() - 1; j++) {
					if (b[l - 1][j] == b[r][j]) {
						rr = rr + "0";
					} else {
						rr = rr + "1";
					}
				}
				cha = rr.size() - ans1.size();
				if ( cha > 0) {
					for (int j = 1; j <= cha; j++) {
						ans1 = "0" + ans1;
					}
				} else {
					for (int j = 1; j <= ans1.size() - rr.size(); j++) {
						rr = "0" + rr;
					}
				}
//			cout << l << ' ' << r;
				if (rr == ans1) {

					ans++;
					l = r + 1;
//				cout<<<<endl;;
					break;
				}
			}
		}

	}

	cout << ans ;
	return 0;
}