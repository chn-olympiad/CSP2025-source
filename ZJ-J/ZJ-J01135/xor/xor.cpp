#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500009];
int ans[500009];
int f[500009] = {0};

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i==1) ans[1] = a[i];
		else ans[i] = ans[i-1] ^ a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i] = f[i-1];
		for(int j=1;j<=i;j++)
		{
			int tmp;
			if(j==1) tmp = ans[i];
			else tmp = ans[i] ^ ans[j-1];
			if(tmp==k)
			{
				f[i] = max(f[j-1]+1,f[i]);
			}
		}
	}
	printf("%d",f[n]);
	return 0;
}
