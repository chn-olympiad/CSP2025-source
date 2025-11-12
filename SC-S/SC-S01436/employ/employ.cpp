#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>; 

#define lson (k << 1)
#define rson (k << 1 | 1)
#define endl '\n'

const int mod = 998244353;
const int N = 3 + 500;

int n, m;
char s[N];
int c[N];


void case_1_2() {
	vector<int> p;
	for (int i = 1; i <= n; ++i) {
		p.push_back(i);
	}
	int ans = 0;
	do {
		
		int cnt = 0;
		int cnt2 = 0;
		
		int j = 1;
		
		for (auto i : p) {
			if (s[j] == '1' && cnt2 < c[i]) {
				++cnt;
			} else {
				++cnt2;
			}
//			if (vector<int>{2, 1, 3} == p) {
//				cout << " @@@ " << cnt << " " << cnt2 << endl;
//				cout << " &&& " << i << ' ' << j << "  " << s[j] << " " << c[i] << endl;
//			}
			++j; 
		}
//		if (vector<int>{2, 1, 3} == p) {
//			cout << " -- " << cnt << " " << cnt2 << endl;
//		}
		if (cnt >= m) {
//			for (auto i : p) {
//				cout << i << "  " ;
//			}
//			cout << endl;
			++ans;
		}
	} while (next_permutation(p.begin(), p.end()));
	
	cout << ans << endl;
}

void case_3_5() {
	vector<vector<int>> dp(n + 1, vector<int>(1 << n));
	vector<int> bin(1 << n);
	for (int i = 1; i < 1 << n; ++i) {
		bin[i] = bin[i / 2] + (i % 2);
	}
	dp[0][0] = 1;
	for (int i = 0; i < 1 << n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i >> k & 1) {
					continue;
				}
				if (!dp[j][i]) {
					continue;
				}
				// bin[i] person 
				
				// j 
				if (j < c[k + 1] && s[bin[i] + 1] == '1') {
					dp[j + 1][i | (1 << k)] += dp[j][i];
					dp[j + 1][i | (1 << k)] %= mod;
				} else {
					dp[j][i | (1 << k)] += dp[j][i];
					dp[j][i | (1 << k)] %= mod;
				}
			}
		}
	}
	LL ans = 0;
	for (int i = m; i <= n; ++i) {
		ans += dp[i][(1 << n) - 1];
	}
	cout << ans % mod << endl;
}


int main() {
//	freopen("employ1.in", "r", stdin);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s + 1;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
//	case_3_5();
//	
//	return 0;
	if (n <= 10) {
		case_1_2();
		return 0;
	}
	
	case_3_5();
	
	
	return 0;
}