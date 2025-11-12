#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int totb,totbb,tot,node,cnt,anss,ans=0;
int v[11],val[11][10001],fa[10011];
bool vis[1000001];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct Bian{
	int u,v,w;
}b[1000001];
struct Bianb{
	int u,v,w;
}bb[1000001];
struct Edge{
	int u,v,w;
}e[1500001];
bool cmp(Bian o,Bian p){
	return o.w<p.w;
}
bool cmpp(Edge o,Edge p){
	return o.w<p.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		++totb;
		cin>>b[totb].u>>b[totb].v>>b[totb].w;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>val[i][j];
		}
	}
	sort(b+1,b+totb+1,cmp);
	for(int i=1;i<=totb;i++){
		int u=b[i].u;
		int v=b[i].v;
		if(find(u)!=find(v)){
			vis[i]=1;
			ans+=b[i].w;
			fa[find(u)]=find(v);
			node++;
			if(node==n-1){
				break;
			}
		}
	}
//	cout<<ans<<'\n';
	for(int i=1;i<=totb;i++){
		if(vis[i]){
			++totbb;
			bb[totbb].u=b[i].u;
			bb[totbb].v=b[i].v;
			bb[totbb].w=b[i].w;
		}
	}
//	cout<<totbb<<' '<<n<<'\n';
	for(int i=0;i<(1<<k);i++){
		cnt=0;
		anss=0;
		tot=0;
		node=n;
		for(int j=1;j<=totbb;j++){
			++tot;
			e[tot].u=bb[j].u;
			e[tot].v=bb[j].v;
			e[tot].w=bb[j].w;
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				node++;
				anss+=v[j];
				for(int z=1;z<=n;z++){
					++tot;
					e[tot].u=j+n;
					e[tot].v=z;
					e[tot].w=val[j][z];
				}
			}
		}
		for(int j=1;j<=n+k;j++) fa[j]=j;
		sort(e+1,e+tot+1,cmpp);
		for(int j=1;j<=tot;j++){
			int u=e[j].u;
			int v=e[j].v;
			if(find(u)!=find(v)){
				anss+=e[j].w;
//				cout<<"ans:"<<anss<<"u,v:"<<u<<' '<<v<<'\n';
				fa[find(u)]=find(v);
				cnt++;
				if(cnt==node-1){
					break;
				}
			}
		}
//		cout<<tot<<' '<<anss<<'\n';
		ans=min(ans,anss);
//		if(anss==504898585){
//			cout<<"dui: "<<i<<'\n';
//			for(int j=1;j<=k;j++){
//				if(i&(1<<(j-1))){
//					cout<<j<<' ';
//				}
//			}
//			cout<<'\n';
//		}
//		if(anss==500543299){
//			cout<<"cuo: "<<i<<'\n';
//			for(int j=1;j<=k;j++){
//				if(i&(1<<(j-1))){
//					cout<<j<<' ';
//				}
//			}
//			cout<<'\n';
//		}
	}
	cout<<ans;
	return 0;
} 