#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e+3 + 3;
const int mod = 998244353;
int dp[maxn], f[maxn], a[maxn];

inline ll read() {
    ll ref = 0;
    bool f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-')
            f = 0;
        ch = getchar();
    }
    while(isdigit(ch))
		ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
	return (f ? ref : -ref); 
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n = read();
	f[0] = 1;
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = 5001; j > a[i]; j--)
			if((dp[min(5001, a[i] + j)] += f[j]) >= mod) dp[min(5001, a[i] + j)] -= mod;
		for(int j = 5001; j >= 0; j--)
			if((f[min(5001, a[i] + j)] += f[j]) >= mod) f[min(5001, a[i] + j)] -= mod;
//		for(int j = 0; j <= 15; j++) cout << f[j] << ' ';
//		cout << endl;
//		for(int j = 0; j <= 15; j++) cout << dp[j] << ' ';
//		cout << endl;
//		cout << endl;
	}
	int answer = 0;
	for(int i = 0; i <= 5001; i++) 
		if((answer += dp[i]) >= mod) answer -= mod;
	cout << answer;

    return 0;
}
