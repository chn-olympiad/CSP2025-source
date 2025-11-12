#include <iostream> //O(2^K*Nlog(NK))
#include <cstdio> //样例2跑了快500ms,死定了
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN=1e4+15,MAXM=1e6+10;

int N,M,K,u,v;
bool taskA=true;
ll w,A[15];
struct edge{
	int from,to;
	ll value;
	bool operator <(const edge a)const{
		return value<a.value;
	}
	bool operator >(const edge a)const{
		return value>a.value;
	}
}E[MAXM],e[MAXN],res[15][MAXN],c;

ll ans;
int fa[MAXN],tot;
int find_fa(int x){
	if(fa[x]==x) return x;
	return fa[x]=find_fa(fa[x]);
}
void Prim(){ //选出最短的N-1条路
	for(int i=1;i<=N;++i) fa[i]=i;
	sort(E+1,E+M+1);
	for(int i=1;i<=M;++i){
		int x=E[i].from,y=E[i].to;
		x=find_fa(x);y=find_fa(y);
		if(x==y) continue;
		fa[x]=y;ans+=E[i].value;
		e[++tot]=E[i];
	}
}

ll find_ans(int state){
	for(int i=1;i<=N+K;++i) fa[i]=i;
	ll sum=0;int hh=N,idn=1; //hh记录点的数量
	priority_queue<edge,vector<edge>,greater<edge> > t;
	for(int i=0;i<K;++i)
		if((state>>i)&1){
			sum+=A[i+1];++hh;
			if(sum>=ans) return sum;
			for(int j=1;j<=N;++j) t.push(res[i+1][j]);
		}
	for(int i=1;i<N;++i) t.push(e[i]);
	while(idn<hh){
		c=t.top();t.pop();
		int x=c.from,y=c.to;
		x=find_fa(x);y=find_fa(y);
		if(x==y) continue;
		fa[x]=y;++idn;sum+=c.value;
		if(sum>=ans) return sum;
	}
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=M;++i)
		scanf("%d%d%lld",&E[i].from,&E[i].to,&E[i].value);
	Prim(); //先跑一个原图的最小生成树(不加乡村)
	if(K==0){printf("%lld\n",ans);return 0;}
	for(int i=1;i<=K;++i){
		scanf("%lld",&A[i]);
		for(int j=1;j<=N;++j){
			scanf("%lld",&w);
			res[i][j]={i+N,j,w};
		}
	}
	for(int i=1;i<(1<<K);++i){ //哪些不选哪些选
		ans=min(ans,find_ans(i));
	}
	printf("%lld",ans);
	return 0;
}