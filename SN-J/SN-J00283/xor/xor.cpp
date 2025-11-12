#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[500005], b[500005], aa = 0, cnt = 1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = b[i-1]^a[i];
	}
//	for (int i = 1;i <= n;i++)
//	{
//		cout << b[i] << " ";
//	}
//	cout << endl;
	for (int k = 0;k <= n;k++)
	{
		int ans = 0;
		for (int i = n;i >= 1;i--)
		{
			for (int j = i;j >= i-k-1;j--)
			{
				int aaa = b[j-1]^b[i];
				if (aaa == k)
				{
	//				cout << aaa << " ";
	//				cout << i << " " << j << endl;
					cnt = j;
					i = j;
					ans++;
					break;
				}
			}
		}
		aa = max(ans, aa);
	}
	cout << aa;
	return 0;
}
