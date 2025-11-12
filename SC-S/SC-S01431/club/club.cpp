#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int T, n;
int a[N][5];

pair<int, int> sx[N];

struct Peo {
	int name1, name2, num1, num2;
} p[N];

int solve() {
	int cnt[5] = {0, 0, 0, 0, 0}, ans = 0;
	sort(sx + 1, sx + 1 + n, greater<pair<int, int>>());
	for (int i = 1; i <= n; i++) {
		int now = sx[i].second;
		if (cnt[p[now].name1] >= n / 2)	cnt[p[now].name2]++, ans += p[now].num2;
		else	cnt[p[now].name1]++, ans += p[now].num1;
	}
	return ans;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {

			pair<int, int> d[5];
			scanf("%d %d %d", &d[1].first, &d[2].first, &d[3].first);
			d[1].second = 1, d[2].second = 2, d[3].second = 3;

			sort(d + 1, d + 4, greater<pair<int, int>>());

			sx[i].first = d[1].first - d[2].first, sx[i].second = i;
			
			p[i].name1 = d[1].second, p[i].name2 = d[2].second;
			p[i].num1 = d[1].first, p[i].num2 = d[2].first;
			
//			cout<<p[i].name1<<" "<<p[i].num1<<" "<<p[i].name2<<" "<<p[i].num2<<"\n";
		}
		printf("%d\n", solve());
	}
	return 0;
}