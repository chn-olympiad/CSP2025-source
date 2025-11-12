#include<bits/stdc++.h>
#define int long long
using namespace	std;
const int M=5e6+15,N=1e4+5;
int n,m,k,fa[N],c[N],p[N][11],top,ans=1e18,w[N];
bool flagA=1;
struct edge{
	int u,v,w,f;
}a[M];
struct Edge{
	int u,v,w,f;
}b[M];
bool cmp(edge q,edge p){
	return q.w<p.w;
}
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	int xf=getfa(x);
	int yf=getfa(y);
	fa[xf]=yf;
}
int code1_4(){
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(getfa(u)!=getfa(v)){
			merge(u,v);
			ans+=w;
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	top=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])flagA=0;
		for(int j=1;j<=n;j++){
			cin>>w[j];
			if(w[i])flagA=0;
		}
	}
	cout<<code1_4();
	return 0;
}