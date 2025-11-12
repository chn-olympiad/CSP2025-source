#include<bits/stdc++.h>
using namespace std;
const long long P = 998244353;
int n, m, c[510], b[510], r[510];
long long ans = 0;
char s[510];
void dfs(int i) {
	if(i == n + 1) {
		int cnt = 0, lu = 0;
		for(int j = 1; j <= n; j++) {
			if(cnt >= c[b[j]]) {
				cnt++;
				continue;
			}
			if(s[j] == '0') {
				cnt++;
			} else {
				lu++;
			}
		}
		if(lu >= m) {
			ans++;
		}
		return;
	}
	for(int j = 1; j <= n; j++) {
		if(!r[j]) {
			r[j] = 1, b[i] = j;
			dfs(i + 1);
			r[j] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}//161088479
