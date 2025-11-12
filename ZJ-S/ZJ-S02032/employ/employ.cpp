#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL MOD = 998244353;
const int N = 505;
int n, m, c[N];
string s;
bool check() {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '0') return 0;
	}
	return 1;
}
void spe_case_12_14() {
	int p = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') {
			p = i + 1;
			break;
		}
	}
	if(!p) {
		printf("0\n");
		return;
	}
	LL ans = 0;
	for(int i = 1; i <= n; i++) if(c[i] >= p) ans++;
	for(int i = 1; i <= n - 1; i++) ans = ans * i % MOD;
	printf("%d\n", ans);
}
void spe_case_15() {
	if(!check()) {
		printf("0\n");
		return;
	}
	sort(c + 1, c + 1 + n);
	for(int i = 1; i <= n; i++) {
		if(c[i] < i) {
			printf("0\n");
			return;
		}
	}
} 
void spe_case_6_8_16_17() {
	LL ans = 1LL;
	for(int i = 1; i <= n; i++) ans = ans * i % MOD;
	printf("%lld\n", ans);
}
int vis[N], res = 0;
void dfs(int cur, int ab) {
	if(n - ab < m) return;
	if(cur > n) {
		res++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		if(ab >= c[i] || s[cur - 1] == '0') dfs(cur + 1, ab + 1);
		else dfs(cur + 1, ab);
		vis[i] = 0;
	}
}
void spe_case_1_2() {
	memset(vis, 0, sizeof(vis));
	dfs(1, 0);
	printf("%d\n", res);
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	cin >> s;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		if(c[i] == 0) cnt++;
	}
	if(n - cnt < m) {
		printf("0\n");
		return 0;
	}
	if(n <= 10) {
		spe_case_1_2();
	}else if(m == 1) {
		spe_case_12_14();
	}else if(m == n) {
		spe_case_15();
	}else if(check()) {
		spe_case_6_8_16_17();
	}
	return 0;
}
