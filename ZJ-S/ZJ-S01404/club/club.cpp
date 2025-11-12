#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100005][3],T,Sum[3],b[100005];
int Get(int I)
{
	if(a[I][0]>=a[I][2]&&a[I][0]>=a[I][0]&&a[I][0]>=a[I][1])return 0;
	if(a[I][1]>=a[I][2]&&a[I][1]>=a[I][0]&&a[I][1]>=a[I][1])return 1;
	if(a[I][2]>=a[I][2]&&a[I][2]>=a[I][0]&&a[I][2]>=a[I][1])return 2;
}
int Swap(int u,int v)
{
	for(int i=1;i<=n;++i)
		swap(a[i][u],a[i][v]);
	swap(Sum[u],Sum[v]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		ans=0;
		Sum[0]=Sum[1]=Sum[2]=0;
		for(int i=1;i<=n;++i)
			++Sum[Get(i)],ans+=a[i][Get(i)];
		if(Sum[0]<Sum[1])Swap(0,1);
		if(Sum[0]<Sum[2])Swap(0,2);
		for(int i=1;i<=n;++i)
		{
			a[i][1]-=a[i][0];
			a[i][2]-=a[i][0];
			a[i][0]-=a[i][0];
		}
		b[0]=0;
		if(n/2<Sum[0])
		{
			for(int i=1;i<=n;++i)
				if(Get(i)==0)
					b[++b[0]]=max(a[i][1],a[i][2]);
			sort(b+1,b+1+b[0]);
			for(int i=b[0];i>n/2;--i)
				ans+=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
