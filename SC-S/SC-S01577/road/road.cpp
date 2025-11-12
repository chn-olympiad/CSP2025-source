/*最小生成树
只处理k=0*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=20002,M=2000002,K=12;
int fa[N],xz[K][N],co[K];
struct edge{
	int u,v,w;
}s[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	//针对ci=0去做 
	int cnt=m;bool f=1;
	for(int i=1;i<=k;i++){
		cin>>co[i];if(co[i]!=0)f=0;
		for(int j=1;j<=n;j++){
			cin>>xz[i][j];
			++cnt;
			s[cnt].u=n+i;
			s[cnt].v=j;
			s[cnt].w=xz[i][j];
		}
	}
	if(f){
		for(int i=1;i<N;i++){
		fa[i]=i;}long long ans=0;sort(s+1,s+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int u=s[i].u,v=s[i].v,w=s[i].w;
			int fau=fd(u),fav=fd(v);
			if(fau!=fav){
				ans+=w;
				if(fau>fav)fa[fau]=fav;
				else fa[fav]=fau;
//				tot++;cout<<u<<" "<<v<<endl;
			}
		}return cout<<ans<<endl,0;
	}
	sort(s+1,s+cnt+1,cmp);
	
	//此时前m条边已经好了 跟以前一样建立边 但是要标注哪些能用 
	int r=0;long long res=1e18;
	while(r<(1<<k)){
			for(int i=1;i<N;i++){
		fa[i]=i;
	}
	int uf[15]={0};int tot=0;
		long long ans=0;
		for(int i=1;i<=k;i++){
			bool us=(r>>(i-1))&1;
			if(us){
				ans+=co[i];uf[i]=1;
			}
		}
		for(int i=1;i<=cnt;i++){
			int u=s[i].u,v=s[i].v,w=s[i].w;
			if(u>n){
				if(uf[u-n]==0)continue;
			}if(v>n){
				if(uf[v-n]==0)continue;
			}
			int fau=fd(u),fav=fd(v);
			if(fau!=fav){
				ans+=w;
				if(fau>fav)fa[fau]=fav;
				else fa[fav]=fau;
//				tot++;cout<<u<<" "<<v<<endl;
			}
		}
		res=min(res,ans);r++;
	}cout<<res<<endl;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4




2-4 1
2-4-5 4
2-3-4-5 8
13
*/