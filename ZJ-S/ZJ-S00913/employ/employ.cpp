#include <bits/stdc++.h>

using namespace std;

int main(void) {
	freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	long long int n,m,ans = 1;
	string s;
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++) {
		ans = (ans * i) % 998244353;
	}
	cout << ans % 998244353;
	return 0;
}

