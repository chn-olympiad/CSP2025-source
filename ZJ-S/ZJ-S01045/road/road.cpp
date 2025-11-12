#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct eg{
	int u,v;
	long long w;
}e[2000005],e2[2000005];
bool cmp(eg a,eg b){
	return a.w<b.w;
}
long long c[15],a[15][10005];
int p[10005];
int find(int x){
	if(p[x]==x)return x;
	return p[x]=find(p[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//scanf("%d%d%d",&n,&m,&k);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)p[i]=i;
	int m2=m;
	for(int i=1;i<=m;i++){
		//scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool mbf=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];//scanf("%lld",&c[i]);
		int mb=-1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		//	scanf("%lld",&a[i][j]);
			if(a[i][j]==0)mb=j;
		}
		if(c[i]||mb==-1||(!mbf)){
			mbf=0;
			continue;
		}
		for(int j=1;j<=n;j++){
			e[++m].u=mb;
			e[m].v=j;
			e[m].w=a[i][j];
		}
	}
	if(mbf){
		sort(e+1,e+m+1,cmp);
		int cnn=0;
		long long ans=0;
		for(int i=1;i<=m&&cnn<n-1;++i){
			int xr=find(e[i].u);
			int yr=find(e[i].v);
			if(xr!=yr){
				p[xr]=yr;
				ans+=e[i].w;
				cnn++;
			}
		}
		cout<<ans;
		exit(0);
	}
	long long ans=0x3fffffffffffffff;
	m=m2;
	for(int i=1;i<=m;i++){
		e2[i]=e[i];
	}
	for(int zy=0;zy<(1<<k);zy++){
		long long re=0;
		m=m2;
		for(int i=1;i<=m;i++){
			e[i]=e2[i];
		}
		int ct=n;
		for(int i=1;i<=k;i++){
			if((zy>>(i-1))&1){
				re+=c[i];
				ct++;
				for(int j=1;j<=n;j++){
					e[++m].u=ct;
					e[m].v=j;
					e[m].w=a[i][j];
				}
			}
		}
		for(int i=1;i<=ct;i++)p[i]=i;
		sort(e+1,e+m+1,cmp);
		int cnn=0;
		for(int i=1;i<=m&&cnn<ct-1;i++){
			int xr=find(e[i].u);
			int yr=find(e[i].v);
			if(xr!=yr){
				p[xr]=yr;
				re+=e[i].w;
				cnn++;
			}
		}
		ans=min(ans,re);
	}
	cout<<ans;
	return 0;
}

