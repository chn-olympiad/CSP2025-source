#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll t, n, a[N][4], ans;
inline ll read(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
ll vis[4];
ll viss[N];
void dfs(ll step, ll sum){
	if(step == n){
		ans = max(ans, sum);
		return;
	}
	for(int i = 1 + step; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			if(vis[j] < n / 2 && !viss[i]){
				vis[j]++;
				viss[i] = 1;
				dfs(step + 1, sum + a[i][j]);
				viss[i] = 0;
				vis[j]--; 
			}
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w", stdout);
	t = read();
	while(t--){
		n = read();
		ll b = 0, c = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				a[i][j] = read();
				if(j == 3 && a[i][j] == 0) c++;
				if(j == 2 && a[i][j] == 0) b++;
			}
		}
		ans = 0;
		if(b == n && c == n){
			ll b[N];
			for(int i = 1; i <= n; i++) b[i] = a[i][1];
			sort(b + 1, b + 1 + n);
			for(int i = 1; i <= n / 2; i++){
				ans += b[n + 1 - i];
			}
			printf("%lld\n", ans);
			continue;
		}
		memset(vis, 0, sizeof(vis));
		memset(viss, 0, sizeof(viss));
		dfs(0, 0);
		printf("%lld\n", ans);
	}
	return 0;
}

