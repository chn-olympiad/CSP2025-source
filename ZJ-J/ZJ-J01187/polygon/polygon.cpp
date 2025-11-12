#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,b[5005],zans,c[5005];
void dfs(int l,int t,int k)
{
 	if(t>l)
	{
		int sum=0,max1=INT_MIN;
		for(int i=1;i<t;i++)
		{
			sum+=c[i];
			if(max1<c[i]) max1=c[i];
		}
		if(sum>2*max1) ans++;
		return;	
	} 
	for(int i=b[t-1]+1;i<=n;i++)
	{
		k=i;
		c[t]=a[k];
		b[t]=k;
		dfs(l,t+1,k+1);
		b[t]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++)
	{
		dfs(i,1,1);
		zans+=ans;
		ans=0;
	}
	printf("%d",zans%998244353); 
	return 0;
}
