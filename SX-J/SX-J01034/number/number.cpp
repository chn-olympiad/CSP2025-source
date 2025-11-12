#include <bits/stdc++.h>
#define ll long long
const ll N = 1e6+10;
using namespace std;
string s;
ll a[N];
ll cnt = 1;

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ll b = s[i] - '0';
			a[cnt] = b;
			cnt++;
		}
	}
	sort(a + 1, a + cnt, cmp);
	for (ll i = 1; i < cnt; i++) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
