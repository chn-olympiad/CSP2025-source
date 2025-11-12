#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10020;
int n,m,k,cnt,c[N],f[N],ans=1e18,ff;
struct edge{
	int u,v,w;
	bool operator<(const edge&a)const{
		return w<a.w;
	}
}e[N*110];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,
		e[++cnt]={u,v,w};
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ff+=c[i];
		int mn=1e18;
		for(int j=1,w;j<=n;j++)
			cin>>w,
			mn=min(mn,w),
			e[++cnt]={i+n,j,w};
		ff+=mn;
	}
	sort(e+1,e+1+cnt);
	for(int i=ff==0?(1<<k)-1:0;i<(1<<k);i++){
		int s=0,p=0;
		for(int j=1;j<=n+k;j++)
			f[j]=j;
		for(int j=0;j<n;j++)
			if(i>>j&1)
				s+=c[j+1],
				p++;
		for(int j=1,q=0;j<=cnt&&q<n+p;j++){
			int u=e[j].u,v=e[j].v;
			if(u>n&&!(i>>(u-n-1)&1))
				continue;
			if(v>n&&!(i>>(v-n-1)&1))
				continue;
			u=find(u),v=find(v);
			if(u!=v)
				s+=e[j].w,
				q++,
				f[u]=v;
		}
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}

