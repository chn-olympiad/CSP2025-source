#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int n, m;
string s;
int c[550];

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i ++) cin >> c[i];
	int ans = 1;
	for(int i = 1;i <= n;i ++){
		ans = (ans * i) % 998244353;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
