// ¸¨ÂÖÖĞÑ§ µ­³şÜ² SN-J00692 
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = (1 << 22);
int n, m, ans, TTT = 1, a[N], sum[N];

void mian()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < N; i++) sum[i] = -1;
	int res = 0, r = 0; sum[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		res ^= a[i];
		if((sum[res ^ m] >= r && sum[res ^ m] < i)) ans++, r = i;
		sum[res] = i;
	}
	cout << ans;
}

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}
