#include<bits/stdc++.h>
using namespace std;
char *P1,*P2,buf[100010];
#define gc() (P1==P2&&(P2=(P1=buf)+fread(buf,1,100000,stdin),P1==P2)?EOF:*P1++)
int read(){
	char ch=gc();
	int x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch-48),ch=gc();
	return x*f;
}
int n,m,k;
struct edge{
	int x,y,z;
}e[2000010],now[100010],e1[2000010];
int fa[20010],siz[20010],a[20][10010];
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	if(x!=y){
		if(siz[x]>siz[y]) fa[y]=x,siz[x]+=siz[y];
		else fa[x]=y,siz[y]+=siz[x];
	}
}
int cmp(edge E1,edge E2){
	return E1.z<E2.z;
}
long long ans;
int c[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].z=read();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int fx=getfa(e[i].x),fy=getfa(e[i].y);
		if(fx!=fy){
			ans+=e[i].z;
			merge(fx,fy);
		}
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	for(int i=1;i<(1<<k);i++){
		int cnt=0;
		long long Now=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				Now+=c[j];
				for(int K=1;K<=n;K++) now[++cnt]={j+n,K,a[j][K]};
			}
		}
		sort(now+1,now+cnt+1,cmp);
		int p1=1,p2=1;
		while(p1<=m&&p2<=cnt){
			if(p1<=m&&e[p1].z<=now[p2].z) e1[p1+p2-1]=e[p1],p1++;
			else e1[p1+p2-1]=now[p2],p2++;
		}
		for(int j=1;j<=n+k;j++) fa[j]=j,siz[j]=1;
		for(int j=1;j<=cnt+m;j++){
			int fx=getfa(e1[j].x),fy=getfa(e1[j].y);
			if(fx!=fy){
				Now+=e1[j].z;
				merge(fx,fy);
			}
			if(Now>=ans) break;
		}
		ans=min(ans,Now);
	}
	cout<<ans;
}
