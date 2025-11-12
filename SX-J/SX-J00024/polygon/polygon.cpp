#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5005],ans = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt = 0,maxn = 0;
	for(int i = 1;i<=n-2;i++)
	{
		for(int j = i+2;j<=n;j++)
		{
			for(int k = i;k<=j;k++)
			{
				cnt+=a[k];
				if(a[k]>=maxn)
				{
					maxn = a[k];
				}
			}
			if(maxn*2 < cnt)
				ans++;
			cnt = 0;
			maxn = 0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
