#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int n;
long long k, a[N], f[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = f[i - 1] ^ a[i];
	}
	int l = 1, r = -1, ans = 0;
    while (l <= n)
    {
		r = -1;
    	for (int i = l; i <= n; i++)
    	{
    		long long yh = abs(f[i] - f[l - 1]);
    		if (yh == k)
    		{
    			r = i;
    			break;
			}
		}
		if (r == -1)
			l++;
		else
		{ 
			l = r + 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
