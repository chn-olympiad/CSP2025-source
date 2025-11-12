//write -> 17:50
#include  <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long;
using ll = long long;
using i128 = __int128;
#define fi first
#define se second
#define pk push_back

const int N = 5e6 + 5;
const int MOD = 998244353;

int s[N];
int c[N],p[N];
int m, n;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i ++) scanf("%1d", &s[i]), p[i] = i;
	for(int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	ll ans = 0;
	do {
		int sum1 = n, sum2 = 0;
		ans ++;
		for(int i = 1; i <= n; i ++) {
			if(n - sum1 >= c[p[i]] || !s[i]) sum1 --;
			if(sum1 < m) {
				ans --;
				break;
			}
		}
	}while(next_permutation(p + 1, p + n + 1));
	cout << ans << '\n';
	return 0;
}
//end 18:05
//the last page
