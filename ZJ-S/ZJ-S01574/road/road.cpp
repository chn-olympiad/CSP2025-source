#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int u,v,w;
}x[2000010];
bool cmp(node e,node f){
	return e.w<f.w;
}
int n,m,k,c[15],a[15][10010];
int root[10010],l;
int findx(int rt){
	if(root[rt]==rt)return rt;
	return findx(root[rt]);
}
void join(int rtx,int rty){
	root[rtx]=findx(rty);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].w;
	}
	int p=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			x[++p].u=i,x[p].v=j,x[p].w=a[i][j];
		}
	}
	int cost=0;
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
	sort(x+1,x+p+1,cmp);
	for(int i=1;l<n-1;i++){
		if(findx(x[i].u)!=findx(x[i].v)){
			join(x[i].u,x[i].v);
			l++,cost+=x[i].w;
		}
	}
	cout<<cost;
	return 0;
}
