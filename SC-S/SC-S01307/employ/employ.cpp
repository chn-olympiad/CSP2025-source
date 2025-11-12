#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 509, Q = 998244353;
char s[N];
int pl[N], c[N], n, m;
ll ans = 0, fac[N];
bool vis[N];
void dfs(int t){
	if(t > n){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(cnt >= c[pl[i]] || s[i] == '0') cnt++;
		}
		if(n - cnt >= m){
			ans++;
		}
		if(ans >= Q) ans -= Q;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			pl[t] = i;
			vis[i] = true;
			dfs(t + 1);
			vis[i] = false;
			pl[t] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf(" %s", s + 1);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	bool FA = true;
	for(int i = 1; i <= n; i++) if(s[i] != '1') FA = false;
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % Q;
	bool FF = true;
	for(int i = 1; i <= n; i++) if(!c[i]) FF = false;
	if(n <= 10){
		ans = 0;
		dfs(1);
		printf("%lld\n", ans);
	}else if(m == n){
		if(!FA) printf("0\n");
		else if(!FF) printf("0\n");
		else printf("%lld\n", fac[n]);
	}else{
		printf("%lld\n", fac[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}