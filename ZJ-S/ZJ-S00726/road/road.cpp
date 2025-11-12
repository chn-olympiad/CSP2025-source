#include<stdio.h>
#include<algorithm>
#define rep(i,s,e) for(int i=(s);i<=(e);++i)
#define _rep(i,s,e) for(int i=(s);i<(e);++i)
#define rev(i,s,e) for(int i=(s);i>=(e);--i)

const int M=1e6+10,N=1e4+10;

struct edge{
	int from,to,val;
}e[M*3];
bool cmp(const edge& x,const edge& y) {
	return x.val<y.val;
}

int fa[M*3];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(x);
}
long long res;
int n,m,k,a[20][N],c[N];
bool Kruskal(){
	int cnt=0;
	for(int i=1;i<=2*m;++i) {
		edge x=e[i];
		int f1=find(x.from),f2=find(x.to);
		if(f1!=f2){
			fa[f2]=f1;
			res+=x.val;
			cnt++;
		}
		if(cnt==n-1) return true;
	}
	return false;
}


int main() {
	int u,v,w,flag=1;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m) {
		scanf("%d%d%d",&u,&v,&w);
		e[m*2]={u,v,w},e[m*2-1]={v,u,w};
	}
	rep(i,1,k) {
		scanf("%d",&c[i]);
		if(c[i]) flag=0;
		rep(j,1,n) {
			scanf("%d",&a[i][j]);
			if(a[i][j]) flag=0;
		}
	}
	if(flag==1) return printf("0"),0;//special A
	rep(i,1,m<<1) fa[i]=i;
	std::sort(e+1,e+1+2*m,cmp);
	Kruskal();
	printf("%lld",res);
	return 0;
}
