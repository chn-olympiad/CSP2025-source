#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , t , d[100009] , cnt[5];
struct node {
	int s , p;
}a[100009][5];

void adj(int i) {
	vector <int> v;
	for (int j = 1 ; j <= n ; j++) if (d[j] == i) v.emplace_back(j);
	sort(v.begin() , v.end() , [](const int &x , const int &y){return (a[x][1].s - a[x][2].s) < (a[y][1].s - a[y][2].s);});
	for (auto j : v) {
		d[j] = a[j][2].p , cnt[i]--;
		if (cnt[i] == n / 2) break;
	}
}

void cclt() {
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) ans += a[i][d[i]].s;
	cout << ans << "\n";
}

void work() {
	cnt[1] = cnt[2] = cnt[3] = 0 , cin >> n;
	for (int i = 1 ; i <= n ; i++) cin >> a[i][1].s >> a[i][2].s >> a[i][3].s , a[i][1].p = 1 , a[i][2].p = 2 , a[i][3].p = 3 , sort(a[i] + 1 , a[i] + 4 , [](const node &x , const node &y){return x.s > y.s;}) , d[i] = a[i][1].p , cnt[a[i][1].p]++;
	for (int i = 1 ; i <= 3 ; i++) if (cnt[i] > n / 2) adj(i);
	for (int i = 1 ; i <= n ; i++) sort(a[i] + 1 , a[i] + 4 , [](const node &x , const node &y){return x.p < y.p;});
	cclt();
}

signed main() {
	freopen("club.in" , "r" , stdin); freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) work();
	return 0;
}
