#include <bits/stdc++.h>
#define ll long long
#define f_1(i,a,b) for(ll i=a;i<=b;i++)
#define f_0(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;
ll n, q;
string s1[200010], s2[200010], t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	f_1(i, 1, n) cin >> s1[i] >> s2[i];
	f_1(i, 1, q) {
		cin >> t1 >> t2;
		int ans = 0;
		string r = t1;
		f_1(j, 1, n) {
			t1 = r;
			int wh = t1.find(s1[j]);
			if (wh == -1)
				continue;
			t1.replace(wh, s1[j].size(), s2[j]);
			if (t1 != t2)
				continue;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}