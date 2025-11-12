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

const int N = 510;
const ll mod = 998244353;

ll jc[N];

int n,m;
char s[N];
int c[N];

ll ans = 0;

bool vis[N];
int p[N];

void dfs(int x) {
	if(x > n) {
		int failed_cnt = 0;
		int get_cnt = 0;
		
		for(int i=1; i<=n; i++) {
			if(failed_cnt >= c[p[i]] or s[i] == '0') failed_cnt++;
			else get_cnt++;
		}
		
		if(get_cnt >= m) ans++;
		return ;
	}
	
	for(int i=1; i<=n; i++)
		if(!vis[i]) {
			vis[i] = 1;
			p[x] = i;
			dfs(x+1);
			vis[i] = 0;
		}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	jc[0] = 1; for(ll i=1; i<=500; i++) jc[i] = jc[i-1] * i %mod;
	
	n = read(), m = read();
	scanf("%s", s+1);
	for(int i=1; i<=n; i++) c[i] = read();
	
	if(n <= 20) {
		dfs(1);
		write(ans);
		return 0;
	}
	
	write(jc[m]);
	
	return 0;
}