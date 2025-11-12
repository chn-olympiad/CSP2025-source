#include<bits/stdc++.h>
using namespace std;

int T;
int n;
struct Stu{int a,b,c;
}g[100100];
int r[5010][5010],f[5010][5010];
int rc[50010],fc[50010];

bool cmp(Stu X,Stu Y)
{
	return X.a>Y.a;
}

int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d %d %d",&g[i].a,&g[i].b,&g[i].c);
		int ans=0;
		
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;++i)
		{
			if(g[i].b!=0)flag1=0;
			if(g[i].c!=0)flag2=0;
		}
		
		if(flag1)
		{
			sort(g+1,g+n+1,cmp);
			for(int i=1;i<=n/2;++i)ans+=g[i].a;
			cout<<ans<<'\n';
			continue;
		}
		if(flag2)
		{
			for(int j=0;j<=n;++j)fc[j]=rc[j]=0;
			for(int i=1;i<=n;++i)
			{
				for(int j=0;j<=i&&j<=n/2;++j)
				{
					fc[j]=0;
					if(i==1){
						fc[0]=g[i].a;
						fc[1]=g[i].b;
						ans=max(fc[0],fc[1]);
						continue;
					}
					if(i-j<=n/2)
					{
						int t=0;
						t=max(t,rc[j]+g[i].a);
						if(j>0)t=max(t,rc[j-1]+g[i].b);
						fc[j]=t;
					}
					ans=max(ans,fc[j]);
				}
				for(int j=0;j<=i&&j<=n/2;++j)
				{
					rc[j]=fc[j];
				}
			}
			
			cout<<ans<<'\n';
			continue;
		}
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				f[j][k]=r[j][k]=0;
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=i&&j<=n/2;++j)
			{
				for(int k=0;k<=i&&k<=n/2;++k)
				{
					f[j][k]=0;
					if(i==1){
						f[0][0]=g[i].a;
						f[1][0]=g[i].b;
						f[0][1]=g[i].c;
						ans=max(f[0][0],max(f[1][0],f[0][1]));
						continue;
					}
					if(i-j-k<=n/2)
					{
						int t=0;
						t=max(t,r[j][k]+g[i].a);
						if(j>0)t=max(t,r[j-1][k]+g[i].b);
						if(k>0)t=max(t,r[j][k-1]+g[i].c);
						f[j][k]=t;
					}
					ans=max(ans,f[j][k]);
				}
			}
			for(int j=0;j<=i&&j<=n/2;++j)
			{
				for(int k=0;k<=i&&k<=n/2;++k)
				{
					r[j][k]=f[j][k];
				}
			}
		}
		
		cout<<ans<<'\n';
	}
} 
