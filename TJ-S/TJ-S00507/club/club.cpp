#include <bits/stdc++.h>
using namespace std;
int n,t;
long long a[100005][5],ans,p[100005],k[5];
bool cmp(long long x,long long y)
{
	return x>y;
}
void dfs(int s,long long sum)
{
	if (s==n+1)
	{
		ans=max(ans,sum);
	}
	for (int i=1;i<=3;i++)
	{
		if (k[i]<n/2)
		{
			k[i]++;
			dfs(s+1,sum+a[s][i]);
			k[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;
		ans=0;
		long long maxc=0;
		for (int i=1;i<=3;i++)
		{
			k[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxc=max(maxc,a[i][3]);
		}
		if (maxc==0)
		{
			for (int i=1;i<=n;i++)
			{
				ans+=a[i][1];
				p[i]=a[i][2]-a[i][1];
			}
			sort(p+1,p+n+1,cmp);
			for (int i=1;i<=n/2;i++)
			{
				ans+=p[i];
			}
		}
		else if (n<=30)
		{
			dfs(1,0);
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				ans+=a[i][1];
				p[i]=a[i][2]-a[i][1];
			}
			sort(p+1,p+n+1,cmp);
			for (int i=1;i<=n/2;i++)
			{
				ans+=p[i];
			}
		}
		cout<<ans<<endl;
	}
}
