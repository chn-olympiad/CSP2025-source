#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005,K=15,M=1000005;
struct Edge{
	int u,v,w;
}p[M+K*N];
int n,m,k,ans=1e9;
int c[K],a[N][K];
int fa[N+K];
int read(){
	int p=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return p*k;
}
void init(int r){
	for(int i=1;i<=r;i++){
		fa[i]=i;
	}
	return;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
	return;
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int kruskal(int t,int r){
	init(r);
	sort(p+1,p+t+1,cmp);
	int cnt=0,sum=0;
	for(int i=1;i<=t;i++){
		Edge now=p[i];
		if(find(now.u)!=find(now.v)){
			merge(now.u,now.v);
			cnt++;
			sum+=now.w;
		}
		if(cnt==r-1) break;
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		p[i].u=read();p[i].v=read();p[i].w=read();
	}
	bool flag1=true;
	for(int i=1;i<=k;i++){
		bool flag2=false;
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[j][i]=read();
			if(a[j][i]==0) flag2=true;
		}
		if(flag2==false||c[i]!=0) flag1=false;
	}
	if(flag1){
		int t=m,r=n;
		for(int j=1;j<=k;j++){
			++r;
			for(int l=1;l<=n;l++){
				p[++t].u=r;
				p[t].v=l;
				p[t].w=a[l][j];
			}
		}
		ans=kruskal(t,r);
		printf("%lld",ans);
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		int t=m,r=n,res=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				res+=c[j+1];
				++r;
				for(int l=1;l<=n;l++){
					p[++t].u=r;
					p[t].v=l;
					p[t].w=a[l][j+1];
				}
			}
		}
		res+=kruskal(t,r);
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}