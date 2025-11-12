#include<bits/stdc++.h>
using namespace std;
#define int long long
#define bug cout<<"...here..."<<endl;
int n,m,k,vis[10005],ans,c[15],a[15][10005],fa[10005],cnt,tot;
struct node{
	int u,v,w;
}b[3000000];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
void add(int x,int y,int z){
	//cout<<x<<' '<<y<<' '<<z<<' '<<tot<<'\n';
	b[++cnt]={x,y,z};
}
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(tot==n-1) break;
		if(find(b[i].u)==find(b[i].v)) continue;
		tot++;
		ans+=b[i].w;
		merge(b[i].u,b[i].v);
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
