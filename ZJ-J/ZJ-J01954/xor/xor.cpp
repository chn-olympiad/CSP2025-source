#include<bits/stdc++.h>
using namespace std;
int maxn[500010],a[500010],f[500010],s[500010],ans,n,m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		s[i]=s[i-1]^a[i];
	}
	if(n<=10000)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
				if((s[i]^s[j-1])==m)
					f[i]=max(f[i],maxn[j-1]+1);
			maxn[i]=max(maxn[i-1],f[i]);
			ans=max(ans,f[i]);
		}
		printf("%d",ans);
	}
	else
	{
		if(m==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=a[i];
			printf("%d",ans);
		}
		else
		{
			int ans=0,i=1;
			while(i<=n)
			{
				if(a[i]==0)
				{
					i++;
					ans++;
				}
				else
				{
					if(a[i+1]==1)
					{
						ans++;
						i++;
					}
					i++;
				}
			}
			printf("%d",ans);
		}
	}
	return 0;
}
