#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5; 
int n, k, ans, cnt, a[N], s[N], f[N];
struct qj{int l, r, len;}; vector<qj> q;
signed main(){
//	int stt = clock();
	freopen("xor.in", "r", stdin); freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1]^a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++){
			int res = s[j]^s[i-1];
//			printf("[%d,%d] = %d\n", i, j, res);
			if (res == k) q.push_back({i, j, j-i+1});
		}
	sort(q.begin(), q.end(), [](qj x, qj y){
		return (x.r == y.r ? x.l < y.l : x.r < y.r);
	});
//	for (int i = 1; i <= n; i++)
	for (int i = 0, now = 0; i < (int)q.size(); i++)
		if (q[i].l > now) ++ans, now = q[i].r;
	cout << ans;// << "\n" << stt;
	return 0;
}

