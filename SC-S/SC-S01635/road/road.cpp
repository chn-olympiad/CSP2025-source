#include<bits/stdc++.h>

using namespace std;
int cbw[11],cun[11][10001];
bool stc[11];
struct E
{
	int u,v,w;
	int c;
	bool operator < (const E& o) const{
		return w<o.w;
	}
}e[1000001];
int f[10001];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k,w;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].c=0;
	}
	int tot=m;
	for(int i=1;i<=k;i++)
	{
		cin>>cbw[i];
		for(int j=1;j<=n;j++)
		{
			cin>>cun[i][j];
			for(int jj=1;jj<j;jj++)
			{
				e[++tot].u=j;
				e[tot].v=jj;
				e[tot].w=cun[i][j]+cun[i][jj];
				e[tot].c=i;
			}
		}
	}
	sort(e+1,e+tot+1);
	long long ans=0;
	for(int i=1;i<=tot;i++)
	{
		int x=e[i].u,y=e[i].v;
		w=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		int dis=w;
		if(!stc[e[i].c])
		{
			dis+=cbw[e[i].c];
			stc[e[i].c]=1;
		}
		ans+=dis;
		// cout<<x<<' '<<y<<' '<<dis<<endl;
		f[fx]=fy;
	}
	cout<<ans<<endl;
	
	return 0;
}
