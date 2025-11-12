#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
struct node{
	int to,w;
	node(){
	}
	node(int to,int w):to(to),w(w){
	} 
};
const int N=1e4;
int minn[N];
long long ans=1e15;
int f[11];int n,m,k,u,v1,w,w1;
vector<node>v[N];
vector<int>v2[11];
int minx[N];
bool vis[N];
int c[11];
long long prim()
{
	long long sum=0;
	for(int i=1;i<=n;i++)minn[i]=inf;
	for(int i=1;i<=n;i++)vis[i]=0;
	minn[1]=0;
	for(int i=1;i<=n;i++)
	{
		int minnn=inf,u;
		for(int i=1;i<=n;i++)
		{
			if(minnn>minn[i]&&!vis[i])
			{
				minnn=minn[i];
				u=i;
			}
		}
		vis[u]=1;
		for(auto it=v[u].begin();it!=v[u].end();it++)
		{
			node j=*it;
			int to= j.to;
			if(!vis[to]&&minn[to]>j.w)minn[to]= j.w;
		}
		for(int l=1;l<=k;l++)
		for(int j=1;j<=n;j++)
		{
			if(vis[j])continue;
			if(minn[j]>v2[l][j-1]+v2[l][u-1])minn[j]=v2[l][j-1]+v2[l][u-1];
		}
	}
	for(int i=1;i<=n;i++)sum+=minn[i];
	return sum;
}
void dfs(int step,long long sum)
{
	if(step==k+1)
	{
		memset(minx,0x3f,sizeof(minx));
		long long temp=sum+prim();
		ans=min(ans,temp);
		return; 
	}
	if(f[step])dfs(step+1,sum);
	else
	{
		f[step]=1;
		dfs(step+1,sum+c[step]);
		f[step]=0;
		dfs(step+1,sum);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		u=read(),v1=read(),w=read();
		v[u].push_back(node(v1,w));
		v[v1].push_back(node(u,w));
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]==0)f[i]=1;
		for(int j=1;j<=n;j++)w1=read(),v2[i].push_back(w1);
	}
		
	dfs(1,0);
	cout<<ans;
	return 0;
}

