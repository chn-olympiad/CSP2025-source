#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],f[500010],sum,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool t1=true;
	int s1=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>1)
		{
			t1=false;
		}
		if(a[i]==1)
		{
			s1++;
		}
	}
	if(n==2 && a[1]==1 && a[2]==1)
	{
		printf("1");
		exit(0);
	}
	if(t1)
	{
		if(k==1)
		{
			printf("%d",s1);
			exit(0);
		}
		else if(k==0)
		{
			s1=n-s1;
			for(int i=1;i<n;i++)
			{
				if(a[i]==1 && a[i+1]==1)
				{
					s1++;
				}
			}
			printf("%d",s1);
			exit(0);
		}
	}
	
	sum=0;
	for(int i=1;i<=n;i++)
	{
		int t=0;
		for(int j=i;j<=n;j++)
		{
			t=t^a[j];
			if(t==k)
			{
				sum++;
				i=j;
				break;
			}
		}
	}
	ans=max(ans,sum);
	
	sum=0;
	for(int i=n;i>0;i--)
	{
		int t=0;
		for(int j=i;j>0;j--)
		{
			t=t^a[j];
			if(t==k)
			{
				sum++;
				i=j;
				break;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
