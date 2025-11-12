#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , k , a[500009] , b[500009] , lst[2000009] , ans , cnt , base , tr[2000009];

void build(int u , int l , int r) {
	if (l == r) {
		tr[u] = n + 1;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1 , l , mid);
	build(u << 1 | 1 , mid + 1 , r);
	tr[u] = min(tr[u << 1] , tr[u << 1 | 1]);
}

void update(int u , int l , int r , int x , int y) {
	if (l == r && l == x) {
		tr[u] = min(tr[u] , y);
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid) update(u << 1 , l , mid , x , y);
	if (x > mid) update(u << 1 | 1 , mid + 1 , r , x , y);
	tr[u] = min(tr[u << 1] , tr[u << 1 | 1]);
}

int query(int u , int l , int r , int x , int y) {
	if (x <= l && r <= y) return tr[u];
	int mid = l + r >> 1 , res = n + 1;
	if (x <= mid) res = min(res , query(u << 1 , l , mid , x , y));
	if (y > mid) res = min(res , query(u << 1 | 1 , mid + 1 , r , x , y));
	return res;
}

signed main() {
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] , b[i] = b[i - 1] ^ a[i];
	for (int i = 0 ; i <= 2e6 ; i++) lst[i] = n + 1;
	build(1 , 1 , n);
	for (int i = n ; i >= 0 ; i--) {
		if (lst[b[i] ^ k] <= n) update(1 , 1 , n , i + 1 , lst[b[i] ^ k]);
		lst[b[i]] = i;
	}
	while (1) {
		int tmp = query(1 , 1 , n , base + 1 , n);
		if (tmp > n) return cout << ans , 0;
		ans++ , base = tmp;
	}
	return 0;
}
