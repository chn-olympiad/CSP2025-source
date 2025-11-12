#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 555, mod = 998244353;
int s[N], c[N];
int tp[N];
bool vis[N];

int n, m;
int tot;
int ans;

void dfs(int x){
	if(x == n + 1){
		int res = 0, have = 0;
		
		for (int i = 1; i <= n; i++){
			if (res >= c[tp[i]]){
				res ++;
				continue;
			}
			
			if (s[i] == 0) res++;
			else		   have++;
		} 
		
		if (have >= m) ans++;
		ans %= mod;
		
		return;
	}
	
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		
		vis[i] = true;		
		tp[x] = i;
		
		dfs(x + 1);
	
		vis[i] = false;
	}
	
	return;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%lld%lld", &n, &m);
	
	for (int i = 1; i <= n; i++){
		char c = getchar();
		
		while(c != '0' && c != '1') c = getchar();
		
		s[i] = c - '0';
	}	
	
	for (int i = 1; i <= n; i++){
		scanf("%lld", &c[i]);
	}

	dfs(1);
	
	printf("%lld", ans);
		
	return 0;
}