#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,cnt[4];
struct pp
{
	long long d[4],m,st,x;
}a[100005],tp[100005];
bool cmp(pp x,pp y)
{
	return x.x<y.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		fill(cnt,cnt+4,0);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			if(a[i].d[1]>=a[i].d[2]&&a[i].d[1]>=a[i].d[3])
			{
				a[i].m=a[i].d[1];
				a[i].st=1;
				a[i].x=min(a[i].d[1]-a[i].d[2],a[i].d[1]-a[i].d[3]);
			}
			else if(a[i].d[2]>=a[i].d[1]&&a[i].d[2]>=a[i].d[3])
			{
				a[i].m=a[i].d[2];
				a[i].st=2;
				a[i].x=min(a[i].d[2]-a[i].d[1],a[i].d[2]-a[i].d[3]);
			}
			else if(a[i].d[3]>=a[i].d[2]&&a[i].d[3]>=a[i].d[1])
			{
				a[i].m=a[i].d[3];
				a[i].st=3;
				a[i].x=min(a[i].d[3]-a[i].d[2],a[i].d[3]-a[i].d[1]);
			}
		}
		for(int i=1;i<=n;i++)
		{
//			cout<<a[i].m<<' '<<a[i].st<<' '<<a[i].x<<'\n';
			ans+=a[i].m;
			cnt[a[i].st]++;
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]*2>n)
			{
				memset(tp,0,sizeof tp);
				long long s=0;
				for(int j=1;j<=n;j++)
				{
					if(a[j].st==i)
					{
						tp[++s]=a[j];
					}
				}
				sort(tp+1,tp+s+1,cmp);
				for(int j=1;n/2+j<=cnt[i];j++)
				{
					ans-=tp[j].x;
				}
			}
		}
		cout<<ans<<'\n';
	}
	

	return 0;
}
