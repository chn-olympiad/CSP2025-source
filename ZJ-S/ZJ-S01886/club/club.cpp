#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,i,j,T,sum,ans,cnt,s1,s2,s3;
struct stu
{
	int ai,bi,ci,ii;
	int w1,w2;
}k[maxn];
int a[maxn][4],l[maxn];
bool cmp(stu x,stu y)
{
	return x.w1-x.w2>y.w1-y.w2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(l,0,sizeof(l));
		s1=0,s2=0,s3=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3])
			{
				s1++,k[i].w1=a[i][1];
				k[i].w2=max(a[i][2],a[i][3]);
			}
			else if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
			{
				s2++,k[i].w1=a[i][2];
				k[i].w2=max(a[i][1],a[i][3]);
			}
			else if(a[i][3]>a[i][1] && a[i][3]>a[i][2])
			{
				s3++,k[i].w1=a[i][3];
				k[i].w2=max(a[i][2],a[i][1]);
			}
			k[i].w1=max(a[i][1],max(a[i][2],a[i][3]));
			k[i].ai=a[i][1],k[i].bi=a[i][2],k[i].ci=a[i][3];
			k[i].ii=i;
	    }
		m=n/2;
		cnt=0;
		if(s1<=m && s2<=m && s3<=m)
		{
			ans=0;
			for(i=1;i<=n;i++)
			{
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			printf("%d\n",ans);
			continue;
		}
		sum=0;
		if(s1>m)
		{
			for(i=1;i<=n;i++)
			{
				if(a[i][1]<=a[i][2] || a[i][1]<=a[i][3])
				{
					ans+=k[i].w1;
					l[i]=1;
				}
			}
			sort(k+1,k+1+n,cmp);
			for(i=1;i<=n;i++)
			{
				if(l[k[i].ii]==1) continue;
				cnt++;
				if(cnt<=m) ans+=k[i].ai;
				else ans+=k[i].w2;
			}
		}
		else if(s2>m)
		{
			for(i=1;i<=n;i++)
			{
				if(a[i][2]<=a[i][3] || a[i][2]<=a[i][1])
				{
					ans+=k[i].w1;
					l[i]=1;
				}
			}
			sort(k+1,k+1+n,cmp);
			for(i=1;i<=n;i++)
			{
				if(l[k[i].ii]==1) continue;
				cnt++;
				if(cnt<=m) ans+=k[i].bi;
				else ans+=k[i].w2;
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				if(a[i][3]<=a[i][2] || a[i][3]<=a[i][1])
				{
					ans+=k[i].w1;
					l[i]=1;
				}
			}
			//cout<<ans<<"\n";
			sort(k+1,k+1+n,cmp);
			//for(i=1;i<=n;i++) cout<<k[i].ci<<" "<<k[i].w2<<" "<<"gkf\n";
			for(i=1;i<=n;i++)
			{
				if(l[k[i].ii]==1) continue;
				cnt++;
				if(cnt<=m) ans+=k[i].ci;
				else ans+=k[i].w2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//I want go to the qiguaixingweidashang!
//luogu uid：562443
//Go for it!
//Ren5Jie4Di4Ling5%
//15:54 yinggaiguole