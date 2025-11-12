#include<bits/stdc++.h>

using namespace std;

const int N = 501;

int n, m, res;
int c[N];
int s[N];
int p[N];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i ++) scanf("%1d", &s[i]), sum += s[i];
	for(int i = 1; i <= n; i ++) scanf("%d", &c[i]), p[i] = i, cnt += (c[i] == 0);
	if(sum == n || m == 1){
		if(sum == n && n - cnt < m){
			puts("0"); return 0;
		}
		if(m == 1 && cnt == n) {
			puts("0"); return 0;
		}
		long long ans = 1;
		while(sum) (ans *= sum) %= 998244353, sum --;
		printf("%lld\n", ans);
		return 0;
	}
	sort(c + 1, c + n + 1);
	int ii = 0;
	do{
		ii ++;
		int cnt = 0, ans = 0;
		for(int i = 1; i <= n; i ++) {
//			if(cnt >= c[i]) continue;
			if(s[i] == 0 || cnt >= c[p[i]]) cnt ++;
			else ans ++;
		}
		if(ans >= m) res ++;
		if(ii == 2e8) break;
	}while(next_permutation(p + 1, p + n + 1));
	printf("%d\n", res);
	return 0;
}