#include<bits/stdc++.h>
using namespace std;
long long b[1000210],n,m,bls[2000210],k,a[19],x,y,z,dis[10210],d[10210],ab[19];
long long to[2000210],nxt[2000210],head[2000210],w[2000210],tot,ey[11][10010];
long long ans,sum,MAX;
queue<int> q;
void add(int x,int y,int z)
{
	nxt[++tot]=head[x];head[x]=tot;to[tot]=y;w[tot]=z;
	nxt[tot+n+k*n]=head[y];head[y]=n+k*n+tot;to[n+k*n+tot]=x;w[n+k*n+tot]=z;
}
void spfa()
{
	dis[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(d[u]==1) continue;
		d[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			int go=to[i],W=w[i];
			d[go]=1;
			if(go<=n&&dis[go]>dis[u]+W)
			{
				dis[go]=dis[u]+W;
				b[head[u]]=1;
				b[bls[go]]=0;
				bls[go]=head[u];
//				if(bls[go]>n) ab[bls[go]-n]=0;
				q.push(go);d[go]=0;
			}
			/*
			if(go>n)
			{
				if(ab[go-n]==1)
				{
					if(dis[go]>dis[u]+W)
					{
						dis[go]=dis[u]+W;
						b[head[u]]=1;
						b[bls[go]]=0;
						if(bls[go]>n) ab[bls[go]-n]=0;
						bls[go]=head[u];
					}
				}
				else
				{
					if(dis[go]>dis[u]+W+a[go-n])
					{
						dis[go]=dis[u]+W+a[go-n];
						ab[go-n]=1;
						b[head[u]]=1;
						b[bls[go]]=0;
						if(bls[go]>n) ab[bls[go]-n]=0;
						bls[go]=head[u];
					}
				}
			}
			*/
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) dis[i]=1e9+7;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&ey[i][j]);
			add(n+i,j,ey[i][j]);
		}
	}
	spfa();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int l=1;l<=k;l++)
	if(i!=j)
	{
		if(ab[l]==1&&dis[j]>dis[i]+ey[l][i]+ey[l][j])
		{
			sum+=dis[j]-dis[i]-ey[l][i]-ey[l][j];
			if(bls[j]>n&&bls[j]-n!=ab[l]) ab[bls[j]-n]=0;
			b[bls[j]]=0;
			bls[j]=n+l;
		}
		else if(ab[l]==0&&dis[j]>dis[i]+ey[l][i]+ey[l][j]+a[l])
		{
			sum+=dis[j]-dis[i]-ey[l][i]-ey[l][j]-a[l];
			if(bls[j]>n&&bls[j]-n!=ab[l]) ab[bls[j]-n]=0;
			b[bls[j]]=0;
			bls[j]=n+l;
			ab[l]=1;
		}
	}
	for(int i=1;i<=tot/2;i++)
	if(b[i]==1||b[i+tot/2]==1) ans+=w[i];
//	for(int i=1;i<=k;i++)
//	if(ab[i]==1) ans+=a[i];
	MAX=0ll;
	for(int i=1;i<=n;i++)
	MAX=max(MAX,dis[i]);
	cout<<MAX<<endl;
	return 0;
}
