#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define int long long
using namespace std;
const int N=1e4+100,M=1e6+100,K=15;
struct edge{
	int u,v,w,id;
}e[M],tmp[M],a[K][N];
int fa[N+K],n,m,k,tot,tag[M],ans,val[K];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return;
	fa[fx]=fy; 
}

int cmp1(edge x,edge y){
	return x.w<y.w;
}

int kruscal(){
	int res=0;
	sort(e+1,e+1+tot,cmp1);
//	for(int i=1;i<=tot;i++){
//		cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
//	}
	for(int i=1;i<=tot;i++){
		int u=e[i].u;
		int v=e[i].v;
		int fu=find(u);
		int fv=find(v);
		if(fu==fv) continue;
		fa[fu]=fv;
		res+=e[i].w;
		if(res>=ans) return res;
	}
	return res;
}

void print(int x){
	bitset <8> bit;
	int tot=0;
	while(x){
		bit[tot++]=(x%2);
		x/=2;
	}
	cout<<bit<<'\n';
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]=edge{u,v,w,i};
	}
	sort(e+1,e+1+m,cmp1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v;
		int fu=find(u);
		int fv=find(v);
		if(fu==fv) continue;
		merge(u,v);
		ans+=e[i].w;
		tag[e[i].id]=1;
	}
	int rt=find(1);
	for(int i=1;i<=m;i++) if(tag[e[i].id]) tmp[++tot]=e[i];
	m=tot;
	for(int i=1;i<=m;i++) e[i]=tmp[i];
	//for(int i=1;i<=m;i++) cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
	
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			int u=i+n;
			int v=j;
			int w;
			cin>>w;
			a[i][j]=edge{u,v,w,0};
		}
	}
	//cout<<ans<<'\n';
	//for(int i=1;i<=k;i++) cout<<val[i]<<' ';
	//cout<<'\n';
	for(int s=1;s<(1<<k);s++){
		int cur=s;
		tot=m;
		int sum_v=0;
		for(int i=1;i<=m;i++) e[i]=tmp[i];
		while(cur){
			int p=lowbit(cur);
			int id=log2(p)+1;
			sum_v+=val[id];
			for(int i=1;i<=n;i++){
				e[++tot]=a[id][i];
			}
			cur-=p;
		}
		if(sum_v>=ans) continue;
		//print(s);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		ans=min(ans,kruscal()+sum_v);
	}
	cout<<ans;
	return 0;
}
