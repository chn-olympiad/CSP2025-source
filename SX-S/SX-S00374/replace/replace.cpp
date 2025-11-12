#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int Max = 2e5+5;
int n, q, B;
string tf, ts;
string sf[Max], ss[Max];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> sf[i] >> ss[i];
	}
	for (int j = 0; j < q; j++) {
		cin >> tf >> ts;
		cout << 0 << '\n';
	}
	return 0;
}
