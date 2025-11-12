#include<bits/stdc++.h>
using namespace std;
const int mxn=1e4+5,mxm=2e6+15;
struct T{
	long long u,v,w;
}g[mxm];
long long n,m,k,cnt,p[15],t[15];
long long ans;
bool cmp(T i,T j){
	return i.w<j.w;
}
int fa[mxn];
int f(int x){
	return (fa[x]==x?x:fa[x]=f(fa[x]));
}
bool mg(int x,int y){
	int fx=f(x),fy=f(y);
	if (fx==fy) return false;
	fa[fx]=fy;
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+5;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[++cnt].u=x;
		g[cnt].v=y;
		g[cnt].w=z;
	}
	for(int i=1;i<=k;i++){
		cin>>t[i];
		for(int j=1;j<=n;j++){
			int c;
			cin>>c;
			g[++cnt].u=n+i;
			g[cnt].v=j;
			g[cnt].w=c+t[i];
		}
	}
	int a[15]={};
	sort(g+1,g+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		
		if (mg(u,v)==true){
			ans+=w;
			if (u>n){
				p[u-n]++;
				a[u-n]=w;
			}
		}
	}
	for(int i=1;i<=k;i++){
		if (p[i]>1) ans-=(long long)t[i]*(p[i]-1);
		else if (p[i]==1) ans-=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
