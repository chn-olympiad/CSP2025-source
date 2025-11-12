#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
const int M = 1e6+10;
int n,m,k,x,y,w,cnt,c[11],city;
int fa[N<<1],sum,a[11][N],id[11];
int ans=LLONG_MAX;
struct node{
	int x,y,w;
	bool operator <(const node &op)const{
		return w<op.w;
	}
}r[M],key[M],e[M<<1];
//O(5*(2^k)*nlogn)
//It have tried my best
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
void dfs(int pos,int st){
	if(pos>=k){
		for(int i=1;i<n;++i) e[i]=key[i];
		cnt=n-1;
		sum=0;
		for(int i=1;i<=k;++i){
			if((st>>(i-1))&1){
				sum+=c[i]+a[i][id[i]];
				for(int j=1;j<=n;++j){
					if(id[i]==j) continue;
					e[++cnt]={id[i],j,a[i][j]};
				}
			}
		}
		sort(e+1,e+cnt+1);
		for(int i=1;i<=n;++i) fa[i]=i;
		int num=0;
		for(int i=1;i<=cnt&&num<n;++i){
			x=e[i].x,y=e[i].y,w=e[i].w;
			int fx=find(x),fy=find(y);
			if(fx==fy) continue;
			fa[fx]=fy;
			++num;
			sum+=w;
		}
		ans=min(ans,sum);
		return;
	}
	dfs(pos+1,st);
	dfs(pos+1,st|(1ll<<pos));
}
/*
13
505585650
504898585
5182974424
*/
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>w;
		r[i]={x,y,w};
	}
	sort(r+1,r+m+1);
	int num=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m&&num<n;++i){
		x=r[i].x,y=r[i].y,w=r[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		fa[fx]=fy;
		key[++num]=r[i];
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		int minn=INT_MAX;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]<minn){
				id[i]=j;
				minn=a[i][j];
			}
		}
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}