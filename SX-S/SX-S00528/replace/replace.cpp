#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5+5;
long long n, q, ll[N];
string s1[N], s2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (long long i = 1; i <= n; i++) {
		string ss, tt;
		cin >> ss >> tt;
		long long len = ss.size();
		ll[i] = len;
		for (long long j = 0; j < len; j++) {
			if (ss[j] == tt[j]) {
				ss[j] = ' ';
				tt[j] = ' ';
			} else
				break;
		}
		for (long long j = len - 1; j >= 0; j--) {
			if (ss[j] == tt[j]) {
				ss[j] = ' ';
				tt[j] = ' ';
			} else
				break;
		}
		for (long long j = 0; j < len; j++) {
			if (ss[j] == ' ')
				continue;
			s1[i] += ss[j];
			s2[i] += tt[j];
		}
	}
	while (q--) {
		string t1, t2, sss = "", ttt = "";
		cin >> t1 >> t2;
		long long len = t1.size(), len1 = t2.size(), ans = 0;
		if (len1 != len) {
			cout << "0\n";
			continue;
		}
		for (long long i = 0; i < len; i++) {
			if (t1[i] == t2[i])
				sss += t1[i];
			else
				break;
		}
		for (long long i = len - 1; i >= 0; i--) {
			if (t1[i] == t2[i])
				ttt = t1[i] + ttt;
			else
				break;
		}
		for (long long i = 1; i <= n; i++) {
			if (ll[i] > len)
				continue;
			if (sss + s1[i] + ttt == t1 && sss + s2[i] + ttt == t2)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
