#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int N = 5e5 + 5;

int sum[N];
map<int, int> mp;

struct node{
	int a, b;
	int id;
}a[N];

bool cmp(node x, node y) {
	if (x.b == y.b) return x.a < y.a;
	return x.b < y.b;
}

signed main(void) {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k; //n = 49999, k = 1;
	int m = 0;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i]; //x = i;
		sum[i] ^= sum[i - 1];
		if (sum[i] == k) {
			m++;
			a[m].a = 1;
			a[m].b = i;
			a[m].id = i;
		}
		if (mp[sum[i] ^ k]) {
			m++;
			a[m].a = mp[sum[i] ^ k] + 1;
			a[m].b = i;
			a[m].id = i;
//			cout << mp[sum[i] ^ k] << "  " << sum[i] << endl;
		}
		mp[sum[i]] = i;
	}
	sort(a + 1, a + m + 1, cmp);
	int x = 0;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (x < a[i].a) x = a[i].b, ans++;
//		cout << "x: " << x << "  ans: " << ans << endl;
//		cout << a[i].a << "  " << a[i].b << "    " << ans << endl;
	}
	
	cout << ans;
	return 0;
} 
