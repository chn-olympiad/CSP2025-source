#include<bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x,i) cerr<<#x<<"="<<x<<" \n"[i]

const int MAX=1e3+10;
const int INF=1e18;

struct node
{
	int u,v,w;
};

int dis[MAX][MAX];
int tmp[MAX][MAX];
int c[MAX];
int a[15][MAX];
node edge[(int)2e6];
int f[MAX];

bool cmp(node x,node y)
{
	return x.w<y.w;
}

int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	else
	{
		return f[x]=find(f[x]);
	}
}

int read()
{
	int x=0;
	int f=1;
	char ch=getchar();
	
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
 } 

signed main()
{
	
//	freopen("data.txt","r",stdin);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	
//	cin>>n>>m>>k;	
	n=read();
	m=read();
	k=read();
	
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
//		cin>>u>>v>>w;
		u=read();
		v=read();
		w=read();
		dis[u][v]=w;
		dis[v][u]=w;
		ans=ans+w;
		
		if(k==0)
		{
			edge[i]={u,v,w};
		}
	}
	if(k==0)
	{
		int res=0;
		
		sort(edge+1,edge+1+m,cmp);
		
		for(int j=1;j<=n;j++)
		{
			f[j]=j;
		}
		
		for(int j=1;j<=m;j++)
		{
			int fu=find(edge[j].u);
			int fv=find(edge[j].v);
			if(fu==fv)
			{
				continue;
			}
			f[fu]=fv;
			res=res+edge[j].w;
		}
		
		cout<<res<<endl;
		return 0; 
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
//		cin>>c[i];
		c[i]=read();
		if(c[i]!=0)
		{
			flag=0; 
		}
		for(int j=1;j<=n;j++)
		{
//			cin>>a[i][j];
			a[i][j]=read();
			if(a[i][j]!=0)
			{
				flag=0;
			}
		}
	}
	if(flag)
	{
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=0;i<(1<<k);i++)
//	int i=1;
	{
		int cnt=0;
		int res=0;
		
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(dis[j][k])
					tmp[j][k]=dis[j][k];
				else 
					tmp[j][k]=INF;
			}
		}
		
		int tmp1=i;
		while(tmp1)
		{
			cnt++;
			int opt=tmp1%2;
			tmp1=tmp1/2;
			if(opt)
			{
				res=res+c[cnt];
				res=res+a[cnt][cnt];
				for(int j=1;j<=n;j++)
				{
					tmp[cnt][j]=min(a[cnt][j],tmp[cnt][j]);
					tmp[j][cnt]=min(a[cnt][j],tmp[cnt][j]);
				}
			}
		}
		
//		debug(res,1);
		
		int tot=0;
		
//		debug(i,1);
		
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j==k)
				{
					continue;
				}
				if(tmp[j][k])
				{
					int a=min(j,k);
					int b=max(j,k); 
					edge[++tot]={a,b,tmp[j][k]};
					
//					debug(j,0);
//					debug(k,0);
//					debug(edge[tot].w,1);
				}
			}
		}
		
		sort(edge+1,edge+1+tot,cmp);
		
		for(int j=1;j<=n;j++)
		{
			f[j]=j;
		}
		
		for(int j=1;j<=tot;j++)
		{
			int fu=find(edge[j].u);
			int fv=find(edge[j].v);
			if(fu==fv)
			{
				continue;
			}
			f[fu]=fv;
			res=res+edge[j].w;
//			debug(edge[j].u,0);
//			debug(edge[j].v,0);
//			debug(edge[j].w,1);
		}
		
		ans=min(res,ans);
	}
	
	cout<<ans<<endl;
	return 0;
 }

