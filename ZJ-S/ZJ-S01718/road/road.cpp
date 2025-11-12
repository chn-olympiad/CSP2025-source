#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
struct node{
	int u,v,w;
}e[N];
struct city{
	int c;
	vector <int> w;
}g[15];
int n,m,k;
int fa[N];
inline int read(){
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
inline int cmp(node x,node y){
	return x.w>y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool A=1;
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int i=1;i<=k;i++){
		g[i].c=read();
		for(int i=1;i<=n;i++){
			int x=read();
			g[i].w.push_back(x);
			if(x!=0) A=0;
		}
	}
	if(A){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+1+m,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=e[i].w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
