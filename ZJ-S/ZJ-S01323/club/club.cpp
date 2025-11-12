#include <bits/stdc++.h>
using namespace std;
struct point
	{
		long long mx,z,mi,id_mx;
	}a[100010];
struct edge
	{
		long long num,id;
	}q[100010];
long long T,n,cnt[100010],num[10],ans=0;
long long sum=0,len;
bool cmp(edge x,edge y)
	{
		return x.num<y.num;
	}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		{
			ans=sum=len=0;
			scanf("%d",&n);
			for(int i=1,x,y,z,mx,zz,mi;i<=n;i++)
				{
					mx=0,mi=0,zz=0;
					scanf("%d%d%d",&x,&y,&z);
					mx=max(x,max(y,z)),mi=min(x,min(y,z));
					if(x!=mx&&x!=mi) zz=x;
					if(y!=mx&&y!=mi) zz=y;
					if(z!=mx&&z!=mi) zz=z;
					a[i].mx=mx,a[i].mi=mi,a[i].z=zz;
					if(mx==x) a[i].id_mx=1;
					if(mx==y) a[i].id_mx=2;
					if(mx==z) a[i].id_mx=3;
				}
			for(int i=1;i<=3;i++) num[i]=0;
			for(int i=1;i<=n;i++)
				{
					cnt[i]=a[i].mx;
					num[a[i].id_mx]++;
				}
			for(int i=1;i<=3;i++)
				if(num[i]>(n/2)) sum=i;
			if(sum!=0)
				{
					for(int i=1;i<=n;i++)
						if(a[i].id_mx==sum)
							{
								len++;
								q[len].num=a[i].mx-a[i].z;
								q[len].id=i;
							}
					sort(q+1,q+1+len,cmp);
					for(int i=1;i<=num[sum]-n/2;i++) cnt[q[i].id]=a[q[i].id].z;
				}
			for(int i=1;i<=n;i++) ans+=cnt[i];
			printf("%lld\n",ans);
		}
	return 0;
}