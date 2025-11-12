#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int Y = 55;
int w[N][5], p[N];
int dp[2][Y][Y][Y];
bool cmp(int a, int b){
	return a > b;
}
struct st{
	int num, id;
} q[N];
bool tmp(st a, st b){
	return a.num > b.num;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	int T; cin >> T;
	while (T--){
		memset(dp, 0, sizeof(dp));
		int n; cin >> n; 
		int sum = 0, w1 = 0, w2 = 0;
		int t = n / 2, b = 0, c = 0;
		for (int i = 1; i <= n; ++i) 
			cin >> w[i][1] >> w[i][2] >> w[i][3];
		if (b == n && c == n){
			for (int i = 1; i <= n; ++i) p[i] = w[i][1];
			sort(p + 1, p + n + 1, cmp);
			int sum = 0; 
			for (int i = 1; i <= t; ++i) sum += p[i];
			cout << sum << '\n';
		} else if (n <= 50){
			bool x = 1;
			for (int i = 1; i <= n; ++i){
				for (int j = 0; j <= t; ++j){
					for (int k = 0; k <= t; ++k){
						for (int l = 0; l <= t; ++l){
							dp[x][j][k][l] = max(max(
							(j != 0 ? dp[x ^ 1][j - 1][k][l] + w[i][1] : INT_MIN),
							(k != 0 ? dp[x ^ 1][j][k - 1][l] + w[i][2] : INT_MIN)), 
							(l != 0 ? dp[x ^ 1][j][k][l - 1] + w[i][3] : INT_MIN));
						} 
					} 
				} 
				x ^= 1;
			}
			x ^= 1; 
			int maxn = 0;
			for (int j = 0; j <= t; ++j){
				for (int k = 0; k <= t; ++k){
					for (int l = 0; l <= t; ++l){
						maxn = max(maxn, dp[x][j][k][l]);
					}
				}
			}
			cout << maxn << '\n';
		} else {
			for (int i = 1; i <= n; ++i)
				sum += w[i][3], w[i][1] -= w[i][3], w[i][2] -= w[i][3], w[i][3] = 0; 
			for (int i = 1; i <= n; ++i) q[i].num = max(w[i][1], w[i][2]), q[i].id = i;
			sort(q + 1, q + n + 1, tmp);
			for (int i = 1; i <= n; ++i){
				if (q[i].num <= 0 && i >= t) break;
				sum += q[i].num;
				w1 += (w[q[i].id][1] > w[q[i].id][2]), w2 += (w[q[i].id][2] > w[q[i].id][1]);
			}
			for (int i = 1; i <= n; ++i) p[i] = abs(w[i][1] - w[i][2]);
			sort(p + 1, p + n + 1);
			if (max(w1, w2) > t){
				int L = abs(w1 - w2) / 2;
				for (int i = 1; i <= L; ++i) sum -= p[i];
			}	
			cout << sum << '\n';
		}
	} 
}

