#include<bits/stdc++.h>
using namespace std;
int n;
int a[5009];
bool judge(int x,int y)
{
	long long sum=0;
	long long mx=-1;
	for(int i=x;i<=y;i++)
	{
		sum+=a[i];
		if(a[i]>mx) mx=a[i];
	}	
	if(mx*2>sum) return 0;
	return 1;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	if(n<3) printf("%d",ans);
	if(n==3)
	{
		if(judge(1,3)) printf("1");
		else printf("%d",ans);
	}
	else
	{
		for(int i=1;i<=n-3;i++)
			for(int j=i+3;j<=n;j++)
				if(judge(i,j)) ans++;
		printf("%d",ans%998244353);
	}
	return 0;
}
