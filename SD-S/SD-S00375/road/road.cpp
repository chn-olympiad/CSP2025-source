//最小生成树
//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt=0;
const int N=1e6+100;
struct node{
	int u,v,w;
}p[N];
bool cmp(node l,node r){
	return l.w<r.w;
}
int f[N];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		p[++cnt]={u,v,w};
	}
	if(k<=0){
		for(int i=1;i<=n;i++) f[i]=i;
		sort(p+1,p+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++){
			int u=p[i].u,v=p[i].v,w=p[i].w;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				f[fu]=fv;
				ans+=w;
			}
		}
		printf("%lld",ans);
	} 
	else{
		for(int i=0;i<=n+20;i++) f[i]=i;
		for(int i=1;i<=k;i++) p[++cnt]={0,n+i,0};
		for(int i=1;i<=k;i++){
			int x; scanf("%lld",&x);
			for(int j=1;j<=n;j++){
				int y; scanf("%lld",&y);
				p[++cnt]={n+i,j,y};
			}
		}
		sort(p+1,p+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++){
			int u=p[i].u,v=p[i].v,w=p[i].w;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				f[fu]=fv;
				ans+=w;
			}
		}
		printf("%lld",ans);
	}
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 8 6
0 1 3 9 4
*/
