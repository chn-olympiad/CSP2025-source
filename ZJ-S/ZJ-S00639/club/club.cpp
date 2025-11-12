#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 10;
struct node {
	int v1, v2, v3;
	int vis;
	int max1;
	int cha;
	int f1;
	int ans;
}a[N];
bool cmp (node x, node y) {
	return x.cha > y.cha;
}
int cnt[5];
void solve () {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
		a[i].vis = 0;
		if (a[i].v1 == a[i].v2 && a[i].v2 == a[i].v3) a[i].ans = a[i].v1, a[i].vis = 1;
		else if (a[i].v1 == a[i].v2 && a[i].v2 > a[i].v3) a[i].ans = a[i].v1, a[i].vis = 1;
		else if (a[i].v2 == a[i].v3 && a[i].v2 > a[i].v1) a[i].ans = a[i].v2, a[i].vis = 1;
		else if (a[i].v1 == a[i].v3 && a[i].v1 > a[i].v2) a[i].ans = a[i].v1, a[i].vis = 1;
			
		else if (a[i].v1 == a[i].v2 && a[i].v2 < a[i].v3) a[i].max1 = a[i].v3, a[i].f1 = 3, a[i].cha = a[i].v3 - a[i].v1;
		else if (a[i].v2 == a[i].v3 && a[i].v2 < a[i].v1) a[i].max1 = a[i].v1, a[i].f1 = 1, a[i].cha = a[i].v1 - a[i].v2;
		else if (a[i].v1 == a[i].v3 && a[i].v1 < a[i].v2) a[i].max1 = a[i].v2, a[i].f1 = 2, a[i].cha = a[i].v2 - a[i].v3;
		
		else if (a[i].v1 < a[i].v2 && a[i].v2 < a[i].v3) a[i].max1 = a[i].v3, a[i].f1 = 3, a[i].cha = a[i].v3 - a[i].v2;
		else if (a[i].v1 < a[i].v3 && a[i].v3 < a[i].v2) a[i].max1 = a[i].v2, a[i].f1 = 2, a[i].cha = a[i].v2 - a[i].v3;
		else if (a[i].v2 < a[i].v1 && a[i].v1 < a[i].v3) a[i].max1 = a[i].v3, a[i].f1 = 3, a[i].cha = a[i].v3 - a[i].v1;
		else if (a[i].v2 < a[i].v3 && a[i].v3 < a[i].v1) a[i].max1 = a[i].v1, a[i].f1 = 1, a[i].cha = a[i].v1 - a[i].v3;
		else if (a[i].v3 < a[i].v1 && a[i].v1 < a[i].v2) a[i].max1 = a[i].v2, a[i].f1 = 2, a[i].cha = a[i].v2 - a[i].v1;
		else if (a[i].v3 < a[i].v2 && a[i].v2 < a[i].v1) a[i].max1 = a[i].v1, a[i].f1 = 1, a[i].cha = a[i].v1 - a[i].v2;
	}
	cnt[1] = cnt[2] = cnt[3] = n / 2; 
	sort (a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i ++ ) {
		if (a[i].vis) continue;
		if (cnt[a[i].f1]) 	cnt[a[i].f1] --, a[i].ans = a[i].max1;
		else			a[i].ans = a[i].max1 - a[i].cha;
	}
	int sum = 0;
	for (int i = 1; i <= n; i ++ ) {
		sum += a[i].ans;
	}
	cout << sum << "\n";
}
signed main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T --) solve();
}
