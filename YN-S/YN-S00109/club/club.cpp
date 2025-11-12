#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c;
};
node no[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int maxN = n / 2;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> no[i].a >> no[i].b >> no[i].c;
			ans = max((no[i].a, no[i].b), no[i].c);
		}
		cout << ans << endl;
	}
	return 0;
}