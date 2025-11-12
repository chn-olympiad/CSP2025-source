#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,c[15],a[15][10005],fa[100005];
struct Edge{
	int from,to,w;
}e[400005];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int mintree(Edge ei[200005],int l){
	int mst=0;
	sort(ei+1,ei+l+1,cmp);
	for(int i=1;i<=l;i++){
		fa[i]=i; 
	} 
	for(int i=1,j=1;i<=n-1;){
		if(fa[ei[j].from]!=fa[ei[j].to]){
			fa[ei[j].from]=fa[ei[j].to];
			mst+=ei[j].w;
			if(ei[j].from<=n && ei[j].to<=n)i++;
		}
		j++;
	}
	return mst;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].from>>e[i].to>>e[i].w;
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++m].from=n+i;
			e[m].to=j;
			e[m].w=a[i][j];
		}
	}
	cout<<mintree(e,n+k);
	return 0;
} 
