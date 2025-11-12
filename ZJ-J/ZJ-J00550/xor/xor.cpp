#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool flag1=0,flag2=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)flag1=1;
		if(a[i]>1)flag2=1;
	}
	if(!flag1)
	{
		if(k==1)printf("%d",n);
		else if(k==0)printf("%d",n/2);
	}
	else if(!flag2)
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)if(a[i]==1)ans++;
			printf("%d",ans);
		}
		else
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i])
				{
					sum++;
					if(sum==2)ans++,sum=0;
				}
				else if(sum==0)ans++;
			}
			printf("%d",ans);
		}
	}
	else
	{
		long long sum=a[1];
		for(int i=2;i<=n;i++)
		{
			if(sum==k)ans++,sum=a[i];
			else sum^=a[i];
		}
		if(sum==k)ans++;
		printf("%d",ans);
	}
	return 0;
}
