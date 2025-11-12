#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 5;
const ll inf = 1e18;

struct rumia {
	ll val;
	int siz[5], sum;
	int pos;
	void init() {
		val = sum = pos = 0;
		siz[0] = siz[1] = siz[2] = 0;
		return;
	}
//	bool friend operator<(rumia x, rumia y) {
//		if (x.val != y.val)
//			return x.val < y.val;
//		else
//			return x.sum > y.sum;
//	}
} tmp;
int n, nn;
ll a[5][N];
ll ans = -inf;

void bfs() {
	/*priority_*/queue<rumia>q;
	for (int i = 0; i <= 2; i++) {
		tmp.init();
		tmp.sum = 1;
		tmp.pos = 1;
		tmp.siz[i] = 1;
		tmp.val = a[i][1];
		q.push(tmp);
	}
	while (!q.empty()) {
		rumia now = q.front();
		q.pop();
		if (now.val <= ans)
			continue;
		if (now.pos >= n) {
			ans = max(ans, now.val);
			continue;
		}
		int npos = now.pos + 1;

		for (int j = 0; j <= 2; j++) {
			if (now.siz[j] >= nn)
				continue;
			rumia tp;
			tp.pos = npos;
			tp.siz[0] = now.siz[0] ;
			tp.siz[1] = now.siz[1] ;
			tp.siz[2] = now.siz[2] ;
			tp.siz[j]++;
			tp.sum = now.sum + 1;
			tp.val = now.val + a[j][npos];
			q.push(tp);
		}
	}
	return;
}

bool reimu(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		nn = n >> 1;
		ans = -inf;
		bool Af = true;
		bool Bf = true;
		bool Cf = true;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[0][i], &a[1][i], &a[2][i]);
			if (a[1][i] != 0 || a[2][i] != 0)
				Af = false;
			if (a[0][i] != 0 || a[2][i] != 0)
				Bf = false;
			if (a[0][i] != 0 || a[1][i] != 0)
				Cf = false;
		}
		if (Af) {
			sort(a[0] + 1, a[0] + n + 1, reimu);
			ans = 0;
			for (int i = 1; i <= nn; i++) {
				ans += a[0][i];
			}
			printf("%lld\n", ans);
			continue;
		}
		if (Bf) {
			sort(a[1] + 1, a[1] + n + 1, reimu);
			ans = 0;
			for (int i = 1; i <= nn; i++) {
				ans += a[1][i];
			}
			printf("%lld\n", ans);
			continue;
		}
		if (Cf) {
			sort(a[2] + 1, a[2] + n + 1, reimu);
			ans = 0;
			for (int i = 1; i <= nn; i++) {
				ans += a[2][i];
			}
			printf("%lld\n", ans);
			continue;
		}
		bfs();
		printf("%lld\n", ans);
	}
	return 0;
}