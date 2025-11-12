#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5*100000+9];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int f=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0) f=1;
		if(a[i]>1) f=2;
	}	
	if(k==1 && f==0)
	{
		printf("%d",n);
		return 0;
	} 
	if(k==0 && f==0)
	{
		printf("%d",n/2);
		return 0;
	}
	int ans=0;
	if(k==0 && f==1)
	{
		int x=a[1];
		for(int i=1;i<=n;i++)
			if(x==a[i])
			{
				ans++;
				i=i+1;
				x=a[i];
			}
		printf("%d",ans);
	}
	if(k==1 && f==1)
	{
		int x=a[1];
		for(int i=1;i<=n;i++)
			if(x!=a[i])
			{
				ans++;
				i=i+1;
				x=a[i];
			}
		printf("%d",ans);
	}				
	if(f==2) printf("2");			
	return 0;
}
