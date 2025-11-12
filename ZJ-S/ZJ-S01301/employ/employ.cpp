//Fight until the end like I promised to
#include<bits/stdc++.h>
#define AK 0
#define int long long
#define D(x) cout<<#x<<": "<<x<<'\n'
#define De(x) cout<<#x<<": "<<x<<' '
#define ctn continue
#define brk break
#define space putchar(' ')
#define enter putchar('\n')
#define pii pair<int,int>
#define mkp make_pair
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
inline int read(){
	bool f = 0;
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = 1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();}
	return f ? -x : x;
}
const int N = 2e5 + 7, mod = 1e9 + 7;
int n, m, ans;
int a[N], c[N];
int b[N];
bool vis[N];
inline void dfs(int d){
	if(d == n + 1){
		int sum = 0, cnt = 0;
		up(1, n, i){
			if(sum >= c[b[i]]){
				sum++;
				ctn;
			}
			if(a[i]) cnt++;
			else sum++;
		}
		if(cnt >= m) ans++;
		return;
	}
	up(1, n, i){
		if(!vis[i]){
			vis[i] = 1;
			b[d] = i;
			dfs(d + 1);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	up(1, n, i) scanf("%1lld", &a[i]);
	up(1, n, i) c[i] = read();
	dfs(1);
	printf("%lld\n", ans % 998244353);
	return AK;
}
