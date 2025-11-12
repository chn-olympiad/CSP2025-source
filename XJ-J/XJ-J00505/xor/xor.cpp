#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,q,l[10005],r[10005],qq = 1;
	cin >> n >> k;
	long long a[n + 1];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			int num = 0;
			if(i == j)
			{
				num += a[i] | a[j];
			}
			else
			{
				num = a[i];
				for(int w = i + 1;w <= j;w++)
				{
					num = num | a[w];
				}
			}
			if(num == k)
			{
				l[qq] = i; 
				r[qq] = j;
				qq++;
			}
		}
	}
	int maxx = 0,numm = 0;
	for(int i = 1;i <= qq;i++)
	{
		numm = 0;
		for(int j = i + 1;j <= qq;j++)
		{
			if(l[i] < l[j] && r[i] < r[j])
			{
				numm++;
			}
			if(l[i] > l[j] && r[i] > r[j])
			{
				numm++;
			}
		}
		maxx = max(numm,maxx);
	}
	cout << maxx;
	return 0;
} 
