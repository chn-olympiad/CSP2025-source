#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MXN = 10020;
const int MXE = 1000020;
int n,m,k,a[12][MXN],c[12],f[MXN],mx,s[MXN],bo[12];
ll ans;
struct edge{
	int u,v,w;
}E[MXE],e0[MXN],e[MXN<<4];
bool operator< (const edge &x,const edge &y){
	return x.w<y.w;
}
int e0cnt,ecnt;

int find(int u)
{
	if(f[u]==u) return u;
	return f[u]=find(f[u]);
}
int main()
{
	freopen("road4.in","r",stdin);
//	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[i]={u,v,w};
	}
	for(int i=1;i<=n;i++) f[i]=i,s[i]=1;
	sort(E+1,E+m+1);
	for(int i=1;i<=m;i++)
	{
		int u=E[i].u,v=E[i].v;
		u=find(u),v=find(v);
		if(u==v) continue;
		if(s[u]<s[v]) swap(u,v);
		f[v]=u;s[u]+=s[v];s[v]=0;
		ans+=E[i].w;mx=max(mx,E[i].w);
		e0[++e0cnt]=E[i];
	}
//	cout<<ans<<" "<<mx<<endl;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int pos=1,res0=0;
	while(pos)
	{
		pos=0;
		for(int i=1;i<=k;i++)
		{
			if(bo[i]) continue;
			ll res=res0+c[i];
			int mx0=0;
			ecnt=e0cnt;
			for(int j=1;j<=ecnt;j++) e[j]=e0[j];
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]>=mx) continue;
				e[++ecnt]={n+i,j,a[i][j]};
			}
			for(int j=1;j<=n+k;j++) f[j]=j,s[j]=1;
			sort(e+1,e+ecnt+1);
			for(int j=1;j<=ecnt;j++)
			{
//				cout<<"---"<<e[j].u<<" "<<e[j].v<<" "<<e[j].w<<endl;
				int u=e[j].u,v=e[j].v;
				u=find(u),v=find(v);
				if(u==v) continue;
				if(s[u]<s[v]) swap(u,v);
				f[v]=u;s[u]+=s[v];s[v]=0;
				res+=e[j].w;mx0=max(mx0,e[j].w);
			}
//			cout<<i<<" "<<res<<endl;
			if(res<ans) ans=res,pos=i,mx=mx0;
		}
//		cout<<"pos:"<<pos<<endl;
		if(pos)
		{
			res0+=c[pos];
			for(int i=1;i<=n;i++)
			{
				if(a[pos][i]>mx) continue;
				e0[++e0cnt]={n+pos,i,a[pos][i]};
			}
			bo[pos]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
