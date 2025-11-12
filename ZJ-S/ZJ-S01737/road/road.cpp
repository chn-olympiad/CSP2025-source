#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=1e6+10,M=1e4+10,K=1e3+10,mod=1e9+7;
const double eps=1e-1;
const long double pi=acos(-1);
int n,m,k,c[20],a[20][M],val[K][K],cnt,fa[M];
struct edge{
	int u,v,w;
}edg[N],edg2[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>edg[i].u>>edg[i].v>>edg[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		if(c[i]){
			flag=1;
			break;
		}
		int flg=0;
		for(int j=1;j<=n;j++){
			if(!a[i][j]){
				flg=1;
				break;
			}
		}
		if(!flg){
			flag=1;
			break;
		}
	}
	if(!flag){
		memset(val,0x3f,sizeof(val));
		for(int i=1;i<=m;i++){
			val[edg[i].u][edg[i].v]=min(val[edg[i].u][edg[i].v],edg[i].w);
			val[edg[i].v][edg[i].u]=min(val[edg[i].v][edg[i].u],edg[i].w);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=1;l<=k;l++){
					val[i][j]=min(val[i][j],a[l][i]+a[l][j]);
					val[j][i]=min(val[j][i],a[l][i]+a[l][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(val[i][j]!=0x3f3f3f3f3f3f3f3f)edg2[++cnt]=(edge){i,j,val[i][j]};
			}
		}
		sort(edg2+1,edg2+cnt+1,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		int sum=0,tot=0;
		for(int i=1;i<=cnt;i++){
			if(tot==n-1)break;
			int u=edg2[i].u,v=edg2[i].v,fu=getfa(u),fv=getfa(v);
			if(fu==fv)continue;
			tot++;
			sum+=edg2[i].w;
			fa[fu]=fv;
		}
		cout<<sum<<endl;
		return 0;
	}
	sort(edg+1,edg+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int sum=0,tot=0;
	for(int i=1;i<=m;i++){
		if(tot==n-1)break;
		int u=edg[i].u,v=edg[i].v,fu=getfa(u),fv=getfa(v);
		if(fu==fv)continue;
		tot++;
		sum+=edg[i].w;
		fa[fu]=fv;
	}
	cout<<sum<<endl;
	return 0;
}
