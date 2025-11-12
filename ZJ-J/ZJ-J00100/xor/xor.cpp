#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], XOR[500005], cnt = 0;
struct node{
	int l, r;
}q[500005];
bool cmp(node x, node y){
	if (x.r == y.r)  return x.l < y.l;
	return x.r < y.r;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i=1; i <= n; i++){
		cin >> a[i];
		XOR[i] = XOR[i-1] ^ a[i];
	}
	for (int i=1; i <= n; i++){
		for (int j=i; j <= n; j++){
			if ((XOR[j] ^ XOR[i-1]) == k){
				q[++cnt] = node{i, j};
				break;
			}
		}
	}
	sort(q+1, q+cnt+1, cmp);
	if (cnt == 0){
		cout << 0;
		return 0;
	}
	int p = 1, rh = q[1].r, ans = 1;
	while (rh < n && p <= cnt){
		while (q[p].l <= rh && p <= cnt)  p++;
		if (p > cnt)  break;
		ans ++;
		rh = q[p].r;
	}
	cout << ans;
	return 0;
}
