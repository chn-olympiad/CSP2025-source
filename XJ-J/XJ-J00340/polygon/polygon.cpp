#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n, r, a[N], b[N], cnt;
bool check(int sum) {
	for(int i=1; i<=r; ++i) {
		if(sum<=b[i]*2) return false;
	}
	return true;
}
void DFS(int k, int pre, int sum) {
	if(k == r+1) {
		if(check(sum)) cnt = (cnt+1) % 998244353;
		return ;
	}
	for(int i=pre+1; i<=n; ++i) {
		b[k] = a[i];
		DFS(k+1, i, sum+a[i]);
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	//思路：DFS深度优先搜索算法 
	cin >> n;  r=n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	while (true) {
		DFS(1, 0, 0);
		-- r;
		if(r<3) break;
	}
	cout << cnt;
	return 0;
}
