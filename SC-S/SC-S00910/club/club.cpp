#include <bits/stdc++.h>
using namespace std;
#define int long long
#define _all(i, a, b) for (int i = (a); i <= (int)(b); i++)
bool checkA(vector<array<int, 4>> A, int n) {
	for (int i = 1; i <= n; i++)
		if (A[i][2] != 0 || A[i][3] != 0)
			return false;
	return true;
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		int n, mp;
		cin >> n, mp = n / 2;
		vector<array<int, 4>> A(n + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> A[i][j];
		if (n <= 10) {
			function<int(int, int, int, vector<int>&)> dfs = [&](int i, int j, int cost, vector<int>& cnt) {
				if (i == n) return cost;
				int mx = -1;
				for (int a = 1; a <= 3; a++)
					if (cnt[a] < n / 2) {
						cnt[a] ++;
						mx = max(mx, dfs(i + 1, a, cost + A[i + 1][a], cnt));
						cnt[a] --;
					}
				return mx;
			};
			vector<int> cnt(n + 1, 0);
			cout << dfs(0, 0, 0, cnt) << '\n';
		} else if (checkA(A, n)) {
			vector<int> temp(n + 1);
			for (int i = 1; i <= n; i++)
				temp[i] = A[i][1];
			sort(temp.begin() + 1, temp.end());
			int result = 0;
			for (int i = n; i > n / 2; i--) result += temp[i];
			cout << result << '\n';
		} else {
			vector<set<pair<int, int>>> C(4); // 每个部门的人的{满意值，编号} 
			queue<array<int, 4>> P;
			vector<int> cnt(4, 0);
			_all(i, 1, n) A[i][0] = i, P.push(A[i]);
			while(!P.empty()) {
				array<int, 4> x = P.front();
				P.pop();
				vector<array<int, 2>> temp(4);
				_all(i, 1, 3) temp[i] = {x[i], i};
				sort(temp.begin() + 1, temp.end(), greater<>());
				_all(i, 1, 3) {
					int j = temp[i][1];
					if (cnt[j] < mp) {
						C[j].insert({temp[i][0], x[0]}), cnt[j]++;
						break;
					} 
					else if (cnt[j] == mp) {
						if (C[j].begin()->first < temp[i][0]) {
							P.push(A[C[j].begin()->second]);
							C[j].erase(C[j].begin());
							C[j].insert({temp[i][0], x[0]});
							break;
						}
					}
				}
			}
			int result = 0;
			_all(i, 1, 3) for (pair<int, int> it : C[i]) result += it.first;
			cout << result << '\n';
		}
	}
	return 0;
}
