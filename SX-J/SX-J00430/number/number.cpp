#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+10;

bool cmp(ll a, ll b) {
	return a > b;
}
ll a[N];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	ll t = 1, cnt = 0;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[t] = s[i] - '0';
			cnt++, t++;
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (ll i = 1; i <= cnt; i++) {
		cout << a[i];
	}
	return 0;
}
