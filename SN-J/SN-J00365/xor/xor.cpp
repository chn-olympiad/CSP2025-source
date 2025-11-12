#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],sum,cnt,l;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 2;i <= n;i++)
	{
		b[i] = b[i] ^ b[i-1];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if(b[i-1] ^ b[j] == k)
			{
				cnt++;
				l = j;
				break;
			}
		}
		i = l + 1;
	}
	cout << cnt;
	return 0;
}
