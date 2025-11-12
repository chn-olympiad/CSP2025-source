#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+99;
const int M=1e4+99;
const int inf=1e9+7;
struct node{
	int u,v,w;
	int typ;
	friend bool operator >(node x,node y){
		return x.w>y.w;
	}
}e[N];
int tag[12],cnt;
int n,m,k,c[12][M],f[M],link[12][M];
int find(int x){return f[x]==x ? x:f[x]=find(f[x]);}
bitset<M> s[M];
void kruskal(){
	int all=n;
	while(sum<all-1){
		node nw=q.top();q.pop();
		if(find(nw.u)==find(nw.v)) continue;
		sum++;
		int fu=find(nw.u),fv=find(nw.v);
		int pos=-1,minn=nw.w,pl=-1,pr=-1;
		for(int i=1;i<=k;i++){
			int cost;
			if(tag[i]) cost=0;
			else cost=c[i][0];
			int lmin=inf,rmin=inf,l=-1,r=-1;
			for(int j=1;j<=n;j++){
				if(s[fu][j]==1){
					if(link[i][j]) lmin=0,l=j;
					else{
						if(lmin>c[i][j]){
							lmin=c[i][j];
							l=j;
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(s[fv][j]==1){
					if(link[i][j]) rmin=0,r=j;
					else{
						if(rmin>c[i][j]){
							rmin=c[i][j];
							r=j;
						}
					}
				}
			}
			if(lmin+rmin+cost<=minn){
				pos=i;
				minn=lmin+rmin+cost;
				pl=l,pr=r;
			}
		}
		if(pos!=-1){
			tag[pos]=1;
			if(pl!=-1) link[pos][pl]=1;
	    	if(pr!=-1) link[pos][pr]=1;
		}
		ans+=minn;
		s[fv]|=s[fu];
		f[fu]=fv;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i,s[i][i]=1;
	for(int u,v,w,i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		e[++cnt].u=u;e[cnt].v=v;e[cnt].w=w;e[cnt].typ=0;
		q.push(e[cnt]);
	}
	for(int i=1;i<=k;i++){
		tag[i]=0;
		scanf("%lld",&c[i][0]);
		for(int j=1;j<=n;j++) scanf("%lld",&c[i][j]);
	}
	kruskal();
	printf("%lld",ans);
	return 0;
}
