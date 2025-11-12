#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 505;
int n,m,ans;
int s[N],c[N],p[N];
void solve() {
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		char c;cin >> c;
		s[i] = c - '0';
	}
	for(int i = 1;i <= n;i ++) {
		cin >> c[i];
	}
	iota(p + 1,p + n + 1,1);
	do {
		int cnt = 0;
		for(int i = 1;i <= n;i ++) {
			cnt += cnt >= c[p[i]] || !s[i];
			if(n - cnt < m) break;
		}
		ans += n - cnt >= m;
	} while(next_permutation(p + 1,p + n + 1));
	cout << ans << "\n";
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --) solve();
	return 0;
}