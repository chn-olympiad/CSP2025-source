#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
struct node{
	int u,v;
	long long w;
}e[M+N*10];
bool used[15];
long long t[15],ans=LONG_LONG_MAX;
bool cmp(node lhs,node rhs){
	return lhs.w<rhs.w;
}
int fa[N+15],h[N+15];
int find(const int a){
	if(a==fa[a])return a;
	fa[a]=find(fa[a]);
	return fa[a];
}
void mnt(long long cus){
	long long res=cus;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m+k*n;i++){
		if(e[i].u>n&&!used[e[i].u-n])continue;
		int p=find(e[i].u),q=find(e[i].v);
		if(p==q)continue;
		if(h[p]<h[q])swap(p,q);
		fa[q]=p;
		h[p]+=(h[p]==h[q]);
		res+=e[i].w;
		if(res>=ans)break;
	}
	ans=min(ans,res);
}
void dfs(int d,long long cus){
	if(d==k){
		mnt(cus);
		return;
	}
	dfs(d+1,cus);
	used[d+1]=1;
	dfs(d+1,cus+t[d+1]);
	used[d+1]=0;
	return;
}
template<class T> inline void read(T &X){
	X=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		X=X*10+ch-'0';
		ch=getchar();
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	for(int i=1;i<=k;i++){
		read(t[i]);
		for(int j=1;j<=n;j++){
			int num=(i-1)*n+j+m;
			read(e[num].w);
			e[num].u=n+i;
			e[num].v=j;
		}
	}
	sort(e+1,e+m+k*n+1,cmp);
	dfs(0,0);
	printf("%lld\n",ans);
	return 0;
}
