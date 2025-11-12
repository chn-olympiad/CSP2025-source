#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int n,m,k;
struct mine {
	int u,v,w;
	bool operator <(const mine b)const {
		return w<b.w;
	}
} a[50000005];
int fa[10005],tmp[10005];
int getfa(int x) {
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1; i<=m; i++)a[i].u=read(),a[i].v=read(),a[i].w=read();
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n; j++) tmp[i]=read();
		for(int j=1; j<n; j++) {
			for(int ii=j+1; ii<=n; ii++) {
				a[++m].u=j,a[m].v=ii,a[m].w=tmp[j]+tmp[ii];
				a[++m].u=ii,a[m].v=j,a[m].w=tmp[j]+tmp[ii];
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) fa[i]=i;
	int ans=0,cnt=0;
	for(int i=1; i<=m; i++) {
		int fx=getfa(a[i].u),fy=getfa(a[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		cnt++;
		ans+=a[i].w;
		if(cnt==n-1) break;
	}
	printf("%d",ans);
	return 0;
}
