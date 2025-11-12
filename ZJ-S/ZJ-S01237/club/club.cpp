#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=1e6+9;
ll t, n, ans = 0, used[N];
struct NDE{
	ll a1, a2, a3;
};
NDE a[N], b[N];
void dfs(ll k, ll sum, ll sa, ll sb, ll sc){
	if (k==n+1){
		ans = max(ans, sum);
	}
	if(sa<n/2){
		sum += a[k].a1;
		sa++;
		dfs(k+1, sum, sa, sb, sc);
		sum -= a[k].a1;
		sa--;
	}
	if(sb<n/2){
		sum += a[k].a2;
		sb++;
		dfs(k+1, sum, sa, sb, sc);
		sum -= a[k].a2;
		sb--;
	}
	if(sc<n/2){
		sum += a[k].a3;
		sc++;
		dfs(k+1, sum, sa, sb, sc);
		sum -= a[k].a3;
		sc--;
	}
	return;
}
bool cmp(NDE ss, NDE bb){
	return ss.a1 > bb.a1;
}
int main(){
	freopen("club5.in", "r", stdin);
	freopen("club5.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	scanf("%lld", &t);
	while(t--){
		scanf("%lld",&n);
		ans = 0;
		memset(used, 0, sizeof(used));
		for(ll i=1;i<=n;i++){
			scanf("%lld %lld %lld", &a[i].a1, &a[i].a2, &a[i].a3);
			b[(i-1)*3+1].a1 = a[i].a1;
			b[(i-1)*3+1].a2 = 1;
			b[(i-1)*3+1].a3 = i;
			b[(i-1)*3+2].a1 = a[i].a2;
			b[(i-1)*3+2].a2 = 2;
			b[(i-1)*3+2].a3 = i;
			b[(i-1)*3+3].a1 = a[i].a3;
			b[(i-1)*3+3].a2 = 3;
			b[(i-1)*3+3].a3 = i;
		}
		if(n<=10){
			dfs(1, 0, 0, 0, 0);
			printf("%lld\n", ans);
			continue;
		}
		sort(b+1, b+1+n*3, cmp);
		ll sa=0,sb=0,sc=0;
		ll ans2 = 0;
		for(ll i=1;i<=n*3;i++){
			if (sa<n/2&&used[b[i].a3]!=1&&b[i].a2 == 1){
				used[b[i].a3] = 1;
				sa++;
				ans += b[i].a1;
			}
			if (sb<n/2&&used[b[i].a3]!=1&&b[i].a2 == 2){
				used[b[i].a3] = 1;
				sb++;
				ans += b[i].a1;
			}
			if (sc<n/2&&used[b[i].a3]!=1&&b[i].a2 == 3){
				used[b[i].a3] = 1;
				sc++;
				ans += b[i].a1;
			}
		}
		ans = max(ans, ans2);
		printf("%lld\n", ans);
	}
	return 0;
}

