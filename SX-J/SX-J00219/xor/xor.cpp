#include <bits/stdc++.h>
using namespace std;
int a[500010], dp[5000][5000];
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	if(k <= 1 and n > 1000){
//		if(k == 1){
//			for(int i = 1;i <= n;i++){
//
//			}
//		}
//	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][i] = a[i];

		for (int j = i; j <= n; j++) {
			dp[i][j] = dp[i][j - 1] xor a[j];
			if (dp[i][j] == k)
				v.push_back({j, i});
		}
//		cout << endl;
	}
	sort(v.begin(), v.end());
	int t = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		if (t >= (int)v.size())
			break;
		sum++;
//		cout << v[t].second << ' ' << v[t].first << endl;
		int endd = v[t].first;
		int tt = v.size();
		for (int j = i + 1; j < (int)v.size(); j++)
			if (v[j].second > endd and v[j].first < (tt == (int)v.size() ? 0x7f7f7f7f : v[tt].first))
				tt = j;
		t = tt;
//		cout << tt << endl;
	}
	cout << sum;
	return 0;
}
