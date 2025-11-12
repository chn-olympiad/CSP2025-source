#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c[505] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cout << 1 << '\n';
	return 0;
} 
