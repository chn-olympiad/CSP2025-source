#include <bits/stdc++.h>
#define int long long
using namespace std;

int t = 1;

const int N = 2e5 + 10;
int n;
string S[N][2];
int Q;
string T[2];

void solve() {
	cin >> n >> Q;
	for(int i = 1; i <= n; i ++) {
		cin >> S[i][0] >> S[i][1];
	}
	
	while(Q --) {
		cin >> T[0] >> T[1];
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	while(t --) {
		solve();
	}
	return 0;
}
