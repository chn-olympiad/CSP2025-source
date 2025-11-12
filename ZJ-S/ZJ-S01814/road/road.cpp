#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
const int M=1e6+20;
int n,m,k,cnt,fx,fy,mi,x,y,z;
int b[11][N],f[N],vis[N],co[20];
struct Node{
	int x,y,z;
}a[M],d[M];
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int find(int x)
{
	if (f[x]==x)	return x;
	else			return f[x]=find(f[x]);
}
bool cmp(Node q,Node h){return q.z<h.z;}
void dfs(int t)
{
	if (t==k+1)
	{
		int tmp=cnt;
		for (int i=1;i<=k;i++)
			if (vis[i])
			{
//				cout<<i<<"\n";
				for (int j=1;j<=n;j++)
					a[++cnt]={n+i,j,b[i][j]};
//				cout<<a[cnt].x<<" "<<a[cnt].y<<" "<<a[cnt].z<<"\n";
			}
		for (int i=1;i<=cnt;i++)	d[i]=a[i];
		sort(d+1,d+1+cnt,cmp);
//		for (int i=1;i<=cnt;i++)
//		{
//			cout<<d[i].x<<" "<<d[i].y<<" "<<d[i].z<<"\n";
//		}
//		cout<<"\n\n";cnt=tmp;return ;
		for (int i=1;i<=n+k;i++)	f[i]=i;
		int sum=0;int jie=n;
		for (int i=1;i<=k;i++)	if (vis[i])	sum+=co[i],jie++;
//		cout<<jie<<"\n";cnt=tmp;return ;
		int che=0;
		for (int i=1;i<=cnt;i++)
		{
			fx=find(d[i].x);fy=find(d[i].y);
			if (fx!=fy)
			{
				sum+=d[i].z;
				che++;
//				cout<<fx<<" "<<fy<<"\n";
				f[fx]=fy;
			}
			if (che==jie-1)
			{
				break;
			}
		}
//		cout<<sum<<"\n\n";
		if (che==jie-1)	mi=min(mi,sum);
		cnt=tmp;
		return ;
	}
	vis[t]=1;dfs(t+1);
	vis[t]=0;dfs(t+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for (int i=1;i<=m;i++)
	{
		x=read();y=read();z=read();
		a[++cnt]={x,y,z};
//		a[++cnt]={y,x,z};
	}
	for (int i=1;i<=k;i++)
	{
		co[i]=read();
		for (int j=1;j<=n;j++)	b[i][j]=read();
	}
	mi=1e10;
	dfs(1);
	cout<<mi;
	return 0;
}
