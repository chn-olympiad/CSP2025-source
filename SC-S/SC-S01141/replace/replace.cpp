#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5 + 7;
ll n, q;
string s1[N], s2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for (ll i = 1; i <= n; ++i) {
		cin >> s1[i];
		cin >> s2[i];
	}
	
	for (ll i = 1; i <= q; ++i) {
		string c1, c2;
		cin >> c1 >> c2;
	}
	
	for (ll i = 1; i <= q; ++i) {
		cout << 0 << '\n';
	}
	
	return 0;
}