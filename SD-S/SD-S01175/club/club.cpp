#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 5;

struct node {
	int x, y, z;
};
struct node2{
	int v, id;
};

int t;
int n;
node a[N];
int ans;
node2 yi[N], er[N], san[N];
bool f[N];
int sy[N], se[N], ss[N];

bool cmp(node2 aa, node2 bb) {
	return aa.v > bb.v;
}
void solve() {
	memset(sy, 0, sizeof(sy));
	memset(se, 0, sizeof(se));
	memset(ss, 0, sizeof(ss));
	memset(f, 0, sizeof(f));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		yi[i].v = a[i].x; yi[i].id = i;
		er[i].v = a[i].y; er[i].id = i;
		san[i].v = a[i].z; san[i].id = i;
	}
	sort(yi + 1, yi + n + 1, cmp);
	sort(er + 1, er + n + 1, cmp);
	sort(san + 1, san + n + 1, cmp);
	
	for (int i = 1; i * 2 <= n; i++) f[yi[i].id] = 1;
	int cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; i++) {
		if (!f[er[i].id]) se[++cnt2] = se[cnt2 - 1] + er[i].v;
		if (!f[san[i].id]) ss[++cnt3] = ss[cnt3 - 1] + san[i].v;
	}
	int sum1 = 0;
	for (int i = 1, j = n / 2 - 1; i <= n / 2, j >= 1; i++, j--) sum1 = max(sum1, se[i] + ss[j]);
	for (int i = 1; i * 2 <= n; i++) sum1 += yi[i].v;
	
	for (int i = 1; i <= n; i++) f[i] = 0, ss[i] = 0, sy[i] = 0;
	for (int i = 1; i * 2 <= n; i++) f[er[i].id] = 1;
	cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; i++) {
		if (!f[yi[i].id]) sy[++cnt2] = sy[cnt2 - 1] + yi[i].v;
		if (!f[san[i].id]) ss[++cnt3] = ss[cnt3 - 1] + san[i].v;
	}
	int sum2 = 0;
	for (int i = 1, j = n / 2 - 1; i <= n / 2; i++, j--) sum2 = max(sum2, sy[i] + ss[j]);
	for (int i = 1; i * 2 <= n; i++) sum2 += er[i].v;
	
//	cout << "er : \n";
//	for (int i = 1; i <= n; i++) cout << sy[i] <<  " ";
//	cout << "=====================\n"; 
	
	for (int i = 1; i <= n; i++) f[i] = 0, se[i] = 0, sy[i] = 0;
	for (int i = 1; i * 2 <= n; i++) f[san[i].id] = 1;
	cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; i++) {
		if (!f[er[i].id]) se[++cnt2] = se[cnt2 - 1] + er[i].v;
		if (!f[yi[i].id]) sy[++cnt3] = sy[cnt2 - 1] + yi[i].v;
	}
	int sum3 = 0;
	for (int i = 1, j = n / 2 - 1; i <= n / 2, j >= 1; i++, j--) sum3 = max(sum3, se[i] + sy[j]);
	for (int i = 1; i * 2 <= n; i++) sum3 += san[i].v;
	
//	cout << sum1 << " " << sum2 << " " << sum3 << "\n";
	
	cout << max(sum1, max(sum2, sum3)) << '\n';
}



int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
