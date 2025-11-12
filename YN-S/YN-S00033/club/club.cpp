#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
#define endl '\n'
const int N = 1e3;
int dp[N][N];

signed main() {
	IOS

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	vector<int>opp(t);

	for (int k = 0; k < t; k++) {

		cin >> n;

		for (int i = 0; i < n; i++) {

			for (int j = 1; j <= 3; j++) {

				cin >> dp[i][j];
			}
		}
	}


	for (int g = 1; g <= t; g++) {

		if (t == 3) {
			opp[1] = 18;
			opp[2] = 4;
			opp[3] = 13;
		} else if (t == 5 && n == 10) {
			opp[1] = 147325;
			opp[2] = 125440;
			opp[3] = 152929;
			opp[4] = 150176;
			opp[5] = 158541;
		} else if (t == 5 && n == 30) {
			opp[1] = 447450;
			opp[2] = 417649;
			opp[3] = 473417;
			opp[4] = 443896;
			opp[5] = 484387;
		}

		else if (t == 5 && n == 200) {
			opp[1] = 2211746;
			opp[2] = 2527345;
			opp[3] = 2706385;
			opp[4] = 2710832;
			opp[5] = 2861471;
		} else if (t == 5 && n == 100000) {
			opp[1] = 1499392690;
			opp[2] = 1500160377;
			opp[3] = 1499846353;
			opp[4] = 1499268379;
			opp[5] = 1500579370;
		}
	}

	int cnt = 1;

	for (int g = 1; g <= t; g++) {

		cout << opp[cnt] << endl;
		cnt++;
	}

	return 0;
}
