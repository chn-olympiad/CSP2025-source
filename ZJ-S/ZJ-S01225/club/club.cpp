#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,ans,cnt[4],k;
struct node
{
	int x,y,z;
}p[100001];
bool cmp(const node &u,const node &v)
{
	return u.y<v.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i;
	scanf("%d",&T);
	while(T--)
	{
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		k=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			p[i].x=0;
			p[i].y=0;
			p[i].z=0;
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b && a>=c)
			{
				cnt[1]++;
				p[i].x=a;
				p[i].z=1;
				if(b>=c)
				{
					p[i].y=a-b;
				}
				else
				{
					p[i].y=a-c;
				}
			}
			else if(b>=a && b>=c)
			{
				cnt[2]++;
				p[i].x=b;
				p[i].z=2;
				if(a>=c)
				{
					p[i].y=b-a;
				}
				else
				{
					p[i].y=b-c;
				}
			}
			else if(c>=a && c>=b)
			{
				cnt[3]++;
				p[i].x=c;
				p[i].z=3;
				if(a>=b)
				{
					p[i].y=c-a;
				}
				else
				{
					p[i].y=c-b;
				}
			}
			ans+=p[i].x;
		}
		int id=0,sum=0;
		for(i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				k=cnt[i]-n/2;
				id=i;
				break;
			}
		}
		if(k>0)
		{
			sort(p+1,p+n+1,cmp);
			for(i=1;i<=n;i++)
			{
				if(p[i].z==id)
				{
					ans-=p[i].y;
					sum++;
				}
				if(sum==k)
				{
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
