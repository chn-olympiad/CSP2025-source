#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e5+9,M=2e6+9;
struct node{
	int u,v;
	ll w;
	bool operator <(const node &x)const{
		return w<x.w;
	}
}e[M],p[N],op[M],kk[19][N];
int n,m,k,cnt;
ll a[19][N],c[N];
ll ans=LINF;
int f[N];
void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}

inline int find(int u){
	return (f[u]==u?u:f[u]=find(f[u]));
}
void intt(int it){
	ll mini=0,minn=LINF;
	for(int i=1;i<=n;i++){
		if(minn>a[it][i]){
			minn=a[it][i];
			mini=i;
		}
	}
	c[it]+=minn;
	int num=0;
	for(int i=1;i<=n;i++){
		if(i!=mini){
			kk[it][++num]={mini,i,a[it][i]};
		}
	}
}

void solve(int opt){
	for(int i=1;i<=cnt;i++){
		op[i]=p[i];
	}
	int it=0,num=cnt;
	ll res=0,sds=0;
	while(opt){
		it++;
		if(opt&1){
			res+=c[it];
			for(int i=1;i<n;i++){
				op[++num]=kk[it][i];
			} 
		}
		opt>>=1;
	}
	init();
	sort(op+1,op+1+num);
	for(int i=1;i<=num;i++){
		int u=op[i].u,v=op[i].v;
		if(find(u)==find(v)) continue;
		f[find(u)]=find(v);
		res+=op[i].w;
		if(++sds==n-1) break;
	}
	ans=min(ans,res);
}
int ttt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	ttt=clock();
	cin>>n>>m>>k;
	int u,v;
	ll w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	init();
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)) continue;
		f[find(u)]=find(v);
		p[++cnt]={u,v,e[i].w};
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		intt(i);
	}
	for(int i=0;i<(1<<k);i++){
		solve(i);
	}
	cout<<ans<<"\n";
	return 0;
}

