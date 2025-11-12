#include <bits/stdc++.h>
using namespace std;

int n, k, j, sum, ans, a[500001];
bool vis[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == 0)
		{
			j = i+1;
			sum = a[i];
			if(sum == k)
			{
				ans++;
				continue;
			}
			while(j <= n)
			{
				if(vis[j] == 0)
				{
					sum = sum ^ a[j];
					vis[j] = 1;
					if(sum == k)
					{
						ans++;
						break;
					}
				}
				j++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
