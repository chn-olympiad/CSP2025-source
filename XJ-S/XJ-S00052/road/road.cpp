#include<bits/stdc++.h>
using namespace std;
long long h[2000005],idx,ne[2000005],w[2000005],e[2000005];
long long us[2000005],dp[10005],ans=0,ka[20],c[20][10005];
long long fa[10005],dep[10005],tofa[10005],idfa[10005],vis[2000005];
int lca(int a,int b)
{
//	cout<<a<<" "<<b<<endl;
	if(a==b) return a;
	if(dep[a]>dep[b]) return lca(fa[a],b);
	else if(dep[a]<dep[b]) return lca(a,fa[b]);
	else return lca(fa[a],fa[b]);
}
void add(int a,int b,int p)
{
	idx++;
	ne[idx]=h[a];
	h[a]=idx;
	e[idx]=b;
	w[idx]=p;
	return;
}
void djstl(int f,int u)
{
	queue<int> q;
	int i;
	for(i=h[u];i!=0;i=ne[i])
	{
//		cout<<i<<" "<<u<<"->"<<e[i]<<endl;
		if(i==f) continue;
		us[i]=0;
		if(dp[e[i]]>dp[u]+w[i])
		{
//			cout<<dp[e[i]]<<" "<<dp[u]+w[i]<<endl;
			us[i]=1;
			fa[e[i]]=u;
			dep[e[i]]=dep[u]+1;
			tofa[e[i]]=w[i];
			idfa[e[i]]=i;
			q.push(e[i]);
			dp[e[i]]=dp[u]+w[i];
		}
	}
	while(q.size())
	{
		djstl(u,q.front());
		q.pop();
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j,l,a,b,p;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b>>p;
		add(a,b,p);
		add(b,a,p);
	}
	for(i=1;i<=k;i++)
	{
		cin>>ka[i];
		for(j=1;j<=n;j++) cin>>c[i][j];
	}
	memset(dp,0x3f,sizeof dp);
	dp[1]=0;
	djstl(0,1);
//	for(i=1;i<=8;i++) cout<<h[i]<<" "<<ne[i]<<"     "<<e[i]<<" "<<w[i]<<endl;
//	for(i=1;i<=n;i++) cout<<fa[i]<<" "<<tofa[i]<<" "<<idfa[i]<<endl;
//	for(i=1;i<=n;i++) cout<<dp[i]<<" ";
//	cout<<endl;
	for(i=1;i<=2*m;i++)
	{
		if(us[i]==1) ans+=w[i];
	}
	long long cd;
	for(i=1;i<=k;i++)
	{
		cd=ans;
		ans+=ka[i];
		for(j=1;j<=n;j++)
		{
			for(l=j+1;l<=n;l++)
			{
//				cout<<j<<" "<<l<<endl;
				long long f=lca(j,l),le,ri,lei,rii,jj;
				if(f!=j&&f!=l) le=tofa[j],ri=tofa[l],lei=idfa[j],rii=idfa[l];
				else if(f==j)
				{
					ri=tofa[l];
					rii=idfa[l];
					for(jj=l;fa[jj]!=j;jj=fa[jj]);
					le=tofa[jj];
					lei=idfa[jj];
				}
				else if(f==l)
				{
					ri=tofa[j];
					rii=idfa[j];
					for(jj=j;fa[jj]!=l;jj=fa[jj]);
					le=tofa[jj];
					lei=idfa[jj];
				}
				if(ri>le&&ri>c[i][j]+c[i][l]&&vis[rii]==0) ans=ans-ri+c[i][j]+c[i][l],vis[rii]=1;
				else if(le>c[i][j]+c[i][l]&&vis[lei]==0)ans=ans-le+c[i][j]+c[i][l],vis[lei]=1;
//				cout<<j<<" "<<l<<" "<<le<<" "<<ri<<" "<<lei<<" "<<rii<<endl;
			}
		}
		if(ans>cd) ans=cd;
		for(j=1;j<=2*m;j++) vis[j]=0;
	}
	cout<<ans;
	return 0;
}
