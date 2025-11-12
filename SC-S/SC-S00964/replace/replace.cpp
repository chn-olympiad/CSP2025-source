#include<bits/stdc++.h>
#define itn int
#define pii pair<int,int>
#define fi first
#define se second
#define el cout<<"\n"
#define N 200010
#define L 5000010
//#define int long long
using namespace std;
int n, q, ans, ds, dt, nexta[L], nextb[L];
string s[N], e[N], a, b;
void sub1() {
	while (q--) {
		ans = 0;
		cin >> a >> b;
		for (int i = 0; i < a.length(); i++)
			if (a[i] != b[i]) {
				ds = i;
				break;
			}
		for (int i = a.length() - 1; ~i; i--)
			if (a[i] != b[i]) {
				dt = i;
				break;
			}
		int ld = dt - ds + 1;
		for (int i = 1; i <= n; i++) {
			if (s[i].length() < ld)continue;
			for (int j = dt - s[i].length(); j <= ds; j++) {
				for (int k = 0; k < s[i].length(); k++) {
					if (s[i][k] != a[j + k])break;
					if (e[i][k] != b[j + k])break;
					if (k == (s[i].length() - 1)) {
//						cout << s[i];
//						el;
//						cout << a;
//						el;
//						cout << j;
//						el;
						ans++;
					}
				}
			}
		}
		cout << ans;
		el;
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i] >> e[i];
	if (n <= 1010 && q <= 1010) {
		sub1();
		return 0;
	}
	while (q--) {
		ans = 0;
		cin >> a >> b;
		if (a.length() != b.length()) {
			cout << 0;
			el;
		}
		for (int i = 0; i < a.length(); i++)
			if (a[i] != b[i]) {
				ds = i;
				break;
			}
		for (int i = a.length() - 1; ~i; i--)
			if (a[i] != b[i]) {
				dt = i;
				break;
			}
		string dfa = " ", dfb = " ";
		for (int i = ds; i <= dt; i++) {
			dfa += a[i];
			dfb += b[i];
		}
		int ld = dt - ds + 1;
//		nexta[1] = 0;
		for (int i = 2; i <= ld; i++) {
			int na = nexta[i - 1];
			while (dfa[na + 1] != dfa[i]) {
				na = nexta[na];
				if (!na)break;
			}
			if (!na) {
				if (dfa[1] == dfa[i])nexta[i] = 1;
				else nexta[i] = 0;
			} else
				nexta[i] = na + 1;
			int nb = nextb[i - 1];
			while (dfb[nb + 1] != dfb[i]) {
				nb = nextb[nb];
				if (!nb)break;
			}
			if (!nb) {
				if (dfb[1] == dfb[i])nextb[i] = 1;
				else nextb[i] = 0;
			} else
				nextb[i] = nb + 1;
		}
		cout << dfa;
		el;
		for (int i = 1; i <= n; i++) {
			if (s[i].length() < ld)continue;
			cout << s[i];
			el;
			int j = 0, k = 1;
			while (j + k - 1 < s[i].length()) {
				if (s[i][j + k - 1] != dfa[k]) {
					if (nexta[k]) {
						j += (k - nexta[k]);
						k = nexta[k];
					} else {
						j++;
						k = 1;
					}
					continue;
				}
				if (k == ld) {
					ans++;
					k = 1;
					j++;
					continue;
				}
				k++;
			}
		}
		cout << ans;
		el;
	}
	return 0;
}