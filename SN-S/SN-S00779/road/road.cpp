#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int MAXN=3e6+5;
struct Node {
	int u,v,w;
};
int ans=0;
Node p[MAXN];
Node t[MAXN];
int c[20],a[20][MAXN];
int f[MAXN];
void init(void) {
	for(int i=0;i<=n;i++) f[i]=i;
}
int mfind(int x) {
	if(f[x]==x) return x;
	return f[x]=mfind(f[x]);
}
void mergex(int x,int y) {
	int fx=mfind(x),fy=mfind(y);
	f[fx]=fy;
}
bool cmp(Node x,Node y) {
	return x.w<y.w;
}
int main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int num=n,h=n+1;
	init();
	for(int i=1;i<=m;i++) {
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++) {
		for(int u=1;u<=n;u++) {
			for(int v=1;v<=n;v++) {
				if(v==u) continue;
				if(a[i][u]+a[i][v]==0) {
					mergex(u,v);
					num--;
				}else{
					p[h]={u,v,a[i][u]+a[i][v]};
					h++;
				}
			}
		}
	}
	
	for(int i=1;i<=h-1;i++) {
		if(mfind(p[i].u)!=mfind(p[i].v)) {
			mergex(p[i].u,p[i].v);
			ans+=p[i].w;
			num--;
		}
		if(num==0) break;
	}
	cout<<ans;
	return 0;
}
