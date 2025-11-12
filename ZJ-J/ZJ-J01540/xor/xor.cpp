#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}qj[500005];
int n,k;
int a[500005];
int qz[500005],dp[500005];
bool mark=true,flag=true;
bool cmp(node a,node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	else return a.y<b.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		qz[i]=qz[i-1]^a[i];
		if(a[i]!=1) mark=false;
		if(!(a[i]<=1&&a[i]>=0)) flag=false;
	}
	if(mark&&k==0)
	{
		cout<<n<<endl;
		return 0;
	}
	else if(flag&&k==1)
	{
		long long cnt;
		for(int i=1;i<=n;i++)
			if(a[i]==1) cnt++;
		cout<<cnt<<endl;
		return 0;
	}
	else
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((qz[j]^qz[i-1])==k)
				{
					node t;t.x=i;t.y=j;
					qj[++cnt]=t;
				}
		sort(qj+1,qj+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
			dp[i]=1;
		for(int i=2;i<=cnt;i++)
		{
			for(int j=1;j<i;j++)
				if(qj[j].y<qj[i].x) 
					dp[i]=max(dp[i],dp[j]+1);
		}
		printf("%d",dp[cnt]);
		return 0;
	}
}
