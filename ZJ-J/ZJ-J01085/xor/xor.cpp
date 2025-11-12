#include<bits/stdc++.h>
using namespace std;
const int mod = 1e7 + 7;
int f[500005], n, a[500005], k, sum[500005];
struct node{
	int x, ind;
};
vector <node> H[10000010];	
int main()	{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)	{
		scanf("%d", a + i);
		sum[i] = a[i] ^ sum[i - 1];
		f[i] = max((sum[i] == k ? 1 : 0), f[i - 1]);
		int p = k ^ sum[i];
		int q = p % mod;
		for (int j = H[q].size() - 1; j >= 0; --j)	{
			if (H[q][j].x == p)	{
				f[i] = max(f[i], f[H[q][j].ind] + 1);
				break;
			}
		}
		H[sum[i] % mod].push_back((node){sum[i], i});
	}
	cout << f[n] << endl;
	return 0;
}