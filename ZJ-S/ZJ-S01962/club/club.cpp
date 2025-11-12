#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][4],p[100010],c[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		int cnt[4],sum=0;
		memset(cnt,0,sizeof(cnt));
		memset(c,0x3f3f3f3f,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			int ma=-1;
			for(int j=1;j<=3;j++)
				if(ma<a[i][j])
					ma=a[i][j],p[i]=j;
			cnt[p[i]]++,sum+=ma; 
		}
		int pos=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]*2>n)	pos=i;
		if(pos!=0)
		{
			for(int i=1;i<=n;i++)
			{
				if(p[i]==pos)
				{
					int ma=-1,mi=1e9,mid=0;
					for(int j=1;j<=3;j++)
					{
						ma=max(ma,a[i][j]);
						mi=min(mi,a[i][j]);
						mid+=a[i][j];
					}
					mid=mid-ma-mi;
					c[i]=ma-mid;
				}
			}
			sort(c+1,c+1+n);
			for(int i=1;i<=cnt[pos]-n/2;i++)
				sum-=c[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
//部门满员后看谁去别的部门对答案的影响最小 
