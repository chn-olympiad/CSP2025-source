#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 505;
const int mod = 998244353;
char str[maxn];
int c[maxn];
int dp[1 << 20][20];
vector<int> vec[maxn];

inline ll read() {
	ll ref = 0;
	bool f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = 0;
		ch = getchar();
	}
	while(isdigit(ch))
		ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
	return (f ? ref : -ref);
} 

inline int num(int n) {
	n = ((n & 0xaaaaaaaa) >> 1) + (n & 0x55555555);
	n = ((n & 0xcccccccc) >> 2) + (n & 0x33333333);
	n = ((n & 0xf0f0f0f0) >> 4) + (n & 0x0f0f0f0f);
	n = ((n & 0xff00ff00) >> 8) + (n & 0x00ff00ff);
	n = ((n & 0xffff0000) >> 16) + (n & 0x000ffff);
	return n;
}

ll fac(int n) {
	if(n == 0) return 1;
	return fac(n - 1) * n % mod;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n = read(), m = read();
	scanf("%s", str);
	for(int i = 0; i < n; i++) c[i] = read();
	if(n <= 20) {
		for(int i = 0; i < 1 << n; i++) vec[num(i)].push_back(i);
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			for(int j : vec[i - 1]) {
				for(int k = 0; k < i; k++) {
					for(int l = 0; l < n; l++) {
						if(j >> l & 1) continue;
						dp[j | (1 << l)][k + (str[i - 1] == '1' && i - k - 1 < c[l])] += dp[j][k];
					}
				}
			}
		}
//		for(int i = 1; i <= n; i++) 
//			for(int j : vec[i]) {
//				for(int k = 0; k <= i; k++) cout << dp[j][k] << ' ';
//				cout << endl;
//			}
		ll answer = 0;
		for(int i = m; i <= n; i++) answer += dp[(1 << n) - 1][i];
		cout << answer;
	}
	else if(m == 1) {
		int i = 0, cnt = 0;
		while(str[i] == '0') i++;
		for(int i = 0; i < n; i++) if(c[i] > i) cnt++;
		cout << cnt * fac(n - 1) % mod;
	} else if(m == n) {
		bool flag = 0;
		for(int i = 0; i < n; i++) if(str[i] == '0' || c[i] == 0) flag = 1;
		cout << (flag ? 0 : fac(n));
	} 
	else {
		int cnt = 0;
		for(int i = 0; i < n; i++) if(str[i] == '0' || c[i] == 0) cnt++;
		cout << (m + cnt <= n ? fac(n) : 0);
	}

	return 0;
}
