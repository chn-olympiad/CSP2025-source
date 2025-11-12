#include <bits/stdc++.h>
using namespace std;

/*
employ
Let's just try 40 pts or even fewer. I'm so tired.
*/

constexpr int N = 800, NS = 20, ST = (1<<18)+5;
constexpr long long MODER = 998244353;
string s;
int c[N];
int n, m;
long long dp[ST][NS];	// dp[i][j]: ST - person unselected
// NS - current employed number of candidates

long long search(int state, int cds) {
	if (dp[state][cds] >= 0) return dp[state][cds];
	long long ans = 0ll;
	int past = 0;
	for (int i = 1; i <= n; i++) {
		if ((state&(1<<(i-1)))) {
			past++;
		}
	}
	if (past == n) {
		if (cds >= m) return dp[state][cds] = 1ll;
		else return dp[state][cds] = 0ll;
	}
	int current_rj = past - cds;	// current number of rejection
	for (int i = 1; i <= n; i++) {
		if (!(state&(1<<(i-1)))) {
			// Not placed, consider somewhere
			if (s[past] == '0' || current_rj >= c[i]) {
				ans = (ans + search(state | (1<<(i-1)), cds)) % MODER;
			} else {
				ans = (ans + search(state | (1<<(i-1)), cds + 1)) % MODER;
			}
		}
	}
	return dp[state][cds] = ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, -1, sizeof(dp));
	
	cin>>n>>m;
	cin>>s;
	for (int i = 1; i <= n; i++) cin>>c[i];
	if (n <= 18) {
		cout<<search(0, 0)<<endl;
	} else {
		long long res = 1ll;
		for (int i = 1; i <= n; i++) res = (res * i) % MODER;
		cout<<res<<endl;
	}
	
	return 0;
}