#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+10;
int a[M][5];
struct node{
	int p,s;
}f[M];
int cnt[5];
bool cmp(node x,node y)
{
	return x.s<y.s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt[0]=cnt[1]=cnt[2]=0;
		int n;
		ll ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
			{
				cnt[0]++;
				f[i].p=0;
				f[i].s=a[i][0]-max(a[i][1],a[i][2]);
				ans+=(ll)a[i][0];
			}
			else if(a[i][1]>=a[i][2])
			{
				cnt[1]++;
				f[i].p=1;
				f[i].s=a[i][1]-max(a[i][0],a[i][2]);
				ans+=(ll)a[i][1];
			}
			else
			{
				cnt[2]++;
				f[i].p=2;
				f[i].s=a[i][2]-max(a[i][0],a[i][1]);
				ans+=(ll)a[i][2];
			}
		}
	//	printf("%lld\n",ans);
		sort(f+1,f+n+1,cmp);
		if(cnt[0]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i].p==0)
				{
					ans-=(ll)f[i].s;
					cnt[0]--;
				}
				if(cnt[0]<=n/2)
				{
					break;
				}
			}
		}
		else if(cnt[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i].p==1)
				{
					ans-=(ll)f[i].s;
					cnt[1]--;
				}
				if(cnt[1]<=n/2)
				{
					break;
				}
			}
		}
		else if(cnt[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i].p==2)
				{
					ans-=(ll)f[i].s;
					cnt[2]--;
				}
				if(cnt[2]<=n/2)
				{
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

