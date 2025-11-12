#include<bits/stdc++.h>
using namespace std;
struct node{
	long long w;
	int u,v,flag; 
}q[2000001],c[2000001];
bool cmp(node x,node y){
	return x.w<y.w;
}
int tot=0,fa[1000001],sz[1000001];
long long d[1000001];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
int n,m,k;
long long ans=1e18,res=0;
void kruskal(){
	res=0;
	for(int i=1;i<=m;i++){
		int x=q[i].u,y=q[i].v;
//		printf("%d %d %d\n",tot,find(x),find(y)); 
		if(find(x)!=find(y)){
			x=find(x);
			y=find(y);
			if(sz[x]>sz[y])swap(x,y);
			fa[x]=y;
			sz[y]+=sz[x];
			res+=q[i].w;
			c[++tot]=q[i];
		}
	}
	ans=min(ans,res);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&q[i].u,&q[i].v,&q[i].w);
		q[i].flag=0;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)sz[i]=1;
	sort(q+1,q+1+m,cmp);
	kruskal();
	for(int i=1;i<=k;i++){
		scanf("%lld",&d[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[++tot].w);
			c[tot].u=i+n;
			c[tot].v=j;
			c[tot].flag=i;
		}
	}
	sort(c+1,c+1+tot,cmp);
	int cnt=(1<<k)-1;
	for(int i=0;i<=cnt;i++){
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=n+k;j++)sz[j]=1;
		res=0;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				res+=d[j];
			}
		}
		for(int j=1;j<=tot;j++){
			if(c[j].flag==0||((1<<(c[j].flag-1))&i)){
				int x=c[j].u,y=c[j].v;
				if(find(x)!=find(y)){
					x=find(x);
					y=find(y);
					if(sz[x]>sz[y])swap(x,y);
					fa[x]=y;
					sz[y]+=sz[x];
					res+=c[j].w;
				}
			}
		} 
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
T2:road

严格强于最小生成树吧。 

很快会了 2^k*(m+n*k)log(m+n*k)做法，过不大去啊 

五分钟后会了不带 log 的做法，优化到了 1e9 级别，不是这真的能过吗？ 

想到了一个神秘剪枝，能减掉一部分

不是，好像没有更优的做法，相信CCF少爷机。 

哦，不需要，只留原图最小生成树上的边，直接变成 2^k * n*k，这个 1e8级别，包过的。 

读错题了，但是没有区别，感觉爽翻了。 

认为自己假了，又花了一些时间证明了一下正确性。
 
不是，怎么一上考场码力=原码力/2啊，我在写分块时都没这么逆天 

不是，怎么时间和正确性都炸了，我漏了什么？

哦，算小了，那其实还好 

把时间改对了，可我的正确性呢？ 

好好好，经典清空不完全等于完全不清空。 
*/