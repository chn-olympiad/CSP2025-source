#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, mod = 998244353;
int n, m, ans, c[N], id[N];
string s;
void solve(){
	int pre = 1;
	for(int i = 1; i <= n; i++){
		if(s[i] == '0' || c[i] == 0){
			printf("0");
			return;
		}
		pre = pre * i % mod;
	}
	printf("%lld", pre);
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	cin >> s;
	s = ' ' + s;
	for(int i = 1; i <= n; i++)	scanf("%lld", &c[i]);
	if(m == n){
		solve();
		return 0;
	}
	for(int i = 1; i <= n; i++)	id[i] = i;
	do{
		int pre = 0;
		for(int i = 1; i <= n; i++){
			if(pre >= c[id[i]] || s[i] == '0')	pre++;
		}
		if(n - pre >= m)	ans = (ans + 1) % mod;
	}while(next_permutation(id + 1, id + 1 + n));
	printf("%lld", ans);
	return 0;
}
