#include <bits/stdc++.h>
using namespace std;
int n, an;
int h[5010];
int mod = 998244353;
vector<int> li;

void ans(int t, int point, int all) {
	all += h[point];
	if (t == 1) {
		if (all > h[point] ) {
			an++;
			
		}
		return;
	}
	for (int i = point; i < n; i++) {

		ans(t - 1, i + 1, all);
	}

}


int main() {
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	sort(h + 1, h + n + 1);
	for (int i = 3; i <= n - 1; i++) {
		ans(i, 1, 0);
	}
	cout << an % mod;
	return 0;
}
