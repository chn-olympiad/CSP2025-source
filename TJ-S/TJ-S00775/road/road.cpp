#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int M=1000005,N=1005;
struct no{
	int u,v,w;
	bool operator < (const no b) const{
		return w<b.w;
	}
}a[M],c[N*10];
int b[11][N],fa[N+10];
inline int find(int u)
{
	if(fa[u]!=u)
		fa[u]=find(fa[u]);
	return fa[u];
}
inline void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,n,fu,fv,cnt,l,sum,m,k,r,maxx=0,tmp;
	ll ans=0,s=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
//	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
//		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+1+m);
	maxx=a[m].w;
	for(i=1;i<=k;i++)
	{
		for(j=0;j<=n;j++)
		{
			cin>>b[i][j];
//			scanf("%d",&b[i][j]);
		}
	}
	sum=0;
	init(n);
	for(i=1;i<=m;i++)
	{
		fu=find(a[i].u);
		fv=find(a[i].v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			ans+=a[i].w;
			sum++;
			if(sum==n-1)
				break;
		}
	}
//	cout<<ans;
	for(i=1;i<(1<<k);i++)
	{
		cnt=sum=s=tmp=0;
		for(j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				tmp++;
				for(l=1;l<=n;l++)
				{
					if(b[j+1][l]>=maxx)
						continue;
					c[++cnt].u=tmp+n;
					c[cnt].v=l;
					c[cnt].w=b[j+1][l];
				}
				s+=b[j+1][0];
			}
		}
		sort(c+1,c+1+cnt);
		l=r=1;
		init(n+tmp);
		while(sum<tmp+n-1)
		{
			if(s>=ans)
				break;
			while(find(c[r].u)==find(c[r].v)&&r<=cnt)
				r++;
			while(find(a[l].u)==find(a[l].v)&&l<=m)
				l++;
			if(a[l].w<=c[r].w)
			{
				s+=a[l].w;
				fa[find(a[l].u)]=find(a[l].v);
				sum++;
				l++;
			}
			else
			{
				s+=c[r].w;
				fa[find(c[r].u)]=find(c[r].v);
				sum++;
				r++;
			}
		}
		ans=min(ans,s);
	}
	cout<<ans;
//	printf("%lld %d",ans,clock());
	return 0;
}
