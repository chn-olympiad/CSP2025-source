#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[5][N],m[5][N],c[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		m[1][0]=0;m[2][0]=0;m[3][0]=0;
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d %d",&a[1][i],&a[2][i],&a[3][i]);
			ans+=max(a[1][i],max(a[2][i],a[3][i]));
			if(a[1][i]>=a[2][i] && a[1][i]>=a[3][i])m[1][++m[1][0]]=i;
			else if(a[2][i]>=a[1][i] && a[2][i]>=a[3][i])m[2][++m[2][0]]=i;
			else if(a[3][i]>=a[1][i] && a[3][i]>=a[2][i])m[3][++m[3][0]]=i;
		}
		int x=0;
		for(int i=1;i<=3;++i)
			if(m[i][0]>n/2)x=i;
		if(x!=0)
		{
			if(x!=1)
			{
				swap(m[x],m[1]);
				swap(a[x],a[1]);
			}
			int l=0;
			for(int i=1;i<=m[1][0];++i)
			{
				int t=m[1][i];
				c[++l]=min(a[1][t]-a[2][t],a[1][t]-a[3][t]);
			}
			sort(c+1,c+l+1);
			for(int i=m[1][0],j=1;i>n/2;--i,++j)
				ans-=c[j];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
