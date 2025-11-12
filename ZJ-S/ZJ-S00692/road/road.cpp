#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y,val;
}to[1000005];
int c[15][100005];
int n,m,k;
int ans;
int tot;
int fa[100005];
int find(int a){
	if(fa[a]==a)return a;
	else return fa[a]=find(fa[a]);
}
void kruskal(){
	for(int i=1;i<=m;i++){
		int a=find(to[i].x);
		int b=find(to[i].y);
		if(a==b)continue;
		fa[a]=b;
		++tot;
		ans+=to[i].val;
		if(tot==n-1)break;
	}
}
bool cmp(node a,node b){
	return a.val<b.val;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>to[i].x>>to[i].y>>to[i].val;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	sort(to+1,to+1+m,cmp);
	kruskal();
	cout<<ans;
	return 0;
}
