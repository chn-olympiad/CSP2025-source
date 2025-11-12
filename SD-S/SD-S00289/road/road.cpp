#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1005,M=1e6+7;
int fa[N],n,m,k,c,a[N];
int mp[N][N],p[N][N];
struct node{
	int x,y,z; 
}edge[M<<2];
bool cmp(node a,node b){return a.z<b.z;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
} 
 
void write(long long x)
{
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	memset(mp,-1,sizeof(mp));
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		edge[i].x=read();
		edge[i].y=read();
		edge[i].z=read();
		mp[edge[i].x][edge[i].y]=edge[i].z;
		mp[edge[i].y][edge[i].x]=edge[i].z;
		p[edge[i].x][edge[i].y]=i;
		p[edge[i].y][edge[i].x]=i;
	}
	int tot=m;
	for(int i=1;i<=k;i++)
	{
		c=read();
		for(int j=1;j<=n;j++)a[j]=read();
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j!=k)
				{
					if(mp[j][k]==-1)
					{
						edge[++tot].x=j;
						edge[tot].y=k;
						edge[tot].z=a[j]+a[k];
						p[j][k]=tot;
						mp[j][k]=a[j]+a[k];
					}
					else if(a[j]+a[k]<mp[j][k])
					{
						edge[p[j][k]].x=j;
						edge[p[j][k]].y=k;
						edge[p[j][k]].z=a[k]+a[j];
						mp[j][k]=a[k]+a[j];
					}
				}
			}
		}
	}
	sort(edge+1,edge+tot+1,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(cnt==n-1)break;
		int nowx=find(edge[i].x);
		int nowy=find(edge[i].y);
		if(nowx!=nowy)
		{
			ans+=edge[i].z;
			fa[nowy]=nowx;
			cnt++;
		}
	}
	write(ans);
	return 0;
}

