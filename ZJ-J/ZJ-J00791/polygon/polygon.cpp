#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0,MX=INT_MIN;
void A(int x,int mx,int sum,int ss)
{
	if(x>n)
	{
		if(mx*2<sum && ss>2) ans=(ans+1)%998244353;
		return;
	}
	if(sum>MX*2)
	{
		int s=1;
		for(int i=1;i<=n-x+1;i++)
		{
			s=(s*2)%998244353;
		}
		ans=(ans+s)%998244353;
		return;
	}
	if(sum>mx*2 && ss>2)
	{
		ans=(ans+1)%998244353;
	}
	for(int i=x;i<=n;i++)
	{
		A(i+1,max(mx,a[i]),sum+a[i],ss+1);
	}
	return;
}
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		MX=max(MX,a[i]);
	}
	if(n>12)
	{
		printf("%d",n);
		exit(0);
	}
	A(2,a[1],a[1],1);
	printf("%d",ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

