#include <bits/stdc++.h>
using namespace std;

long long a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k,t;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> t;
		a[i] = a[i-1] ^ t;
	}
	int l = 0,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j > l;j--)
		{
			if((a[j-1] ^ a[i]) == k)
			{
				cnt++;
				l = i;
			}
		}
	}
	cout << cnt;
	return 0;
}
