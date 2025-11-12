#include <bits/stdc++.h>
using namespace std;

bool vis[100010];

int main() {
	//priority_queue<int, vector<int>, greater<int>> pq;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		priority_queue<pair<int, int>, vector<pair<int, int>>> A, B, C;
		for (int i = 1; i <= n; i ++) {
			int a, b, c;
			cin >> a >> b >> c;
			A.push({a, i}), B.push({b, i}), C.push({c, i});
		}

		memset(vis, false, sizeof(vis));
		int cntA = 0;
		int cntB = 0;
		int cntC = 0;
		int ans = 0;
		while (cntA + cntB + cntC <= n && !A.empty() && !B.empty() && !C.empty()) {

			auto nowA = A.top();
			//cout << "A:" << nowA.first << ' ' << nowA.second << ' ' << cntA << endl;
			//cout << n / 2 << endl;
			//cout << "vis:" << endl;
//			for (int i = 1; i <= n; i ++) {
//				cout << vis[i] << ' ';
//			}
			//cout << endl;
			if (!vis[nowA.second] && cntA <= n / 2) {
				//cout << "A部门加一个" << endl;
				ans += nowA.first;
				vis[nowA.second] = true;
				cntA ++;
			}
			A.pop();

			auto nowB = B.top();
			if (!vis[nowB.second] && cntB <= n / 2) {
				//cout << "B部门加一个" << endl;
				ans += nowB.first;
				vis[nowB.second] = true;
				cntB ++;
			}
			B.pop();

			auto nowC = C.top();
			if (!vis[nowC.second] && cntC <= n / 2) {
				//cout << "C部门加一个" << endl;
				ans += nowC.first;
				vis[nowC.second] = true;
				cntC ++;
			}
			C.pop();

			//cout << ans << endl;
		}

		cout << ans;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}