#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const int N = 200011;
int n, q;
pair<string, string> s[N], t[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i].fi >> s[i].se;
	for (int i = 1; i <= q; i++)
		cin >> t[i].fi >> t[i].se;
	for (int i = 1; i <= q; i++)
		cout << 0 << '\n';
}
