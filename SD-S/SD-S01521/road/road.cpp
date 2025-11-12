#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<typename type>
void read(type &x){
	x=0;
	bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){
		ch=='-'?flag=1:0;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	flag?x=-x:0;
}
const int N=1e4+5;
const int M=2e6+5;
int n,m,k;
struct node{
	int u,v,w;
}e[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void init(){
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
}
int cnt;
ll ans;
int c[15];
int a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;++i){
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	for(int i=1;i<=k;++i){
		read(c[i]);
		for(int j=1;j<=n;++j){
			read(a[i][j]);
		}
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]==0){
				for(int jj=1;jj<=n;++jj){
					if(j!=jj){
						++m;
						e[m].u=j;
						e[m].v=jj;
						e[m].w=a[i][jj];
					}
				}
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	init();
	for(int i=1;i<=m&&cnt<n-1;++i){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y){
			continue;
		}
		ans+=e[i].w;
		fa[x]=y;
		++cnt;
	}
	printf("%lld\n",ans);
	return 0;
}
