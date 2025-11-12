#include<bits/stdc++.h>
using namespace std;
int t,b[4],c[100010];
struct node
{
	int s,id;
}a[100010][4];
bool cmp(node a,node b)
{
	if(a.s>b.s) return true;
	else return false;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n,ans=0;
		int a2=0,a3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1].s,&a[i][2].s,&a[i][3].s);
			if(a[i][2].s!=0) a2=1;
			if(a[i][3].s!=0) a3=1;
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
		}
		if(a3==0)
		{
			if(a2==0)
			{
				for(int j=1;j<=n;j++)
				{
					c[j]=a[j][1].s;
				}
				sort(c+1,c+1+n);
				for(int j=1;j<=n/2;j++)
				{
					ans+=c[j];
				}
				printf("%d\n",ans);
				continue;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			sort(a[i]+1,a[i]+4,cmp);
			if(b[a[i][1].id]<n/2)
			{
				b[a[i][1].id]++;
				ans+=a[i][1].s;
			}
			else
			{
				int p=0,ii,cc,dd;
				for(int j=1;j<i;j++)
				{
					if(a[i][1].id==a[j][1].id && a[i][1].s+a[j][2].s-a[j][1].s>0 && c[j]==0)
					{
						p=max(p,a[i][1].s+a[j][2].s-a[j][1].s);
						ii=a[j][2].id;
						cc=j;
						dd=2;
					}
					else if(a[i][1].id==a[j][2].id && a[i][1].s+a[j][3].s-a[j][2].s>0 && c[j]==2)
					{
						p=max(p,a[i][1].s+a[j][3].s-a[j][2].s);
						ii=a[j][3].id;
						cc=j;
						dd=3;
					}
				}
				if(p==0)
				{
					b[a[i][2].id]++;
					ans+=a[i][2].s;
					c[cc]=dd;
				}
				else
				{
					b[ii]++;
					ans+=p;
					c[cc]=dd;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
