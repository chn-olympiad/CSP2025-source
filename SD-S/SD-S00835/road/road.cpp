#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[1020],cnt,c[1020],c1[15][10005],ans=1e18;
struct node{
	long long u,v,w;
}e[2000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
bool cmp2(node x,node y){
	return x.u<y.u;
}
long long find(long long x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
void kkk(string s1){
	long long sum=0,sum2=0;
	for(int i=1;i<=k;i++){
		if(s1[i-1]=='0') continue;
		sum2++;
		sum+=c[i+n];
		for(int j=1;j<=n;j++){
			e[++cnt].u=i+n;
			e[cnt].v=j;
			e[cnt].w=c1[i][j];
		}
	}
	sort(e+1,e+cnt+1,cmp);
	init();
	int x1=0;
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x==y) continue;
		x1++;
		fa[x]=y;
		sum+=e[i].w;
	}
	ans=min(ans,sum);
	sort(e+1,e+cnt+1,cmp2);
	for(int i=cnt;i>=1;i--){
		if(e[i].u<=n) continue;
		cnt--;
	}
	return;
}
void dfs(int i,string s12){
	if(i==k+1){
		kkk(s12);
		return;
	} 
	dfs(i+1,s12+'1');
	dfs(i+1,s12+'0');
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
		cnt++;
	}
	c[0]=3e9;
	bool f=0;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i+n]);
		if(c[i+n]!=0) f=1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&c1[i][j]);
		}
	}
	dfs(1,"");
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
T_T
QwQ
*/
