#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#define int long long
const int MAXM=1e7+5,MAXN=5e4;
using namespace std;
int n,m,k,c[MAXN],tot=0,ans=0,cnt=0,rd=0,rans=0,num=0;
int f[MAXN],s[MAXN];
int vis[MAXN];
struct edge {
	int u,v,w;
} e[MAXM],a[20][MAXN];
int cmp(edge a,edge b) {
	return a.w<b.w;
}
int fa(int x) {
	if(x==f[x])return f[x];
	return f[x]=fa(f[x]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%lld%lld%lld",&a[0][i].u,&a[0][i].v,&a[0][i].w);
	}
	for(int i=1; i<=n; i++)f[i]=i,s[i]=1;
	sort(a[0]+1,a[0]+m+1,cmp);
	for(int i=1; i<=m; i++) {
		int fx=fa(a[0][i].u),fy=fa(a[0][i].v);
		if(fx!=fy) {
			f[fx]=fy;
			rans+=a[0][i].w;
			s[fy]+=s[fx];
			if(s[fy]==n){
				rd=i;
				break;
			}
		}
	}
	for(int i=n+1; i<=n+k; i++) {
		scanf("%lld",&c[i-n]);
		for(int j=1; j<=n; j++) {
			scanf("%lld",&a[i-n][j].w);
			a[i-n][j].u=i,a[i-n][j].v=j,a[i-n][j].w;
		}
	}
	while(1) {
		//cout<<rans<<endl;
		int minn=1e18,q=0;
		for(int i=n+1; i<=n+k; i++) {
			if(vis[i-n]==1)continue;
			ans=cnt=tot=0;
			ans+=c[i-n];
			//if(vis[k])continue;
			for(int j=1; j<=rd; j++) {
				e[++tot].u=a[0][j].u,e[tot].v=a[0][j].v,e[tot].w=a[0][j].w;
			}
			for(int j=1; j<=n; j++) {
				e[++tot].u=a[i-n][j].u,e[tot].v=a[i-n][j].v,e[tot].w=a[i-n][j].w;
			}
			sort(e+1,e+tot+1,cmp);
			for(int j=1; j<=n+k; j++){
				f[j]=j;
				if(j<=n)s[j]=1;
				else s[j]=0; 
			}
			for(int j=1; j<=tot; j++) {
				int fx=fa(e[j].u),fy=fa(e[j].v);
				if(fx!=fy) {
					f[fx]=fy;
					ans+=e[j].w;
					s[fy]+=s[fx];
				}
				if(s[fy]==n)break;
			}
			if(ans<rans){
				if(ans<minn){
					minn=ans,q=i-n;
				}
			}
		//	cout<<ans<<endl;
		}
		if(q==0)break;
		rans=minn;
		vis[q]=1;
		for(int i=rd+1;i<=rd+n;i++){
			a[0][i].u=a[q][i-rd].u;
			a[0][i].v=a[q][i-rd].v;
			a[0][i].w=a[q][i-rd].w;
		}
		rd=rd+n;
	}
	cout<<rans<<endl;
	return 0;
}
