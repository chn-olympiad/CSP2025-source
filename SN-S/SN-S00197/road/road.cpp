//CSP-S
//SN-S00197
//张之奇
//西安市铁一中学

#include <bits/stdc++.h>
using namespace std;

const int maxn=2e4+5;
const int maxm=2e6+5;
const int maxk=25;
const long long inf=1e15;
int n,m,k;
long long c[maxk];
long long a[maxk][maxn];

int cnt;
struct edge{
	int u,v;
	long long w;
	friend bool operator < (const edge &x,const edge &y){
		return x.w<y.w;
	}
}G[maxm],e[maxn*maxk],ed[maxn];

int f[maxn];
int find_fa(int x){
	if (f[x]==x)	return x;
	return f[x]=find_fa(f[x]);
}

long long kruskal(int n,int m,int flag){
	for (int i=1;i<=n;i++)	f[i]=i;
	sort(e+1,e+m+1);
	long long tot=0;
	for (int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		long long w=e[i].w;
		int fu=find_fa(u);
		int fv=find_fa(v);
		if (fu==fv)	continue;
		f[fu]=fv;
		tot+=w;
		if (flag)	ed[++cnt]=e[i];
	}
	return tot;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)	cin>>G[i].u>>G[i].v>>G[i].w;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++)	cin>>a[i][j];
	}
	for (int i=1;i<=m;i++)	e[i]=G[i];
	kruskal(n,m,1);
	long long ans=inf;
	for (int sta=0;sta<=(1<<k)-1;sta++){
		long long tot=0;
		int num=0;
		int mm=0;
		for (int i=1;i<=k;i++){
			if (sta&(1<<(i-1))){
				tot+=c[i];num++;
				for (int j=1;j<=n;j++)	e[++mm]={n+num,j,a[i][j]};
			}
		}
		for (int i=1;i<=n-1;i++)	e[++mm]=ed[i];
		tot+=kruskal(n+num,mm,0);
		ans=min(ans,tot);
	}
	cout<<ans;
	return 0;
}
