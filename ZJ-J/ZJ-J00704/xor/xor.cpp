#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define N 500050
using namespace std;

int n, k, m, ans, maxn;
int a[N], sxor[N], dp[N];

vector<int> h[1200000];

struct left_right{
	int l;
	int r;
}lr[N];

bool cmp(left_right a, left_right b){
	if(a.l - b.l) return a.l < b.l;
	return a.r < b.r;
}

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> a[i], sxor[i] = sxor[i - 1] ^ a[i], h[sxor[i]].push_back(i);
//	for(int i = 1;i <= n;i ++) cout << sxor[i] << " ";cout << endl;
	for(int i = 1;i <= n;i ++){
		int target = k ^ sxor[i - 1], l = 0, r = h[target].size() - 1, mid;
		if(!h[target].size()) continue;
		while(l < r){
			mid = l + r >> 1;
			if(i <= h[target][mid]) r = mid;
			else l = mid + 1;
		}
		if(i <= h[target][l]){
			left_right tmp;
			tmp.l = i;
			tmp.r = h[target][l];
			lr[++ m] = tmp;
		}
	}
//	sort(lr + 1, lr + m + 1, cmp);
	int ans = 0;
	for(int i = 0;i <= m;i ++) dp[i] = 123456789987654321;
//	for(int i = 1;i <= m;i ++) cout << lr[i].l << " " << lr[i].r << endl;
	for(int i = 1;i <= m;i ++){
		int l = 0, r = ans, mid;
		while(l < r){
			mid = (l + r + 1) >> 1;
			if(lr[i].l > dp[mid]) l = mid;
			else r = mid - 1;
		}
		int val = l + 1;
		ans = max(ans, val);
		dp[val] = min(dp[val], lr[i].r);
//		cout << dp[i] << " ";
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
