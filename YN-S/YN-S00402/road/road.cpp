#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e4 + 4;

struct cities {
	pair<int, int> to;
} ci[N];
int xiang[11][N];//乡村
int n, m, k;

int main () {
	IOS
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int kl1, kl2, kl3;

	for (int i = 1; i <= n; i++) {

		cin >> kl1 >> kl2 >> kl3;
		ci[kl1].to.first = kl2; //通往
		ci[kl1].to.second = kl3; //路费
		ci[kl2].to.first = kl1; //通往
		ci[kl1].to.second = kl3; //路费
	}

	ll ans = 1e18;

	for (int i = 1; i <= k; i++) {

		cin >> xiang[i][0]; //j=0的是城市化费用
		ll sum = 0;

		for (int j = 1; j <= n; j++) {

			cin >> xiang[i][j]; //通往n个城市的路费
			sum += xiang[i][j];
		}

		ans = min(ans, sum);
	}

	cout << ans << endl;
	return 0;
}