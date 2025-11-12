#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
const int maxm=1000005;
int n,m,k,fa[maxn];
int ans;
struct GYY{
	int u,v,w;
}e[maxm];
bool cmp(GYY x,GYY y){return x.w<y.w;}
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1,j=1;i<=m&&j<n;i++){
		int fx=getfa(e[i].u),fy=getfa(e[i].v);
		if(fx==fy)continue;
		fa[fy]=fx;j++;
		ans+=e[i].w;
	}
	printf("%d\n",ans);
	return 0;
}