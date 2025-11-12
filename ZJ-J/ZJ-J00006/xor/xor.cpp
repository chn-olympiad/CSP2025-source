#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010],Max,cnt,dp[1010];
struct node
{
	int l,r;
}c[1010];
int main()
{ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int bo1=1,bo2=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) bo1=0;
	    if(a[i]>1) bo2=0;
	}
	if(bo1)
	{
		if(k==1) cout<<n<<endl;
		  else cout<<0<<endl;
		return 0;
	}
	if(bo2)
	{
		if(k==1)
		{
			int p=0;
			for(int i=1;i<=n;i++) p+=a[i];
			cout<<p<<endl;
			return 0;
		}
		else
		{
			int p=0,t=1;
			while(t<=n)
			{
				if(a[t]==0) p++;
				  else if(a[t]==1&&a[t+1]==1) t++,p++;
				t++;
			}
			cout<<p<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k)
			{
				c[++cnt].l=i;
				c[cnt].r=j;
				break;
			}
		}
	}
	dp[1]=1;
	for(int i=1;i<=cnt;i++)
	  for(int j=1;j<i;j++)
	    if(c[i].l>c[j].r) dp[i]=max(dp[j]+1,dp[i]);
	int ans=0;
	for(int i=1;i<=cnt;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
