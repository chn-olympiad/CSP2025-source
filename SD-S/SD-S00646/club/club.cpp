#include<bits/stdc++.h>
using namespace std;
struct p{
	int x,y,z;
}a[2000020];
bool cmp1(p c,p b)
{
	return c.x>b.x;
}
int t;
int n,ans=0;
int ry[2000020];
int ra,rb,rc;
bool xzA=1;
int maxn=0;
void suan(int w)
{
	if(w>n)
	{
		maxn=max(ans,maxn);
		return ;	
	}
	suan(w+1);
	if(ra>0&&a[w].x!=0)
	{
		ans+=a[w].x;
		ra--;
		suan(w+1);
		ans-=a[w].x;
		ra++;
	}
	if(rb>0&&a[w].y!=0)
	{
		ans+=a[w].y;
		rb--;
		suan(w+1);
		ans-=a[w].y;
		rb++;
	}
	if(rc>0&&a[w].z!=0)
	{
		ans+=a[w].z;
		rc--;
		suan(w+1);
		ans-=a[w].z;
		rc++;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		ans=0;
		maxn=0;
		ra=n/2;
		rb=n/2;
		rc=n/2;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].x>>a[j].y>>a[j].z;
			if(a[j].y!=0||a[j].z!=0)
				xzA=0;
		}
		if(xzA==1)
		{
			sort(a+1,a+1+n,cmp1);
			for(int j=1;j<=n/2;j++)
				ans+=a[j].x;
			printf("%d\n",ans);
			continue;
		}
		suan(1);
		printf("%d\n",maxn);
	}
	return 0;
}

