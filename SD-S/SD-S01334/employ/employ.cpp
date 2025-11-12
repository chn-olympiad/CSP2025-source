#include <bits/stdc++.h>

#define int long long 

constexpr int N = 505,mod = 998244353;
int m,n,c[N],p[N],ans = 0;
char s[N];
bool vs[N];
void dfs(int x){
	if(x > n){
		int cnt = 0;
		for(int i = 1; i <= n; ++ i){
			if(cnt >= c[p[i]]){
				++ cnt;
			}else{
				if(s[i] == '0') ++ cnt;
			}
		}
		if(cnt <= n - m) ++ ans;
		return;
	}
	for(int i = 1; i <= n; ++ i){
		if(!vs[i]){
			vs[i] = 1;
			p[x] = i;
			dfs(x + 1);
			vs[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		std::cin >> s[i];
	}
	for(int i = 1; i <= n; ++ i){
		std::cin >> c[i];
	}
	if(n <= 10){
		dfs(1);
		std::cout << ans << '\n';
	}else{
		
	}
	return 0;
}
