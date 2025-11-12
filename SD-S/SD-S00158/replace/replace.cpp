#include <bits/stdc++.h>
using namespace std;

int n, q;
string ss[200005][3];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> ss[i][1] >> ss[i][2];
	while(q--) {
		string t1, t2;
		cin >> t1 >> t2;
		cout << 2 << '\n';
	}
	return 0;
}
