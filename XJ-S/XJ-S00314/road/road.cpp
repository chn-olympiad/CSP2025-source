#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,m,k,a;long long ans,cnt,b;
struct node{
	long long u,v,w,f=0,q;
}r[maxn];
struct q{
	int t,ww;
}aq[maxn];
int f[maxn],g[maxn];long long c[maxn];
int fin(int x){
	if(f[x]==x) return x;
	return f[x]=fin(f[f[x]]);
}
bool cmp(node x,node y){
	if(x.w==y.w) return x.u<y.u; 
	return x.w<y.w;
}
bool cmp2(q x,q y){
	return x.t<y.t;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	c[0]=0;g[0]=1;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	cnt=m+1;
	for(int i=1;i<=maxn;i++){
		f[i]=i;g[i]=0;r[i].q=0;r[i].f=0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			r[cnt].u=i+n;
			r[cnt].v=j;
			r[cnt].w=c[i]+a;
			r[cnt].f=i;
			cnt++;
			r[cnt].u=i+n;
			r[cnt].v=j;
			r[cnt].w=a;
			r[cnt].f=i;
			r[cnt].q=i;
			cnt++;
		}
	}
	sort(r+1,r+1+cnt,cmp);b=1;
	for(int i=1;i<=cnt;i++){
		if(fin(r[i].u)==fin(r[i].v)||g[r[i].q]==0){
			continue;
		}
		g[r[i].f]=1;
		ans+=r[i].w;
		f[fin(r[i].v)]=fin(r[i].u);
		if(r[i].u>n){
			aq[b].t=r[i].u;
			aq[b].ww=r[i].w;b++;
		}

	}
	sort(aq+1,aq+1+b,cmp2);
	if(aq[1].t!=aq[2].t) ans-=aq[1].ww;
	if(aq[b-1].t!=aq[b].t) ans-=aq[b].ww;
	for(int i=2;i<b;i++){
		if(aq[i].t!=aq[i+1].t&&aq[i-1].t!=aq[i].t){
			ans-=aq[i].ww;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
