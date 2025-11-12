#include<bits/stdc++.h>
//#undef STDIO
const int N = 510, MOD = 998244353;
int n, m, c[N];
char s[N];
namespace bf{
	int b[N];
	void solve(){
		for(int i = 1; i <= n; i++){
			b[i] = i;
		}
		int ans = 0;
		do{
			int cnt = 0;
			for(int i = 1; i <= n; i++){
				if(cnt >= c[b[i]] || s[i] == '0') cnt++;
			}
			if(n - cnt >= m) ans++;
		}while(std::next_permutation(b + 1, b + n + 1));
		printf("%d\n", ans);
	}
}
int main(){
#ifndef STDIO
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	bf::solve();
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}