#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,m,k,sum = 0;
struct node{
	int w,u,v;
}y[N];
int fa[10005];
int l[N][15];
int find(int x){
	if(x != fa[x]) return find(fa[x]);
	return x;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i] = i;
	}
	for(int i=1;i<=m;i++){
		cin>>y[i].u>>y[i].v>>y[i].w;
	}
	int g = N+1;
	for(int i=1;i<=k;i++){
		cin>>l[0][i];
		for(int j=1;j<=n;j++){
			cin>>l[j][i];
		}
	}
	sort(y+1,y+1+n,cmp);
	for(int i=1;i<=n;i++){
		int ra = find(y[i].u),rb = find(y[i].v);
		if(ra != rb){
			fa[rb] = ra;
			sum += y[i].w;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
