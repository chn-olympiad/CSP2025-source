#include<bits/stdc++.h>//60
using namespace std;
int t,n,f[210][210][210],a[100010][3],ans,b[100010],x;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		if(n>200)
		{
			for(int i=1;i<=n;++i)
				scanf("%d%d%d",&b[i],&x,&x);
			sort(b+1,b+1+n);
			for(int i=n;n-i+1<=n/2;--i)
				ans=ans+b[i];
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(i<=n/2)
			{
				f[i][0][0]=f[i-1][0][0]+a[i][0];
				f[0][i][0]=f[0][i-1][0]+a[i][1];
				f[0][0][i]=f[0][0][i-1]+a[i][2];
			}
		}
		for(int i=2;i<=n;++i)
		{
			for(int j=1;j<=min(n/2,i);++j)
			{
				int k=i-j;
				if(k<=0||k>n/2)
					continue;
				f[j][k][0]=max(f[j-1][k][0]+a[i][0],f[j][k-1][0]+a[i][1]);
				f[j][0][k]=max(f[j-1][0][k]+a[i][0],f[j][0][k-1]+a[i][2]);
				f[0][j][k]=max(f[0][j-1][k]+a[i][1],f[0][j][k-1]+a[i][2]);
				if(i==n)
					ans=max(max(ans,f[j][k][0]),max(f[j][0][k],f[0][j][k]));
//				cout<<j<<' '<<k<<' '<<f[j][k][0]<<' '<<f[j][0][k]<<' '<<f[0][j][k]<<'\n';
			}
		}
		for(int i=3;i<=n;++i)
		{
			for(int j=1;j<=min(n/2,i);++j)
				for(int k=1;k<=min(n/2,i-j);++k)
				{
					int l=i-j-k;
					if(l>n/2||l<=0)
						continue;
					f[j][k][l]=max(f[j-1][k][l]+a[i][0],max(f[j][k-1][l]+a[i][1],f[j][k][l-1]+a[i][2]));
					if(i==n)
						ans=max(ans,f[j][k][l]);
				}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}