#include<bits/stdc++.h>
using namespace std;
const int maxn=501;
int n,t;
long long ans,a[maxn][3],b[maxn],c[maxn],d[maxn],f[maxn][maxn][maxn];
bool spea,speb;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0ll;
		spea=1;
		speb=1;
		cin>>n;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++) f[i][j][k]=0;
			}
		}
		for(int i=0;i<=n;i++) a[i][0]=0,a[i][1]=0,a[i][2]=0;
		memset(b,0ll,sizeof b);
		memset(c,0ll,sizeof c);
		memset(d,0ll,sizeof d);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[i]=a[i][0];
			c[i]=a[i][1];
			d[i]=a[i][2];
			if(not((a[i][0]==0 and a[i][1]==0 and a[i][2]!=0) or (a[i][0]==0 and a[i][1]!=0 and a[i][2]==0) or (a[i][0]!=0 and a[i][1]==0 and a[i][2]==0))) spea=0;
		}
		if(spea)
		{
			if(b[1]!=0)
			{
				sort(b+1,b+n+1,cmp);
				for(int i=1;i<=n/2;i++) ans+=b[i];
			}
			else if(c[1]!=0)
			{
				sort(c+1,c+n+1,cmp);
				for(int i=1;i<=n/2;i++) ans+=c[i];
			}
			else if(d[1]!=0)
			{
				sort(d+1,d+n+1,cmp);
				for(int i=1;i<=n/2;i++) ans+=d[i];
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=0;i<=n/2;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2 and i+j+k<=n;k++)
					{
						int x=i+j+k;
						if(i*j*k>0) f[i][j][k]=max(f[i][j][k-1]+a[x][2],max(f[i][j-1][k]+a[x][1],f[i-1][j][k]+a[x][0]));
						else if(i>0 and j>0 and k==0) f[i][j][k]=max(f[i][j-1][k]+a[x][1],f[i-1][j][k]+a[x][0]);
						else if(i>0 and j==0 and k>0) f[i][j][k]=max(f[i][j][k-1]+a[x][2],f[i-1][j][k]+a[x][0]);
						else if(i==0 and j>0 and k>0) f[i][j][k]=max(f[i][j][k-1]+a[x][2],f[i][j-1][k]+a[x][1]);
						else if(i>0 and j==0 and k==0) f[i][j][k]=f[i-1][j][k]+a[x][0];
						else if(j>0 and i==0 and k==0) f[i][j][k]=f[i][j-1][k]+a[x][1];
						else f[i][j][k]=f[i][j][k-1]+a[x][2];
					}
				}
			}
			for(int i=0;i<=n/2;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					int k=n-i-j;
					ans=max(ans,f[i][j][k]);
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
