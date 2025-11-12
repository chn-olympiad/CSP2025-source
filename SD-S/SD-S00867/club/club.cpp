#include<bits/stdc++.h>
using namespace std;
long long c1[100010],c2[100010],c3[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long a1,a2,a3,ans=0,sum1=0,sum2=0,sum3=0;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%lld%lld%lld",&a1,&a2,&a3);
			int maxx=max(a1,max(a2,a3));
			ans+=maxx;
			int d;
			if(maxx==a1){d=min((maxx-a2),(maxx-a3));c1[sum1]=d;sum1++;}
			else if(maxx==a2){d=min((maxx-a1),(maxx-a3));c2[sum2]=d;sum2++;}
			else if(maxx==a3){d=min((maxx-a1),(maxx-a2));c3[sum3]=d;sum3++;}
		}
		if((sum1<=n/2)&&(sum2<=n/2)&&(sum3<=n/2)) printf("%lld\n",ans);
		else
		{
			int f=max((sum1-n/2),max((sum2-n/2),(sum3-n/2)));
			if(f==(sum1-n/2))
			{
				sort(c1,c1+sum1);
				for(int j=0;j<f;j++) ans-=c1[j];
			}
			else if(f==(sum2-n/2))
			{
				sort(c2,c2+sum2);
				for(int j=0;j<f;j++) ans-=c2[j];
			}
			else if(f==(sum3-n/2))
			{
				sort(c3,c3+sum3);
				for(int j=0;j<f;j++) ans-=c3[j];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
