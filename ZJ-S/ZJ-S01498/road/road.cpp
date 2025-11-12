#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL read() {
	LL x=0;
	char ch=getchar();
	bool flag=true;
	for(;ch<'0'||ch>'9';ch=getchar()) (ch=='-')&&(flag=false);
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return flag? x:-x;
}
int n,m,k;
//int head[10015],nxt[2000005],to[2000005],cnt_edge;
struct edge{
	int u,v;
	LL w;
	edge(){}
	edge(int a,int b,LL c):u(a),v(b),w(c){}
}a[1010005],b[1010005];
int fa[10015];
LL v_c[15],tvc[11][100005];
LL val[2000005];
LL ans,tot;
//void merge(int u,int v,int w) {
//	int k=++cnt_edge;
//	nxt[k]=head[u];
//	to[k]=v;
//	val[k]=w;
//}
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
int find(int x) {
	for(;fa[x]!=x;) {
		fa[x]=fa[fa[x]];
		x=fa[x];
	}
	return x;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	tot=1e17;
	for(int i=1;i<=m;i++) {
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	for(int i=1;i<=k;i++) {
		v_c[i]=read();
		for(int j=1;j<=n;j++) {
			tvc[i][j]=read();
		}
	}
	for(int i=0;i<(1<<k);i++) {
		ans=0;
		for(int i=1;i<=m;i++) b[i]=a[i];
		int top=m,nn=n;
		for(int j=1;j<=k;j++) {
			if((i&(1<<(j-1)))<1) continue;
			nn++;
			ans+=v_c[j];
			for(int l=1;l<=n;l++) {
				b[++top]=edge(nn,l,tvc[j][l]);
			}
		}
//		cout<<ans<<'\n';
		for(int j=1;j<=n+k;j++) fa[j]=j;
		sort(b+1,b+top+1,cmp);
		int now=1;
//		for(int i=1;i<=top;i++) {
//			cout<<b[i].w<<'\n';
//		}
//		cout<<nn<<'\n';
		for(int j=1;j<nn;j++) {
			for(;now<=top&&find(b[now].u)==find(b[now].v);now++);
//			cout<<now<<'\n';
			fa[find(b[now].u)]=find(b[now].v);
//			cout<<b[now].w<<','<<ans<<"\n";
			ans+=b[now].w;
//			cout<<b[now].w<<','<<ans<<"\n\n";
		}
//		cout<<i<<':'<<ans<<'\n';
		tot=min(tot,ans);
	}
	cout<<tot<<'\n';
	return 0;
}