#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6;
string s;
int a[N], cnt;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			cnt++;
		}
	}
	sort(a, a + s.size() + 1, cmp);
	for (int i = 0; i < cnt; i++) {
		cout << a[i];
	}
	return 0;
}
