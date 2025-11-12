#include<bits/stdc++.h>

using namespace std;

int n;
long long cnt = 0;
int a[5050];
int f[5050][5050];
const int MOD = 998244353;

int fas(int i, int j) {
	if (f[i][j] != 0) return f[i][j];
	if (i == j) {
		f[i][j] = a[i];
		return a[i];
	}
	f[i][j] = f[i][j-1] + a[j];
	return fas(i, j-1) + a[j];
}

void dfs(int x, int sum,int issd) {
	if (x > n) return;
	if(sum - a[x] > a[x] &&issd >= 3) {
		//cout << x << " " << issd << " " << sum << endl;
		cnt++;
	}
	for (int i = x+1; i <= n; i++) {
		dfs(i, sum+a[i], issd+1);
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	
	int ifs = 0;
	bool f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) ifs ++;
	}
	
	sort(a+1,a+n+1);
	
	if (a[n] <= 1) {
		int ans = 0;
		if (ifs <= 3) cout << 0;
		else {
			for (int i = 0; i < ifs-2; i++) {
				ans = i + 1 + ans;
			}
			cout << ans;
		}
		return 0;
	}

	for (int i = 1; i <= n; i++) dfs(i, a[i], 1);
	
	cout << cnt % MOD << endl;
	return 0;
}
