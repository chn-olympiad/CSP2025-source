#include <bits/stdc++.h>
using namespace std;
const int XN=5e2+10, mod=998244353;
int n, m, c[XN], sum[XN], ans, lst[XN];
bool s[XN];
vector<int> v;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i]; sum[i] = sum[i-1]; 
		if (i>1 && s[i-1]==0) sum[i]++; 
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++) {
		ans = 1;
		int l=1; r=n;
		while (l <= r) {
			int mid=(l+r)/2
			if (sum[mid] <= c[i])
				l = mid+1;
			else r = mid-1;
		} 
		v.push_back(r);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		if (i) ans = ans*(i-1)%mod;
		else ans = ans*i%mod;
	cout << ans; 
	return 0;
}
