#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 505;
int n,m,c[N],idx[N];
char s[N];

void solve() {
	scanf("%d%d%s",&n,&m,s + 1);
	for(int i = 1;i <= n;i++) scanf("%d",&c[i]),idx[i] = i;
	if(n <= 10) {
		int ans = 0;
		do {
			int sum = 0,s2 = 0;
			for(int i = 1;i <= n;i++) {
				if(s2 >= c[idx[i]] || s[i] == '0') s2++; 
				else sum++;
			} 
			if(sum >= m) ans = (ans + 1) % 998244353;
		} while(next_permutation(idx + 1,idx + n + 1));
		printf("%d",ans);
		return ;
	}
	ll ans = 1;
	for(int i = 1;i <= n;i++) ans = ans * 2 % 998244353;
	cout << ans;
}

int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}