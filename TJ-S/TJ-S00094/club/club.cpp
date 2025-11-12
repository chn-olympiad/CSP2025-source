#include <bits/stdc++.h>
#define int long long
using namespace std;

int T, n, cnt[5], mx, idx;
struct DATA {
	int d[5];
} a[100010], b[100010];

int amax(int x, int y, int z) {
	if(x >= y && x >= z) return 1;
	if(y >= x && y >= z) return 2;
	if(z >= x && z >= y) return 3;
}
int tiaoji() {
	if(cnt[1] > n/2) return 1;
	if(cnt[2] > n/2) return 2;
	if(cnt[3] > n/2) return 3;
	return 0;
}
int slove() {
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += max(max(a[i].d[1], a[i].d[2]), a[i].d[3]);
	return ans;
}
bool cmp(DATA x, DATA y) {
	int cha1 = 0, cha2 = 0;
	for(int i = 1; i <= 3; i++)
		if(i != mx) cha1 = max(cha1, x.d[i]), cha2 = max(cha2, y.d[i]);
	return x.d[mx]-cha1 > y.d[mx]-cha2;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		cnt[1] = cnt[2] = cnt[3] = mx = idx = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i].d[1], &a[i].d[2], &a[i].d[3]);
			cnt[amax(a[i].d[1], a[i].d[2], a[i].d[3])]++;
		}
		mx = tiaoji();
		if(!mx) {
			printf("%lld\n", slove());
			continue;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(amax(a[i].d[1], a[i].d[2], a[i].d[3]) != mx) {
				int ps = 0;
				for(int j = 1; j <= 3; j++)
					if(j != mx) ps = max(ps, a[i].d[j]);
				ans += ps;
			}
			else b[++idx] = a[i];
		}
		sort(b+1, b+idx+1, cmp);
		for(int i = 1; i <= n/2; i++) ans += b[i].d[mx];
		for(int i = n/2+1; i <= idx; i++) {
			int aaa = 0;
			for(int j = 1; j <= 3; j++) 
				if(j != mx) aaa = max(aaa, b[i].d[j]);
			ans += aaa;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
