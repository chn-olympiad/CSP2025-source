#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read();
const int N=1e4+10; 

int a[N][N],sum;
bool b[N];

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			a[i][j]=LLONG_MAX;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[y][x]=a[x][y]=min(a[x][y],read());
	}
	for(int i=1;i<=m;i++)
	{
		int x=read();
		for(int j=1;j<=n;j++)
		{
			x=read();
		}
	}
	
	b[1]=1;
	for(int i=1;i<n;i++)
	{
		int minn=LLONG_MAX,t=0,s=0;
		for(int j=1;j<=n;j++)
		{
			if(b[j])
			{
				for(int k=1;k<=n;k++)
				{
					if(b[i]==0);
					if(minn>a[j][k])
					{
						minn=a[j][k];
						t=k;
						s=j;
					}
				}
			}
		}
		b[t]=1;
		sum+=a[t][s];
		a[t][s]=LLONG_MAX;
		a[s][t]=LLONG_MAX;
	}
	printf("%d",sum);
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline int read()
{
	int x=0,s=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*s;
}

