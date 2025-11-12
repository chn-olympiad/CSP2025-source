#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct js
{
	int u,v,w;
}a[M],b[N*20],op[N];
int n,m,k,f[N+100],cnt=0,c[N];
int d[10][N];
bool cmp(js x,js y)
{
	return x.w<y.w;
}
int fa(int x)
{
	if(f[x]==x) return x;
	return f[x]=fa(f[x]);
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++)
		{
			if(fa(a[i].u)!=fa(a[i].v))
			{
				f[fa(a[i].u)]=fa(a[i].v);
				op[++cnt]=a[i];
			}
		}
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
				cin>>d[i][j];
		}
		long long res=1e18;
		for(int p=0;p<(1<<k);p++)
		{
			for(int i=1;i<n;i++)
				b[i]=op[i];
			cnt=n-1;
			long long ans=0;
			for(int i=1;i<=k;i++)
				if((1<<(i-1))&p)
				{
					ans+=c[i];
					for(int j=1;j<=n;j++)
						if(d[i][j]<b[n-1].w)
						b[++cnt]={n+i,j,d[i][j]};
				}
			sort(b+1,b+1+cnt,cmp);
			for(int i=1;i<=n+k;i++) f[i]=i;
			for(int i=1;i<=cnt;i++)
			{
				if(fa(b[i].u)!=fa(b[i].v))
				{
					f[fa(b[i].u)]=fa(b[i].v);
					ans+=b[i].w;
				}
			}
			res=min(res,ans);
		}
		cout<<res;
		return 0;
}

