#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+107;
ll n,m,ans,cnt,k,a[17][N],c[17],x,y,z,f[17],fa[N],num;
ll i,j,h;
struct node{
	ll now,to,w;
	bool friend operator<(const node &x,const node &y){
		return x.w>y.w;
	}
}b[N*100],xx,bb[N*100];
vector<node>g[N];
ll gf(ll now){
	return now==fa[now]?now:fa[now]=gf(fa[now]);
}
void kr(ll zy){
	priority_queue<node>q;
	cnt=0;
	num=n;
	for(i=1;i<=k;i++){
		f[i]=zy&1;
		zy>>=1;
		if(f[i]){
			for(j=1;j<=n;j++){
				q.push({j,n+i,a[i][j]});
			}
			num+=1;
			cnt+=c[i];
		}
	}
	for(i=1;i<=n+k;i++)fa[i]=i;
	for(i=1;i<n;i++)q.push(b[i]);
	for(h=1;h<num;h++){
		xx=q.top();
		q.pop();
		while(gf(xx.now)==gf(xx.to)){
			xx=q.top();
			q.pop();
		}
		cnt+=xx.w;
		fa[fa[xx.to]]=fa[xx.now];
	}
	ans=min(ans,cnt);
}
void kr2(){
	priority_queue<node>q;
	cnt=0;
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)q.push(bb[i]);
	for(h=1;h<n;h++){
		xx=q.top();
		q.pop();
		while(gf(xx.now)==gf(xx.to)){
			xx=q.top();
			q.pop();
		}
		cnt+=xx.w;
		fa[fa[xx.to]]=fa[xx.now];
		b[h]=xx;
	}
	ans=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		g[x].push_back({x,y,z});
		g[y].push_back({y,x,z});
		bb[i]={x,y,z};
	}
	for(i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	kr2();
	for(x=1;x<1<<k;x++){
		kr(x);
	}
	printf("%lld",ans);
	return 0;
}
