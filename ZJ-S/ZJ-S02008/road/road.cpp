#include<bits/stdc++.h>
using namespace std;
const int N=1e4+12,M=1e6+2;
int n,m,k,x,y,cnt,mx,f[N],a[12],b[12][N];
long long ans,sum;
struct edge{int u,v,w;}e[M],p[N],E[M];
int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}
bool cmp(edge x,edge y){return x.w<y.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	for(int i=1;i<=m;i++){
		x=e[i].u,y=e[i].v;
		if(fd(x)==fd(y))continue;
		ans+=e[i].w;
		f[fd(x)]=fd(y);
		p[++cnt]=e[i];
	}
	for(int i=1;i<(1<<k);i++){
		cnt=sum=0,mx=n-1;
		for(int j=1;j<=n+k;j++)f[j]=j;
		for(int i=1;i<n;i++)E[++cnt]=p[i];
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				++mx;
				for(int l=1;l<=n;l++)E[++cnt]={n+j,l,b[j][l]};
				sum+=a[j];
			}
		}
		sort(E+1,E+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			x=E[i].u,y=E[i].v;
			if(fd(x)==fd(y))continue;
			sum+=E[i].w;
			f[fd(x)]=fd(y);
			--mx;
			if(mx==0)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}