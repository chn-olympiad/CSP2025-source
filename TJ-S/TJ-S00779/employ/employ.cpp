#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 20, mod = 998244353;

int n, m, c[N], s[N]; string str;
ll ans = 0, fac[N]; 

bool vis[N];

int a[N];

inline void dfs(int dep, int los, int cnt)
{
	if(cnt == m) {
		ans+=fac[n-dep+1]; if(ans > mod) ans -= mod;
//		printf("(%d %d %d)\n", dep, los, cnt);
//		for(int i = 1; i <= n; i++) {
//			printf("%d ", a[i]);
//		}
//		printf("\n");
		return;
	}
	if(dep == n+1) {
		
	}

	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
//		printf("at (%d %d %d), chose %d, vis%d\n", dep, los, cnt, i, vis[i]);
		vis[i] = true; a[dep] = i;
		if(los >= c[i] || !s[dep]) dfs(dep+1,los+1,cnt);
		else dfs(dep+1,los,cnt+1);
		vis[i] = false;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m >> str;
	fac[0] = fac[1] = 1;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		s[i] = str[i-1]-'0';
		fac[i] = fac[i-1]*i;
	}
	dfs(1,0,0);
	printf("%lld\n", ans);
		
	
	return 0;
}

//check WA/RE/MLE/TLE

