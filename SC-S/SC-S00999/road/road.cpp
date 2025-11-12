#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=1e18;
int c[15],a[15][10005],h[20005];
struct edge{
	int u,v;
	int w;
}E[2000005],T[2000005];
bool operator<(edge a,edge b){
	return a.w<b.w;
}int fa[20005];
int find(int a){
	if(a==fa[a])return a;
	return fa[a]=find(fa[a]);
}
long long kruskal(int len){
	for(int i=1;i<=len;++i)T[i]=E[i];
	for(int i=1;i<=n+k;++i)fa[i]=i,h[i]=1;
	sort(T+1,T+len+1);
	long long ret=0;
	for(int i=1;i<=len;++i){
		int ru=find(T[i].u),rv=find(T[i].v);
		if(ru!=rv){
			if(h[ru]>h[rv])swap(ru,rv);
			if(h[ru]==h[rv])++h[rv];
			fa[ru]=rv;
			ret+=T[i].w;
		}
	}return ret;
}void dfs(int step,long long sum){
	if(sum>=ans)return;
	if(step>k){
		ans=min(ans,kruskal(m)+sum);
	}else{
		dfs(step+1,sum);
		int tm=m;
		for(int i=1;i<=n;++i){
			E[++m]={n+step,i,a[step][i]};
		}dfs(step+1,sum+c[step]);
		m=tm;
	}
}inline void read(int &a){
	a=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(E[i].u),read(E[i].v),read(E[i].w);
	}int maxn=0;
	for(int i=1;i<=k;++i){
		read(c[i]);
		maxn=max(maxn,c[i]);
		int minx=1e9;
		for(int j=1;j<=n;++j){
			read(a[i][j]);
			minx=min(minx,a[i][j]);
		}maxn=max(maxn,minx);
	}if(maxn==0){
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				E[++m]={n+i,j,a[i][j]};
			}
		}printf("%lld",kruskal(m));
	}else{
		dfs(1,0);
		printf("%lld",ans);
	}
	
	return 0;
}