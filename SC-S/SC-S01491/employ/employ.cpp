#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 9, MOD = 998244353;
int tmp[N], c[N], n, m, ans;
bool dif[N], flag[N];
void dfs(int now){
	if(now == n + 1){
		int cnt = 0, res = 0;
		for(int i = 1; i <= n; i++){
			if(cnt >= c[tmp[i]] || !dif[i])
				cnt++;
			else
				res++;
		}
		if(res >= m)
			ans = (ans + 1) % MOD;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!flag[i]){
			flag[i] = true;
			tmp[now] = i;
			dfs(now + 1);
			flag[i] = false;
		}
	}
}
char ch[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", ch + 1);
	for(int i = 1; i <= n; i++)
		dif[i] = ch[i] - '0';
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	dfs(1);
	printf("%d", ans);
	return 0;
}