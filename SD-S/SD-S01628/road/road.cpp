#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
const long long M=2e6+5;
const long long N=1e4+5;
long long n,m,k,c[15],a[15][N],cnt[15],lol[15],flag[15][N],nimas[15];
long long head[N],nt[2*M],tot,fa[N],ans,qqq=1,opopop,lmao,minn=0x3f3f3f3f3f3f;
struct node{
	long long u,v,w;
}ver[2*M];
void add(long long u,long long v,long long w){
	ver[++tot].u=u;
	ver[tot].v=v;
	ver[tot].w=w;
	return ;
}
long long find(long long x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void dfs(){
	for(long long i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(ver+1,ver+1+tot,cmp);
	for(long long i=1;i<=tot;i++){
		long long u=min(ver[i].u,ver[i].v);
		long long v=max(ver[i].u,ver[i].v);
		if(find(fa[u])==find(fa[v])){
			continue;
		}else{
			fa[find(fa[v])]=find(fa[u]);
			qqq++;
			if(v>n){
				cnt[v-n]++;
				lol[v-n]+=ver[i].w;
				flag[v-n][u]=1;
			}
			ans+=ver[i].w;
		}
		if(qqq==n+m){
			return ;
		}
	} 
}
void dfss(){
	for(long long i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(ver+1,ver+1+tot,cmp);
	for(long long i=1;i<=tot;i++){
		long long u=min(ver[i].u,ver[i].v);
		long long v=max(ver[i].u,ver[i].v);
		if(v>n&&!nimas[v-n]){
			continue;
		}
		
		if(find(fa[u])==find(fa[v])){
			continue;
		}else{
			fa[find(fa[v])]=find(fa[u]);
			qqq++;
			if(v>n){
				cnt[v-n]++;
				lol[v-n]+=ver[i].w;
				flag[v-n][u]=1;
			}
			ans+=ver[i].w;
		}
		if(qqq==n+lmao){
			return ;
		}
	} 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	opopop=1;
	for(long long i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0){
			opopop=0;
		}
		for(long long j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			add(i+n,j,a[i][j]);
		}
	}
	if(opopop){
		dfs();
		for(long long i=1;i<=k;i++){
			if(cnt[i]==0||cnt[i]==1){
				ans-=c[i];
				ans-=lol[i];
			}
		}
		printf("%d",ans);
	}
	else{
		for(long long i=0;i<=(long long)(pow(2,k)-1);i++){
			ans=0;
			lmao=0;
			for(long long j=1;j<=k;j++){
				nimas[j]=i/(long long)(pow(2,j-1))%2;
				if(nimas[j]){
					lmao++;
					ans+=c[j];
				}
			}
			qqq=1;
			dfss();
			for(long long j=1;j<=k;j++){
				if(nimas[j]&&(cnt[j]==0||cnt[j]==1)){
					ans-=c[j];
					ans-=lol[j];
				}
			}
			minn=min(minn,ans);
		}
		printf("%d",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
