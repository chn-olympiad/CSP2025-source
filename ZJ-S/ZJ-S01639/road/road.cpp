#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],c[15],ac[15][10005],ans;
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
struct zdy{
	int x,y,w;
	bool operator<(const zdy &B)const{return w<B.w;}
}a[100005],b[100005];
struct edge{
	int t,w,nt;
}e[200005];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		a[i]=(zdy){u,v,w};b[i]=a[i];
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			ac[i][j]=read();
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			int x=a[i].x,y=a[i].y;
			int fx=getfa(x),fy=getfa(y);
			if(fx==fy) continue;
			fa[fx]=fy,ans+=a[i].w;
		}
		printf("%d\n",ans);
	}else{
		for(int i=1;i<=m;i++){
			int x=b[i].x,y=b[i].y,Min=b[i].w;
			for(int j=1;j<=k;j++)
				Min=min(Min,ac[j][b[i].x]+ac[j][b[i].y]);
			b[i].w=Min;
		}
		for(int i=1;i<=m;i++){
			int x=b[i].x,y=b[i].y;
			int fx=getfa(x),fy=getfa(y);
			if(fx==fy) continue;
			fa[fx]=fy,ans+=b[i].w;
		}
		printf("%d\n",ans);
	}
	return 0;
}
