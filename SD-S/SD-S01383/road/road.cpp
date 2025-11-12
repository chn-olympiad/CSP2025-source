#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,tot,head[11000],c[15],fa[11000],sz[11000],ans=0x3f3f3f3f3f3f3f3f,us[15];
struct node{
	int u,v,w,e;
}a[3001000];
struct nod{
	int u,v,w;
}p[1001000];
int cmp(nod x,nod y){
	if(x.u==y.u) return x.v<y.v;
	return x.u<y.u;
}
void add(int u,int v,int w,int e){
	a[++tot]=node{u,v,w,e};
}
int cmp2(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,g;
		scanf("%lld%lld%lld",&u,&v,&g);
		add(u,v,g,0);
	}
	int q=1;
	int flag=1;
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			int w;
			scanf("%lld",&w);
			if(w!=0) flag=0;
			add(n+i,j,w,i);
		}
		q*=2;
	}
	if(flag){
		cout<<"0";
		return 0;
	}
	sort(a+1,a+(m+n*k)+1,cmp2);
//	for(int i=1;i<=m+n*k;i++){
//		cout<<a[i].u<<" "<<a[i].v<<endl;
//	}
	for(int l=0;l<q;l++){
		int t=l,now=0,ansn=0;
		memset(us,0,sizeof us);
		while(t){
			now++;
			if(t&1){
				ansn+=c[now];
				us[now]=1;
			}
			t>>=1;
		}
//		for(int i=1;i<=5;i++){
//			cout<<us[i]<<" ";
//		}
//		cout<<endl;
		int use=0;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			sz[i]=1;
		} 
		int qwe=0;
		for(int i=1;i<=m+n*k;i++){
			//cout<<a[i].e<<endl;
//			cout<<find(a[i].u)<<' '<<find(a[i].v)<<endl;
			int u=find(a[i].u),v=find(a[i].v);
			if(u!=v&&(a[i].e==0||us[a[i].e]==1)){
				qwe++;
				use+=a[i].w;
				if(sz[u]<=sz[v]){
					fa[u]=v;
					sz[v]+=sz[u];
				}
				else{
					fa[v]=u;
					sz[u]+=sz[v];
				}
			}
		}
//		cout<<qwe<<endl;
//		cout<<ansn<<" "<<use<<endl;
		ans=min(ans,ansn+use);
	}
	printf("%lld",ans);
	return 0; 
}

