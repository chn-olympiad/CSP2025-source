#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=3e6+5,K=12;
int n,m,k,u,v,w,num;
ll ans;
//int st[M],to[M],val[M],nxt[M],h[N],cnt;
int h[N],cnt;
int c[K],a[K][N];//dis[N][N];
int fa[N];
struct eage{
	int st,to,val;
	int nxt;
}s[M];
void add(int a,int b,int c){
	s[++cnt].st=a;
	s[cnt].to=b;
	s[cnt].val=c;
//	s[cnt].nxt=h[a];
//	h[a]=cnt;
}
int cmp(eage a,eage b){
	return a.val<b.val;
}
int find(int a){
	if(fa[a]!=a) return fa[a]=find(fa[a]);
	return a;
}
int main(){//kruscal°å×Ó Ô¤¹À48·Ö:)  16£º20 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
//		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			add(i+n,j,a[i][j]);
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(s+1,s+cnt+1,cmp);
	for(int j=1;j<=cnt;j++){
		int r1=find(s[j].st),r2=find(s[j].to);
		if(r1==r2) continue;
		fa[r1]=r2;
		ans+=s[j].val;
		num++;
		if(num==n+k-1) break;
	}
	printf("%lld\n",ans);
	return 0;
}
