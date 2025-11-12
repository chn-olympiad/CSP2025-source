#include <bits/stdc++.h>
using namespace std;
long long T, n, maxx, tot, vis[10];

struct me {
	long long a;
	long long b;
	long long c;
} member[100010];

void dfs(long long Fl) {
	if (Fl == n + 1) {
		maxx = max(maxx, tot);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		long long f = -1;
		if (i == 1 && vis[1] < n / 2) {
			tot += member[Fl].a;
			f = 1;
			vis[1]++;
		}
		if (i == 2 && vis[2] < n / 2) {
			tot += member[Fl].b;
			f = 2;
			vis[2]++;
		}
		if (i == 3 && vis[3] < n / 3) {
			tot += member[Fl].c;
			f = 3;
			vis[3]++;
		}
		dfs(Fl + 1);
		if (f == 1) {
			tot -= member[Fl].a;
			vis[1]--;
		}
		if (f == 2) {
			tot -= member[Fl].b;
			vis[2]--;
		}
		if (f == 3) {
			tot -= member[Fl].c;
			vis[3]--;
		}
	}
}

int comp(me L, me R) {
	return L.a > R.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		maxx = LLONG_MIN;
		tot = 0;
		memset(vis, 0, sizeof(vis));
		long long tpA = 1;
		for (int j = 1; j <= n; j++) {
			scanf("%lld%lld%lld", &member[j].a, &member[j].b, &member[j].c);
			if (member[j].b > 0)
				tpA = 0;
			if (member[j].c > 0)
				tpA = 0;
		}
		if (tpA == 1) {
			sort(member + 1, member + 1 + n, comp);
			long long Etot = 0;
			for (int j = 1; j <= n / 2; j++) {
				Etot += member[j].a;
			}
			printf("%lld\n", Etot);
			continue;
		}
		if (n <= 10) {
			dfs(1);
			printf("%lld\n", maxx);
			continue;
		}
	}
	return 0;
}
