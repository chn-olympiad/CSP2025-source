#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
struct node{
	int x,y,w;
}e[1100005];
int n,m,k,a[12][N],c[12],fa[N],f,ans;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];if(c[i]!=0) f=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	if(f==0){
		for(int i=1;i<=k*n;i++){
			e[m+i].x=(i-1)/k+1;e[m+i].y=n+(i-1)%k+1;
			e[m+i].w=a[(i-1)%k+1][(i-1)/k+1];
		}
		sort(e+1,e+m+n*k+1,[](node x,node y){return x.w<y.w;});
		for(int i=1;i<=m+n*k;i++){
			int x=e[i].x,y=e[i].y;
			if(find(x)!=find(y)){
				fa[find(x)]=find(y);
				ans+=e[i].w;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(e+1,e+m+1,[](node x,node y){return x.w<y.w;});
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y;
		if(find(x)!=find(y)){
			fa[find(x)]=find(y);
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}

