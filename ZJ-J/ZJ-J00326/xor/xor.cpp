#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 1e6 + 5e5 + 5;
int n, k, a[N], f[N], sum[N], nt[M], cnt;
struct Node {
	int l, r;
	bool operator < (const Node k1) const {return k1.r > r;}
}b[N];
signed main ()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	//OK100
	
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	
	memset (nt, -1, sizeof nt);
	nt[0] = 0;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		int x = k ^ sum[i];
		if (nt[x] != -1)b[++ cnt] = {nt[x] + 1, i};
		nt[sum[i]] = i;
	}
	sort (b + 1, b + cnt + 1);
	int j =  1;
	for (int i = 1; i <= n; i ++)
	{
		f[i] = f[i - 1];
		if (b[j].r == i)f[i] = max (f[i], f[b[j].l - 1] + 1), j ++;
	}
	cout << f[n];
}
/*
4 0
2 1 0 3


*/
