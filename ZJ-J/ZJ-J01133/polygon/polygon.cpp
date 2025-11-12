#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 5010;
const ll mod = 998244353;

ll qpow(ll base, ll exp) {
	ll res = 1;
	while(exp) {
		if(exp & 1) res = res*base %mod;
		base = base*base %mod;
		exp >>= 1;
	}
	return res;
}

int n,m;
int a[N];

ll dp[N], dpsum[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	n = read();
	for(int i=1; i<=n; i++) a[i] = read(), m = max(m, a[i]);
	
	sort(a+1, a+1+n);
	
	ll ans = 0;
	
	dp[0] = dpsum[0] = 1;
	for(int j=1; j<=m; j++) dpsum[j] = dpsum[j-1] + dp[j];
	
	for(int i=1; i<=n; i++) {
		ans += qpow(2, i-1);
		ans -= dpsum[a[i]];
		ans = (ans%mod + mod)%mod;
		
		for(int j=m; j>=a[i]; j--)
			dp[j] += dp[j-a[i]], dp[j] %= mod;
			
		for(int j=a[i]; j<=m; j++)
			dpsum[j] = (dpsum[j-1] + dp[j]) %mod;
	}
	
	write(ans);
	
	/*
	//freopen()
	//feropen()
	*catch

	8:15 arrive at here
	8:45 finish reading each problem, finish writing high-speed reading and writing, finish T1
	9:00 some problems appeared. I lost all my code. This minded : never use ctrl+z when you were not coding.
	9:30 finish T1 and T2 AGAIN;
	9:55 finish T3
	10:20 finish T4. AK?????????? I AK CSP-J????
	10:25-10:30 go to toilet
	10:40-10:50 write this thing
	I think I need to check my code now. bye
	11:45 finish checking! I just AK ed CSP-J.

	Luogu: 993941 (xingchen666)
	*/
	
	return 0;
}