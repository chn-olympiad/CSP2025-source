#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],fi[100005],se[100005],cz[100005],js[4],ans,q[100005],qq;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(js,0,sizeof js);
		ans=qq=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				if(a[i][2]>a[i][3])fi[i]=1,se[i]=2;
				else fi[i]=1,se[i]=3;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				if(a[i][1]>a[i][3])fi[i]=2,se[i]=1;
				else fi[i]=2,se[i]=3;
			}
			else
			{
				if(a[i][1]>a[i][2])fi[i]=3,se[i]=1;
				else fi[i]=3,se[i]=2;
			}
			cz[i]=a[i][fi[i]]-a[i][se[i]];
			js[fi[i]]++;
			ans+=a[i][fi[i]];
		}
		if(js[1]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(fi[i]==1)
					q[++qq]=cz[i];
			sort(q+1,q+qq+1);
			for(int i=1;i<=js[1]-n/2;i++)ans-=q[i];
		}
		else if(js[2]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(fi[i]==2)
					q[++qq]=cz[i];
			sort(q+1,q+qq+1);
			for(int i=1;i<=js[2]-n/2;i++)ans-=q[i];
		}
		else if(js[3]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(fi[i]==3)
					q[++qq]=cz[i];
			sort(q+1,q+qq+1);
			for(int i=1;i<=js[3]-n/2;i++)ans-=q[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

*/