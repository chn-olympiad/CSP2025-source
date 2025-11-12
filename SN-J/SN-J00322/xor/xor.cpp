//简单题
//数组优化DP?
//就是开一个2^20的数组记录每种前缀异或值的答案最大值即可
#include<bits/stdc++.h>

using namespace std;

#define N 500005
#define M 1100005 

int n, K, a[N], f[N], mx[M];

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> K;
	for(int i = 1; i <= n; i++)cin >> a[i], a[i] ^= a[i - 1];
	for(int i = 1; i <= 1048576; i++)mx[i] = -1e7;
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		f[i] = max(f[i], mx[a[i] ^ K] + 1);
		mx[a[i]] = max(mx[a[i]], f[i]);
	}
	cout << f[n] << "\n";
	return 0;
} 
