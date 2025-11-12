#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e18,c[15][10005],v[15];
int f[200005];
struct e{
	long long u,v,w;
};
e b[1000005],a[1000005];
bool cmp(e a,e b){
	return a.w<b.w;
}
int find(int u){
	if(u==f[u]) return u;
	return f[u]=find(f[u]);
}
void solve(int j){
	long long res=0,cnt=0,bs=0,cnt2=0;
	for(int i=1;i<=k;++i){
		if(j>>(i-1)&1){
			res+=v[i];
			++cnt2;
			for(int j=1;j<=n;++j) a[++cnt]={i+(int)n,j,(int)c[i][j]};
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=n+k;++i) f[i]=i;
	int now=1,now2=1;
	while(bs<n+cnt2-1){
		if(res>=ans) return ;
		e hd;
		if(now>m){
			hd=a[now2];
			++now2;
		}
		else if(now2>cnt){
			hd=b[now];
			++now;
		}
		else{
			if(a[now2].w<b[now].w){
				hd=a[now2];
				++now2;
			}
			else{
				hd=b[now];
			++now;
			}
		}
		int u=hd.u,v=hd.v,w=hd.w;
		u=find(u);
		v=find(v);
		if(u==v) continue;
		f[u]=v;
		++bs;
		res+=w;
	}
	ans=min(ans,res);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
	}
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=k;++i){
		cin>>v[i];
		for(int j=1;j<=n;++j){
			scanf("%lld",&c[i][j]);
		}
	}
	for(int i=0;i<(1<<k);++i) solve(i);
	cout<<ans;
	return 0;
}
