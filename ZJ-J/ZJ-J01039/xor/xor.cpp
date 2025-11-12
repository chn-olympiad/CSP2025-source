#include<bits/stdc++.h>
using namespace std;
const int mxn = 5e5 + 6;
int n, k;
bool cnt[mxn], a[mxn];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (k > 1)
	{
		cout << 0;
	}
	else
	{
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			if (i < n && (a[i] ^ a[i + 1]) == k && !cnt[i] && !cnt[i + 1])
			{
				cnt[i] ^= 1;
				cnt[i + 1] ^= 1;
				ans++;
			}
			if (i > 1 && (a[i] ^ a[i - 1]) == k && !cnt[i] && !cnt[i - 1])
			{
				cnt[i] ^= 1;
				cnt[i - 1] ^= 1;
				ans++;
			}
		}
//		for (int i = 1;i <= n;i++)
//		{
//			cout << cnt[i] << ' ';
//		}
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
