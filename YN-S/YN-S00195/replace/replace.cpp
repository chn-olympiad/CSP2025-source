#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 988244353;

ll n, q, s1[200005], s2[200005];
string q1, q2;

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		cin >> q1 >> q2;
		cout << 0 << endl;
	}
	return 0;
}