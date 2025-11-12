#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int fa[N],c,o,cnt,ans,n,m,k,ww;
struct node{
	long long u,v,w;
}edge[N];
char cc;
int read(){
	cc=getchar();
	while(cc<'0'||cc>'9') cc=getchar();
	ww=0;
	while(cc>='0'&&cc<='9'){
		ww=(ww<<1)+(ww<<3)+cc-'0';
		cc=getchar();
	}
	return ww;
}
int find(long long x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node f1,node f2){
	return f1.w<f2.w;
}
void di(){
	for(int i=1;i<=cnt;i++){
		if(find(edge[i].u)==find(edge[i].v)) continue;
		else{
			long long fu=find(edge[i].u),fz=find(edge[i].v);
			fa[fu]=fz;
			ans+=edge[i].w;
		}
	}
}
void intt(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){edge[i].u=read();edge[i].v=read();edge[i].w=read();}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	intt();
	cnt=m;
	for(int i=1;i<=k;++i){
		c=read();
		for(int j=1;j<=n;++j){
			o=read();
			edge[++cnt].u=i+n;edge[cnt].v=j;
			edge[cnt].w=o;
		}
	}
	for(int i=1;i<=n+k;++i) fa[i]=i;
	sort(edge+1,edge+1+cnt,cmp);
	di();
	printf("%d",ans);
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

504898585

*/
