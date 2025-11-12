#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int t;
struct {
	ll w;
	int num1, num2, num3;
} dp[N][4];

struct Peo{
	ll a1, a2, a3;
} pep[N];

bool cmp(Peo &a, Peo &b) {
	if (a.a1 > b.a1) {
		return true;
	}
	if (a.a2 > b.a2) {
		return true;
	}
	if (a.a3 > b.a3) {
		return true;
	}
}

bool cmp1(Peo &a, Peo &b) {
	if(a.a1 > b.a1) {
		return true;
	}
	return a.a2 < b.a2;
}

void slove() {
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	bool flag = false;
	bool flag1 = false;
	for (int i = 0; i < n; ++i) {
		cin >> pep[i].a1 >> pep[i].a2 >> pep[i].a3;
		flag = (pep[i].a1 == 0 &&  pep[i].a3 == 0) || flag;
		flag1 = (pep[i].a3 == 0) || flag1;
	}
	if (flag) {
		sort(pep, pep + n, cmp);
		int ans = 0;
		for (int i = 0; i < n/2; ++i) {
			ans += pep[i].a2;
		}
		cout << ans << '\n';
		return ;
	}
	if (flag1) {
		sort(pep, pep + n, cmp1);
		int ans = 0;
		for (int i = 0; i < n/2; ++i) {
			ans += pep[i].a1;
		}	
		for (int i = n/2; i < n; ++i) {
			ans += pep[i].a2;
		}
		cout << ans << endl;
		return ;
	}
	sort(pep, pep + n, cmp);
	dp[0][0] = {pep[0].a1, 1, 0, 0};
	dp[0][1] = {pep[0].a2, 0, 1, 0};
	dp[0][2] = {pep[0].a3, 0, 0, 1};
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (dp[i - 1][j].num1 < n/2 && dp[i - 1][j].w + pep[i].a1 > dp[i][0].w) {
				dp[i][0].w = dp[i - 1][j].w + pep[i].a1;
				dp[i][0].num1 = dp[i - 1][j].num1 + 1;
				dp[i][0].num2 = dp[i - 1][j].num2;
				dp[i][0].num3 = dp[i - 1][j].num3;
			}
			if (dp[i - 1][j].num2 < n/2 && dp[i - 1][j].w + pep[i].a2 > dp[i][1].w) {
				dp[i][1].w = dp[i - 1][j].w + pep[i].a2;
				dp[i][1].num2 = dp[i - 1][j].num2 + 1;
				dp[i][1].num1 = dp[i - 1][j].num1;
				dp[i][1].num3 = dp[i - 1][j].num3;
			}
			if (dp[i - 1][j].num3 < n/2 && dp[i - 1][j].w + pep[i].a3 > dp[i][2].w) {
				dp[i][2].w = dp[i - 1][j].w + pep[i].a3;
				dp[i][2].num3 = dp[i - 1][j].num3 + 1;
				dp[i][2].num1 = dp[i - 1][j].num1;
				dp[i][2].num2 = dp[i - 1][j].num2;
			}
		} 
	}
	ll ans = 0;
	for (int i = 0; i < 3; ++i) {
		ans = max(dp[n - 1][i].w, ans);
	}
	
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < 3; ++j) {
//			cout << dp[i][j].w << " n1 " << dp[i][j].num1 << " n2 " << dp[i][j].num2 << " n3 " << dp[i][j].num3 << "///";
//		}
//		cout << endl;
//	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	cin >> t;
	while (t--) {
		slove();
	}
	return 0;
}
