#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int a[maxn];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
	} 
	int ans=0;
	if(n<=3)
	{
		if(n<3)
			return printf("0"),0;
		if(a[1]+a[2]>a[3] || a[2]+a[3]>a[1] || a[1]+a[3]>a[2])
		{
			ans++;
		}
		
	}
	else
	{
		ans=n/2;
	}
	printf("%d",ans);
	return 0;
} 
